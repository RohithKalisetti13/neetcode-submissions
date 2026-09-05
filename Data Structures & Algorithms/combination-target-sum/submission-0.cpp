class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        combo(nums, 0, target,result, current);
        return result;
    }

    void combo(vector<int>& nums, int start, int rem, vector<vector<int>>& result, vector<int>& current){   
        if(rem == 0){
            result.push_back(current);
            return;
        }
        for(int i = start; i< nums.size();i++){
            if(nums[i]>rem) continue;
            else{
                current.push_back(nums[i]);
                combo(nums,i, rem-nums[i],result, current);
                current.pop_back();
            }
         }

    }
};
