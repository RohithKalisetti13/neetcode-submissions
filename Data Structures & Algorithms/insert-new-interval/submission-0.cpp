class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> merged;

        vector<int>current = newInterval;
        bool inserted = false;

        for(int i=0;i<intervals.size();i++){
            
            if(intervals[i][1] < current[0]){
                merged.push_back(intervals[i]);
            }

            else if(intervals[i][0] > current[1]){
                if(!inserted){
                  merged.push_back(current);
                  inserted = true;  
                }
                
                merged.push_back(intervals[i]);
            }

            else{
                current[0] = min(current[0],intervals[i][0]);
                current[1] = max(current[1],intervals[i][1]);
            }

        }  

        if(!inserted){
            merged.push_back(current);
            inserted = true;  
        }
  
        return merged;

    }
};
