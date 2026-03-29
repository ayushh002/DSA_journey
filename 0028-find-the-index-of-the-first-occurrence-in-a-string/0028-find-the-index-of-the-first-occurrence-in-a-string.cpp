class Solution {
public:
    int strStr(string haystack, string needle) {
        // Brute Force - O(n^2)
        int n = haystack.size();
        int m = needle.size();

        int left = 0, right = 0;
        while(left<n){
            if(haystack[left]==needle[right]){
                left++;
                right++;
                if(right==m)
                    return left-right;
            }
            else{
                left = left-right+1;
                right = 0;
            }
        }
        return -1;
    }
};