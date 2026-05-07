class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxArea = 0;

        int left = 0, right = size-1;
        while(left<right){
            int h = min(height[left], height[right]);
            int w = right-left;
            int area = h*w;
            maxArea = max(area, maxArea);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};