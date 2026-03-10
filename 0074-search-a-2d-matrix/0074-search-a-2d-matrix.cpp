class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(n + log m)
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i<n; i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                int start = 0, end = m-1;
                while(start<=end){
                    int mid = start + (end-start)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    else if(matrix[i][mid]<target)
                        start = mid+1;
                    else end = mid-1;
                }
            }
        }
        return false;
    }
};