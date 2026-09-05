class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        braces(0,0,n,current,result);
        return result;
    }

    void braces(int open, int close, int n, string& current, vector<string>& result){
        if(open==n && close==n){
            result.push_back(current);
            return;
        }

        if(open<n){
           current.push_back('(');
           braces(open+1,close,n,current,result);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            braces(open,close+1,n,current,result);
            current.pop_back();
        }

    }
};
