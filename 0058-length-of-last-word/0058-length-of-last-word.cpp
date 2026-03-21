class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), i;
        for(i = n-1; i>=0; i--){
            if(s[i]!=' ')
                break;
        }
        int count = 0;
        while(i>=0 && s[i]!=' '){
            count++;
            i--;
        }
        
        return count;
    }
};