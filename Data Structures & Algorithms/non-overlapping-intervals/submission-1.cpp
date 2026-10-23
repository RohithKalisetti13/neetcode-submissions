class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int removal = 0;

        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];

        for(int i=1;i<intervals.size();i++){

            if(intervals[i][0] < prevEnd){
                removal++;
                prevEnd = min(prevEnd, intervals[i][1]); // keep which ever ends earlier and remove
                
            }
            else{
                prevEnd = intervals[i][1]; // no overlap keep current interval
            }
        }
        return removal;
    }
};
