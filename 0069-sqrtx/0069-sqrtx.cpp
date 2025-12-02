class Solution {
public:
    int mySqrt(int target) {
        int start = 0;
        int end = target;
        long long int mid;
        int sqrt;
        while(start<=end){
            mid = start + (end-start)/2;
            if(mid*mid==target){
                sqrt = mid;
                break;
            }
            else if(mid*mid<target){
                sqrt = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return sqrt;
    }
};