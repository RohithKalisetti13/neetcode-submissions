class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        parenthesis(n, 0, 0, result, current);
        return result;
    }

    void parenthesis(int n, int open, int close, vector<string>& result, string current){
        if(open== n && close== n){
            result.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            parenthesis(n, open+1, close, result, current);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            parenthesis(n, open, close+1, result, current);
            current.pop_back();
        }

    }
};
