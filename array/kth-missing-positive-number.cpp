class Solution {
    public :
    int findKthPositive(vector<int> &arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Calculate how many numbers are missing before the index 'mid'
            // Expected value at index mid is (mid + 1)
            int missingNumbersTillNow = arr[mid] - (mid + 1);
            
            if (missingNumbersTillNow < k) {
                // Not enough missing numbers yet, look to the Right
                start = mid + 1;
            } else {
                // Too many (or exactly k) missing numbers, look to the Left
                end = mid - 1;
            }
        }
        
        return k + start;
    }
};