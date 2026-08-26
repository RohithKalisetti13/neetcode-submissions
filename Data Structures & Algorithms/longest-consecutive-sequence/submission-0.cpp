class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = 0;
        int currlength =0;
        unordered_set<int>set;
        for(int i: nums){
            set.insert(i);
        }
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i]-1)==set.end()){
                int curr=nums[i];
                currlength=1;
                while(set.find(curr+1)!=set.end()){
                    curr++;
                    currlength++;
                }
                length=max(length,currlength);
            }
            
        }
        return length;
    }
};
