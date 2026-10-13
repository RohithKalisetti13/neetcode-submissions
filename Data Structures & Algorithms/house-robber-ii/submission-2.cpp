class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int maxAmount = 0;
        return maxAmount = max(robRange(0,n-2, nums), robRange(1,n-1,nums));
    }
    int robRange(int a, int b, vector<int>& nums){
        if(a==b) return nums[a];
        int prev1 = nums[a];
        int prev2 = max(nums[a],nums[a+1]);
        for(int i = a+2;i<=b;i++){
            int curr = max(prev2, prev1+nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};
