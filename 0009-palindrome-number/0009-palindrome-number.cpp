class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        
        string num = to_string(x);
        int start = 0, end = num.length()-1;
        while(start<end){
            if(num[start]!=num[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};