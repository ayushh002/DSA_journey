class Solution {
public:
    int mySqrt(int target) {

        int start = 0, end = target, sqrt;
        long long mid;
        while(start<=end){
            mid = start+(end-start)/2;

            if(mid*mid == target)
                return mid;

            else if(mid*mid <= target){
                sqrt = mid;
                start = mid + 1;
            }
            else
                end = mid-1;
        }
        return sqrt;
    }
};