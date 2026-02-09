class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWordCount = 0;
        for(string sentence: sentences){
            int words = 1;
            for(char c: sentence){
                if(c == ' ')
                    words++;
            }
            maxWordCount = max(maxWordCount, words);
        }
        return maxWordCount;
    }
};