class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(search(i, j, 0, board, word)) return true;
                }
            }
        }

    return false;
    }

    bool search(int i, int j, int idx, vector<vector<char>>& board, string word){
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i>=board.size() || j>= board[0].size() || board[i][j] == '#') return false;
        
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        
        board[i][j] = '#';

        bool found = search(i+1, j, idx+1, board, word) || search(i-1, j, idx+1, board, word) ||
                     search(i, j+1, idx+1, board, word) || search(i, j-1, idx+1, board, word);

        board[i][j] = temp;

        return found;

    }
};
