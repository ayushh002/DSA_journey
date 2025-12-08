class Solution {
public:
    int INF = 1e9;
    vector<vector<int>> dp;

    int solve(vector<int>& jobDifficulty, int i, int n, int d){
        if (i == n && d == 0) return 0;        // perfect schedule
        if (i == n || d == 0) return INF;      // invalid schedule

        if (dp[i][d] != -1) return dp[i][d];

        int dayMax = 0;
        int ans = INF;

        for (int j = i; j <= n - d; j++) {
            dayMax = max(dayMax, jobDifficulty[j]);

            int remaining = solve(jobDifficulty, j + 1, n, d - 1);
            if (remaining != INF) {
                ans = min(ans, dayMax + remaining);
            }
        }

        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;

        dp = vector<vector<int>>(n, vector<int>(d + 1, -1));

        int res = solve(jobDifficulty, 0, n, d);
        return res >= INF ? -1 : res;
    }
};