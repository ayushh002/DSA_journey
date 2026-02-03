class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> seen;
        for(char c: jewels)
            seen[c] = true;

        int count = 0;
        for(char c: stones){
            if(seen[c])
                count++;
        }

        return count;

    }
};