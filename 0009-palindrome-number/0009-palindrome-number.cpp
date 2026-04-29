class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        if(x<10) return 1;
        if(x%10==0) return 0;
        int temp = 0;
        while(x>temp){
            int rem = x%10;
            temp = temp*10+rem;
            x /= 10;
        }
        
        return (x==temp || temp/10==x);
    }
};