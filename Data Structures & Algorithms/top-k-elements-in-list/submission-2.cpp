class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++; //number->freq
        }
        vector<vector<int>>bucket(n+1); //freq->number

        for(auto& it : mp){
            bucket[it.second].push_back(it.first); //building frequency from 1- max
        }

        for(int i = n;i>=1;i--){
            for(auto& temp : bucket[i]){
                res.push_back(temp);
                if(res.size()==k){
                    return res;
                }
            }   
        }
    }
};
