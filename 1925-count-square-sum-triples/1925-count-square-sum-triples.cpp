class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i = 3; i <= n; i++){
            for(int j = 3; j <= n; j++){
                int sum = i*i + j*j;
                int c = sqrt(sum);
                if(c<=n && c*c==sum)
                    count++;
            }
        }
        return count;
    }
};