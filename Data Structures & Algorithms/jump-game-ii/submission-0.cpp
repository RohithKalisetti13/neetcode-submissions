class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int farthest =0;
        int currentEnd = 0;
        for(int i=0;i<nums.size();i++){
            if(currentEnd==nums.size()-1) continue;
           farthest = max(farthest, i+nums[i]);
            if(i==currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
