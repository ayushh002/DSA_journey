class Solution {
public:
    int solve(int n, int head, int step, bool leftToRight){
        if(n==1) return head;
        // We are focused on moving left only based on the fact that
        // n get half after every function fall (log n)
        if(leftToRight){
            head += step;
        }
        else{
            if(n%2==1)
                head += step;
        }
        return solve(n/2, head, step*2, !leftToRight);
    }
    int lastRemaining(int n) {
        int head = solve(n, 1, 1, true);
        return head;
    }
};