class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> unique;
        for(int x: nums){
            if(x!=0)
            unique.insert(x);
        } 
            
        return unique.size();
    }
};