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
        if(intervals.empty()) return 0;

        priority_queue<int, vector<int>,greater<int>>rooms;
        sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b){
            return a.start<b.start;
        });
        
        for(auto& meeting : intervals){
            int start = meeting.start;
            int end = meeting.end;
            if(!rooms.empty() && rooms.top()<= start){
                rooms.pop();
            }
            rooms.push(end);
        }
        return rooms.size();
    }
};
