class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        sort(intervals.begin(),intervals.end());

        vector<int> current = intervals[0];
        for(int i=0;i+1<intervals.size();i++){
            if(intervals[i+1][0] <= current[1]){
                current[1] = max(current[1],intervals[i+1][1]);
            }
            else{
                merged.push_back(current);
                current = intervals[i+1];
            } 
        }
        merged.push_back(current);
        return merged;
    }
};
