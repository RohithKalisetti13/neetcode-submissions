class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,0);
        return max(robRange(0,n-2,nums,dp),robRange(1,n-1,nums,dp));    
    }
    int robRange(int a, int b, vector<int>& nums, vector<int>& dp){
        if(a==b) return nums[a];
        dp[a]= nums[a];
        dp[a+1]= max(nums[a],nums[a+1]);
        for(int i=a+2;i<=b;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[b];
    }
};
