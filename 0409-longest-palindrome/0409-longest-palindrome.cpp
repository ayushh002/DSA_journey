class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        bool hasOddChar = false;

        unordered_map<char, int> freq;
        for(char c: s) freq[c]++;

        int length = 0;
        for(auto& p: freq){
            length += p.second;
            if(p.second%2!=0){
                length--;
                hasOddChar = true;
            }
        }

        if(hasOddChar)
            length++;
        
        return length;
    }
};