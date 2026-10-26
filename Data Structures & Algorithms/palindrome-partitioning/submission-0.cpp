class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>current;
        palPartition(s, 0, res, current);
        return res;
    }

    void palPartition(string& s, int start, vector<vector<string>>& res, vector<string>& current){
        if(start == s.size()) {
            res.push_back(current);
            return;
        }
        for(int end=start;end<s.size();end++){
            string sub = s.substr(start, end-start+1);
            
            if(isPalindrome(sub)){
                current.push_back(sub);
                palPartition(s, end+1, res, current);
                current.pop_back();
                
            }
        }
    }

    bool isPalindrome(string s){
        int left =0;
        int right = s.size()-1;
        while(left<right){

            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
