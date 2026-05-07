class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        int maxHeight=height[0], maxIdx=0;
        for(int i=1; i<size; i++){
            if(maxHeight<height[i]){
                maxHeight = height[i];
                maxIdx = i;
            }
        }

        int ans = 0, prefixMax = height[0], suffixMax = height[size-1];
        for(int i=1; i<maxIdx; i++){
            if(prefixMax>height[i])
                ans += prefixMax-height[i];
            prefixMax = max(prefixMax, height[i]);
        }
        for(int i=size-2; i>maxIdx; i--){
            if(suffixMax>height[i])
                ans += suffixMax-height[i];
            suffixMax = max(suffixMax, height[i]);
        }
        return ans;
    }
};