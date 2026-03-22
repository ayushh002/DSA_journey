class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);

        // Insert all the words
        int count = 0; // to store the count of words
        string currentWord = "";
        for (char c: s) {
            if(c == ' ') continue; 

            if (isdigit(c)) {
                int idx = c - '0';
                words[idx-1] = currentWord;
                currentWord = ""; 
                count++;
            }
            else
                currentWord += c;
        }

        // Generate the sentence from array of words
        string sentence = "";
        for(int i = 0; i < count; i++){
            if(i>0)
                sentence += " ";
            sentence+=words[i];
        }
        return sentence;
    }
};