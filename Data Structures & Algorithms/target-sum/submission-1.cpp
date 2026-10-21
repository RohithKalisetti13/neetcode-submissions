class Solution {
public:
     map<pair<int,int>, int> memo;

    int findTargetSumWays(vector<int>& nums, int target) { 

    return solve(0, 0, nums, target);
    }

    int solve(int i, int currentSum, vector<int>& nums, int target){
        if(i == nums.size()) return currentSum == target ? 1 : 0;
        
        pair<int,int> state = {i, currentSum};
       
        if(memo.find(state)!=memo.end()) return memo[state];

        int add = solve(i+1, currentSum+nums[i], nums, target);
        int subtract = solve(i+1, currentSum-nums[i],nums, target);

        memo[state]= add+subtract;
        return memo[state];
    }
};
