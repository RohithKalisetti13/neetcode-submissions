class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> eachSet;
        createSubset(nums, 0, eachSet, result);

        return result;
    }

    void createSubset(vector<int>& nums, int i, vector<int>& eachSet, vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(eachSet);
            return;
        }

        eachSet.push_back(nums[i]);
        createSubset(nums, i+1, eachSet, result);
        eachSet.pop_back();
        createSubset(nums, i+1, eachSet, result);

    }

};
