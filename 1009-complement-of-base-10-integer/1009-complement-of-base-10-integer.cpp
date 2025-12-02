class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0) return 1;

        int complement = 0, mul=1;
        while(n>0){
            // reversing the digits
            int digit = !(n%2);
            // Converting to decimal
            complement += mul * digit;
            mul *= 2;
            n /= 2;
        }
        return complement;
    }
};