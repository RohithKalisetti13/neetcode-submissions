class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> current;
       vector<vector<int>>result;
       combination(0, nums, target,current, result);
       return result; 
    }

    void combination(int start, vector<int>& nums, int target, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(nums[i]>target) continue;
        
            current.push_back(nums[i]);
            combination(i, nums, target-nums[i],current, result);
            current.pop_back();

        }
    }

};
