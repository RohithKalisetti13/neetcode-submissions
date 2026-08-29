class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOne=0;
        int left=0;
        unordered_map<int,int>count;
        for(int right=0;right<nums.size();right++){
            count[nums[right]]++;
            if((count[0]>k)){
                count[nums[left]]--;
                if(count[nums[right]]==0) count.erase(nums[right]);
                left++;
            }
        maxOne = max(maxOne, right-left+1);
        }
        return maxOne;
    }
};