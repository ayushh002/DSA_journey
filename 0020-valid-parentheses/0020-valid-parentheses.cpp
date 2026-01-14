class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> fmap = { {')', '('}, {'}', '{'}, {']', '['}};

        for (char c: s){
            if(fmap.count(c)){
                if(st.empty() || st.top()!=fmap[c])
                    return false;
                char top = st.empty() ? '*' : st.top();
                    st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};