class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // storing it in set and finding duplicates is
        // present by comparing the size of set and arr
        unordered_set<int> temp;
        for(int num : nums){
            temp.insert(num);
        }
        return !(nums.size() == temp.size());
    }
};