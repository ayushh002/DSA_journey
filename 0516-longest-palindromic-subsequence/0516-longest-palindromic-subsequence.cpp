class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.length();
        int m = rev.length();
        vector<int> dp(m+1, 0);

        for(int i = 1; i<=n; i++){
            int prevDiag = 0;
            for(int j = 1; j<=m; j++){
                int aboveElement = dp[j];
                if(s[i-1]==rev[j-1])
                    dp[j] = 1+prevDiag;
                else
                    dp[j] = max(aboveElement, dp[j-1]);
                    
                prevDiag = aboveElement;
            }
        }
        return dp[m];
    }
};