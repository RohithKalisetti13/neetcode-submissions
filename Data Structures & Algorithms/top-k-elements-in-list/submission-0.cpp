class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }
        for(auto x: mp){
            pq.push({x.second,x.first});
        }

        for(int i =0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
