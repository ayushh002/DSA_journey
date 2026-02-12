class Solution {
public:
   int findKthPositive(vector<int>& arr, int k) {
    int size = arr.size();
    int counting = 1, count = 0;

    for (int i = 0; i < size; i++) {
        while (counting < arr[i]) { 
            // Counting missing numbers before arr[i]
            count++;
            if (count == k) {
                return counting; // Found the k-th missing number
            }
            counting++;
        }
        counting++; // Move to the next number
    }

    // If the k-th missing number is beyond the largest element in the array
    while (count < k) {
        count++;
        counting++;
    }

    return counting - 1; // Return the k-th missing number
}


};