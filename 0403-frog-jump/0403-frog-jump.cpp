class Solution {
public:
    int mem[2000][2000];
    unordered_map<int, int> mp;

    int calculate(vector<int>&stones, int curr_stone_index, int prev_jump){
        // If frog reaches the last stone, success
        if(curr_stone_index==stones.size()-1)
            return true;
        // Memoized result
        if (mem[curr_stone_index][prev_jump] != -1)
            return mem[curr_stone_index][prev_jump];

        for(int next_jump = prev_jump - 1; next_jump<=prev_jump+1; next_jump++){
            if(next_jump>0){
                int next_stone = stones[curr_stone_index]+next_jump;

                // Check if such stone exists
                if (mp.count(next_stone)) {
                    int next_index = mp[next_stone];
                    if (calculate(stones, next_index, next_jump))
                        return mem[curr_stone_index][prev_jump] = 1;
                }
            }
        }
        return mem[curr_stone_index][prev_jump] = 0;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1) return false;

        memset(mem, -1, sizeof(mem));

        for(int i = 0; i<n; i++) mp[stones[i]] = i;
        return calculate(stones, 0, 0);
    }
};