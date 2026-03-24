class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();

        int carry = 0;
        string ans = "";
        while(n1 || n2){
            int digit1 = 0, digit2 = 0;
            if(n1)
                digit1 = num1[--n1] - '0';
            if(n2)
                digit2 = num2[--n2] - '0';
            
            int sum = carry + digit1 + digit2;
            carry = sum / 10;
            sum %= 10;
            ans += (sum + '0');
        }

        if(carry)
            ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};