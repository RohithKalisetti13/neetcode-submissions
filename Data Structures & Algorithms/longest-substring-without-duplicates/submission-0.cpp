class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxCount = 0;
        unordered_set<char>visited;
        while (right< s.length()){
            if(visited.find(s[right])==visited.end()){
                visited.insert(s[right]);
                maxCount = max(maxCount, right-left+1);
                right++;
            }
            else{
                visited.erase(s[left]);
                left++;
            }
        }
        return maxCount;
    }
};
