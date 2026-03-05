class Solution {
public:
    int minOperations(string s) {
        int first = 0, second = 0;
        int flip = 1;
        for(int i = 0; i<s.size(); i++){
            if(flip!=(s[i]-'0'))
                first++;
            flip = flip == 1 ? 0 : 1;
        }
        flip = 0;
        for(int i = 0; i<s.size(); i++){
            if(flip!=(s[i]-'0'))
                second++;
            flip = flip == 1 ? 0 : 1;
        }
        return min(first, second);
    }
};