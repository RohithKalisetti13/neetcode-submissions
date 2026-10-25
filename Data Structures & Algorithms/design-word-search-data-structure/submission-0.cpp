class WordDictionary {
    struct Node{
        Node* letter[26]={};
        bool isEnd = false;
    };
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(const string& word) {
        Node* curr = root;
        for(char c : word){
            int idx = c - 'a';
            if(!curr->letter[idx]){
                curr->letter[idx] = new Node();
            }

            curr = curr->letter[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(const string& word) {
        return dfs(word, 0, root);
    }

    bool dfs(const string& word, int pos, Node* curr){
        if(pos == word.size()) return curr->isEnd;
        char c = word[pos];
        
        if(c != '.'){
            int idx = c-'a';
            if(!curr->letter[idx]) return false;
            return dfs(word, pos+1, curr->letter[idx]);
        }
        

        for(int i=0;i<26;i++){
            if(curr->letter[i] && dfs(word, pos+1, curr->letter[i])) return true;
        }
        return false;
    }

};
