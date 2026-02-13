class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ST;
        unordered_map<char, char> TS;
        for(int i = 0; i<s.size(); i++){
            if(ST.contains(s[i])){
                if(ST[s[i]]!=t[i])
                    return false;
            }
            else
                ST[s[i]] = t[i];
            if(TS.contains(t[i])){
                if(TS[t[i]]!=s[i])
                    return false;
            }
            else
                TS[t[i]] = s[i];
        }
        return true;
    }
};