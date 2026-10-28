/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //bruteforce

        if(intervals.empty()) return 0;
        vector<int>rooms;
        
        sort(intervals.begin(),intervals.end(), [](const Interval& a, const Interval&b){
            return a.start<b.start;
        });

        for(auto& interval : intervals){
            int start = interval.start;
            int end = interval.end;
            
            bool used = false;
            for(int i=0;i<rooms.size();i++){
                if(rooms[i]<=start){
                    rooms[i]=end;
                    used = true;
                    break;
                }
            }
            if(!used){
                rooms.push_back(end);
            }
        }
        return rooms.size();
    }
};
