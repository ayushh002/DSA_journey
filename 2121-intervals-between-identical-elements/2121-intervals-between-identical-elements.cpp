class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for(auto &it : mp) {
            vector<int> &idx = it.second;
            int m = idx.size();

            vector<long long> prefix(m);
            prefix[0] = idx[0];

            for(int i = 1; i < m; i++)
                prefix[i] = prefix[i-1] + idx[i];

            for(int k = 0; k < m; k++) {
                long long left = 0, right = 0;

                if(k > 0)
                    left = 1LL * idx[k] * k - prefix[k-1];

                if(k < m-1)
                    right = (prefix[m-1] - prefix[k]) - 1LL * idx[k] * (m-k-1);

                ans[idx[k]] = left + right;
            }
        }

        return ans;
    }
};