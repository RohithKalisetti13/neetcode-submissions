class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getPermutations(nums,0,result);
        return result;
    }

    void getPermutations(vector<int>& nums,int idx, vector<vector<int>>& result){
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
           getPermutations(nums,idx+1,result);
            swap(nums[idx],nums[i]);

        }
    }
};
