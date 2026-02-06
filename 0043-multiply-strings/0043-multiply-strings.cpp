class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0') return "0";

        int s1 = num1.size(), s2 = num2.size();
        vector<int> num(s1+s2, 0);
        int i1 = s1, i2 = s2;
        while(i1--){
            while(i2--){
                int product = (num1[i1] - '0') * (num2[i2] - '0');
                num[i1+i2+1] += product;
                num[i1+i2] += num[i1+i2+1]/10;
                num[i1+i2+1] %= 10;
            }
            i2 = s2;
        }

        int i = 0;
        while(i<num.size() && num[i]==0) i++;

        string ans = "";
        while(i<num.size())
            ans += num[i++]+'0';
        return ans;
    }
};