class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        int target = sum/2;

        if(sum%2!=0) return false;
        
        vector<bool>dp(target+1, false);
        dp[0]=true;

        for(int num: nums){
            for(int s=target;s>=num;s--){
                dp[s]=dp[s] || dp[s-num];
            }
        }
        return dp[target];
    }
};
