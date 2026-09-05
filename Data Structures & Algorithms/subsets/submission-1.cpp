class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        getSubsets(nums, 0, ans, result);

    return result;
    }

    void getSubsets(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& result){
        if(i==nums.size()) {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getSubsets(nums, i+1, ans, result);
        ans.pop_back();
        getSubsets(nums, i+1, ans, result);
    }
};
