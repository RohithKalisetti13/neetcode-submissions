class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumMap;
        // Prefix sum 0 has occurred once before we start.
        // This lets us count subarrays that begin at index 0.
        sumMap[0]=1; 
        int count=0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
        // Current prefix sum from index 0 to i
        sum += nums[i];

        // We want:
        // currentSum - previousPrefixSum = k
        // so previousPrefixSum = currentSum - k
        int diff = sum - k;

        // Every previous occurrence of 'diff'
        // creates one valid subarray ending at i
        count += sumMap[diff];

        // Store this prefix sum for future elements
        sumMap[sum]++;
    }
        return count;
    }
};