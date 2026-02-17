class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            int idx = abs(arr[i])-1;
            if(arr[idx]<0){
                return abs(arr[i]);
            }
            arr[idx] = -arr[idx];
        }
        return -1;
    }
};