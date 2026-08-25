class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, int>freq;
        for(auto it : s){
            freq[it]++;
        }
        for(auto it: t){
            freq[it]--;
            
            if(freq[it]<0) return false;

        }
       

        return true;
    }
};
