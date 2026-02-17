class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int size = arr.size();
        for(int num : arr){
            int idx = abs(num);
            if(arr[idx-1]<0){
                return idx;
            }
            arr[idx-1] = -arr[idx-1];
        }
        return size;
    }
};