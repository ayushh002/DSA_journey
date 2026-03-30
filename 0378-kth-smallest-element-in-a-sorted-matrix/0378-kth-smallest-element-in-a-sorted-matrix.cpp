class Solution {
public:
    int countNodes(vector<vector<int>>& matrix, int mid){
        // Most Optimized - O(n log n) time and O(1) space
        int n = matrix.size();
        int count = 0;
        int i = n-1, j = 0;
        while(i>=0 && j<n){
            if(matrix[i][j]<=mid){
                count += (i+1);
                j++;
            }
            else
                i--;
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans;
        int start = matrix[0][0], end = matrix[n-1][n-1];
        while(start<=end){
            int mid = start + (end-start)/2;
            if(countNodes(matrix, mid)<k)
                start = mid + 1;
            else{
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};