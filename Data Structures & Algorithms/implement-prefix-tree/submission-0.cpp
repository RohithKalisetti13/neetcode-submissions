class PrefixTree {
    struct Node{
        Node* child[26] = {}; //nullptr
        bool isEnd = false;
    };
    Node* root = new Node();
public:
    PrefixTree() {
        
    }
    
    void insert(const string& word) {
        Node* curr = root;
        for(char c : word){
            int idx = c-'a';
            if(curr->child[idx] == nullptr){ //if the char doesnt exist
                curr->child[idx] = new Node(); // create a new node and add child
            }
            curr = curr->child[idx]; // move curr to next
        }
        curr->isEnd = true; // at the end mark isEnd true
    }
    
    bool search(const string& word) {
        Node* curr = root;
        for(char c : word){
            int idx = c-'a';
            if(curr->child[idx]== nullptr) return false;

            curr = curr->child[idx];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(const string& prefix) {
        Node* curr = root;
        for(char c : prefix){
            int idx = c-'a';
            if(curr->child[idx]== nullptr) return false;

            curr = curr->child[idx];
        }
        return true;
    }
};
