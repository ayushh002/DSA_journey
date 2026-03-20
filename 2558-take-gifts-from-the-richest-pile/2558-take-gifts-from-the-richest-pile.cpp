class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int x: gifts) pq.push(x);

        while(k-- && !pq.empty()){
            int pile = pq.top();
            pq.pop();
            int reduced = floor(sqrt(pile));
            if(reduced)
                pq.push(reduced);
        }

        long long totalGifts = 0;
        while(!pq.empty()){
            totalGifts += pq.top();
            pq.pop();
        }
        return totalGifts;
    }
};