class Solution {
public:
    // O(n log k) - Optimized
    vector<int> minHeap;
    void insert(int num, int k){

        int index = minHeap.size();
        minHeap.push_back(num);

        while(index>0 && minHeap[(index-1)/2] > minHeap[index]){
            swap(minHeap[(index-1)/2], minHeap[index]);
            index = (index-1)/2;
        }

        if(minHeap.size()>k){
            deleteTop(k);
        }
    }

    void deleteTop(int k){
        int size = minHeap.size();

        minHeap[0] = minHeap[size-1];
        minHeap.pop_back();

        if(minHeap.size()==0) return;
        Heapify(0);
    }

    void Heapify(int index){
        int size = minHeap.size();
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && minHeap[left]<minHeap[smallest])
        smallest = left;
        if(right<size && minHeap[right]<minHeap[smallest])
        smallest = right;

        if(smallest!=index){
            swap(minHeap[index], minHeap[smallest]);
            Heapify(smallest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++){
            insert(nums[i], k);
        }
        return minHeap[0];
    }
};