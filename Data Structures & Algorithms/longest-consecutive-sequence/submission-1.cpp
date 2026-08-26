class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = 0;
        unordered_set<int>seen;
        for(int i:nums){
            seen.insert(i);
        }
        for(int i:seen){
            if(seen.find(i-1)==seen.end()){
                int currlength =1;
                int curr = i;
                while(seen.find(curr+1)!=seen.end()){
                    curr++;
                    currlength++;
                }
                length = max(length, currlength);
            }
        }
        return length;
    }
};
