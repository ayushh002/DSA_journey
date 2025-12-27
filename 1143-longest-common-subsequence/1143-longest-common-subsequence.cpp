class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Bottom Up - tabulation
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m+1, 0);
        for(int i = 1; i<=n; i++){
            int prevDiag = 0;
            for(int j = 1; j<=m; j++){
                int aboveElement = dp[j];
                if(text1[i-1]==text2[j-1])
                    dp[j] = 1+prevDiag;
                else
                    dp[j] = max(aboveElement, dp[j-1]);

                prevDiag = aboveElement;
            }
        }
        return dp[m];
    }
};