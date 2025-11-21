class Solution {
public:
    bool check(unordered_set<int>& seen, int n){
        if(n==1) return true;

        if(seen.count(n))
            return false;

        seen.insert(n);
        int newNum = 0;
        while(n>0){
            int digit = n%10;
            newNum += digit*digit;
            n/=10;
        }

        return check(seen, newNum);
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        return check(seen, n);
    }
};