class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<vector<int>,vector<string>>group;
       
        for(auto it: strs){
            vector<int>freq(26,0);
            for(char c: it){
            freq[c-'a']++;
            }
            group[freq].push_back(it);
        }
        for(auto it: group){
            res.push_back(it.second);
        }
        return res;
    }
};
