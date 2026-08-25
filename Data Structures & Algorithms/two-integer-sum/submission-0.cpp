class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     for(int j=1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target) return {i,j};
        //     }
        // }
        unordered_map<int,int> mp;
        int comp;
        for(int i=0;i<nums.size();i++){
            comp=target-nums[i];
            if(mp.count(comp)) 
                return {mp[comp],i}; 
            mp[nums[i]]=i;
        }
        return {};
    }
};
