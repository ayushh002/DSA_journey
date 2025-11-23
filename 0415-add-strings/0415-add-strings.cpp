class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.length(), s2 = num2.length();
        int max = s1 > s2 ? s1 : s2;

        string ans = "";
        int carry = 0;
        while(max--){
            int digit1 = 0, digit2 = 0;
            if(s1)
                digit1 = (num1[--s1] - '0');
            if(s2)
                digit2 = (num2[--s2] - '0');

            int sum = digit1+digit2+carry;
            carry = sum/10;
            sum %= 10;
            ans += (sum + '0');
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};