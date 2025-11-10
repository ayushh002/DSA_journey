class Solution {
public:
    bool checkPalindrome(string& s, int start, int end){
        if(start>=end) return true;
        if(s[start]!=s[end]) return false;
        return checkPalindrome(s, start+1, end-1);
    }
    void findPalindrome(vector<vector<string>>& ans, vector<string>& temp, string s, int partition){ 
        if(partition==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = partition; i<s.size(); i++){
            if(checkPalindrome(s, partition, i)){
                temp.push_back(s.substr(partition, i-partition+1));
                findPalindrome(ans, temp, s, i+1);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        findPalindrome(ans, temp, s, 0);
        return ans;
    }
};