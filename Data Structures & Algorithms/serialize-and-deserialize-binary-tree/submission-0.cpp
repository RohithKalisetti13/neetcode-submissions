/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "NULL";
        string result;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(!curr){
                result += "NULL,";
                continue;
            }
            result += to_string(curr->val)+",";

            q.push(curr->left);
            q.push(curr->right);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data =="NULL") return nullptr;
        
        vector<string>tokens;
        string temp;
        for(char c : data){
            if(c== ','){
                tokens.push_back(temp);
                temp ="";
            }
            else{
                temp+=c;
            }
        }
        
        TreeNode* root = new TreeNode(stoi(tokens[0]));

        queue<TreeNode*>q;
        q.push(root);
        int idx = 1;

        while(!q.empty() && idx<tokens.size()){

            TreeNode* curr = q.front();
            q.pop();

            //left
            if(idx<tokens.size() && tokens[idx] != "NULL"){
                curr->left = new TreeNode(stoi(tokens[idx]));
                q.push(curr->left);
            }
            idx++;
            //right
            if(idx<tokens.size() && tokens[idx] != "NULL"){
                curr->right = new TreeNode(stoi(tokens[idx]));
                q.push(curr->right);
            }
            idx++;
        }
        return root;
    }
};
