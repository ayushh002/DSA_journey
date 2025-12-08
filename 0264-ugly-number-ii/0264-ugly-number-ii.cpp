class Solution {
public:
    int nthUglyNumber(int n) {
        int twoCount = 0;
        int threeCount = 0; 
        int fiveCount = 0;

        int index = 1;
        vector<int> dp(n);
        dp[0] = 1;
        while(index<n){
            int twoMultiple = 2*dp[twoCount];
            int threeMultiple = 3*dp[threeCount];
            int fiveMultiple = 5*dp[fiveCount];

            int uglyNumber = min({twoMultiple, threeMultiple, fiveMultiple});

            if(uglyNumber==twoMultiple) twoCount++;
            if(uglyNumber==threeMultiple) threeCount++;
            if(uglyNumber==fiveMultiple) fiveCount++;
            
            dp[index++] = uglyNumber; 
        }

        return dp[n-1];
    }
};