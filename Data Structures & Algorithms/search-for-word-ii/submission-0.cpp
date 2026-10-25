class Solution {
    struct Node{
        Node* letter[26]={};
        bool isEnd = false; 
        string wordFinal = "";
    };
    Node* root = new Node();
public:
    void insert(vector<string>& words){
        for(string& word : words){
            Node* curr = root;
            for(char c : word){
                int idx = c-'a';
                if(!curr->letter[idx]){
                    curr->letter[idx] = new Node();
                }
                curr = curr->letter[idx];
            }
            curr->wordFinal = word;
            curr->isEnd = true;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        vector<string> result;

        insert(words);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i, j, board, visited, root, result);
            }
        }

        return result;
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, Node* curr, vector<string>& result){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==true) return;

        char c = board[i][j];
        int idx = c-'a';
        if(!curr->letter[idx]) return;
        curr = curr->letter[idx];

        if(curr->isEnd){
        result.push_back(curr->wordFinal);
        curr->isEnd = false;  
        }

        visited[i][j] = true;
        dfs(i+1,j, board, visited, curr, result);
        dfs(i-1,j, board, visited, curr, result);
        dfs(i,j+1, board, visited, curr, result);
        dfs(i,j-1, board, visited, curr, result);
        
        visited[i][j] = false;
    }
};
