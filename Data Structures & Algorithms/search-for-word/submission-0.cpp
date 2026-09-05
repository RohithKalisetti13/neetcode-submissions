class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size();i++){
            for(int j =0; j<board[0].size();j++){
                if(board[i][j]==word.front()){
                    if(find(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int i, int j, string& word, int index){   
        if(index == word.length()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        return false;

        if(board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j]='#';

        bool found = find(board, i+1, j, word, index+1) ||
        find(board, i-1, j, word, index+1) ||
        find(board, i, j+1, word, index+1) ||
        find(board, i, j-1, word, index+1);

        board[i][j]= temp;

        return found;
    }
};
