class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num){
            int digit = num%10;
            rev = rev*10 + digit;
            num/=10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        set<int> unique;
        for(int num : nums){
            int rev = reverse(num);
            unique.insert(num);
            unique.insert(rev);
        }  
        return unique.size();
    }
};