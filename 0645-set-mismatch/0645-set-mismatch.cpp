class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        int repeating = 0;
        int missing = 0;
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i]]==-1){
                repeating = nums[i];
            }
            map[nums[i]] = -1;
        }

        for(int i = 1; i<nums.size()+1; i++){
            if(map[i]!=-1)
                missing=i;
        }


        if(missing && repeating)
            return {repeating, missing};
        return {};
    }
};