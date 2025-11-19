class Solution {
public:
    int winner(vector<bool>& eliminated, int n, int index, int person_count, int k){
        if(person_count==1){
            for(int i = 0; i<n; i++){
                if(!eliminated[i])
                    return i+1;
            }
        }

        int kill = (k-1) % person_count;
        while(kill--){
            index = (index+1) % n;
            while(eliminated[index]) 
                index = (index+1) % n;
        }

        eliminated[index] = 1;

        while(eliminated[index]) 
            index = (index+1) % n;

        return winner(eliminated, n, index, person_count-1, k);
    }
    
    int findTheWinner(int n, int k) {
        vector<bool> eliminated(n, 0);
        return winner(eliminated, n, 0, n, k);
    }
};