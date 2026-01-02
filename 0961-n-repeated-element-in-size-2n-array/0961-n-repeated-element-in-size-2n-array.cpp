class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int count = nums.size()/2;
        unordered_map<int, int> freqMap;
        for(int i = 0; i<nums.size(); i++)
            freqMap[nums[i]]++;
        for(auto& entry : freqMap){
            if(entry.second == count)
                return entry.first;
        }
        return -1;
    }
};