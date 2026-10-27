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

class Solution {
public:
    int count = 0;
    int answer = 0;
    bool found = false;
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return answer;
    }
    void inOrder(TreeNode* root, int k){
        if(!root || found) return;

        inOrder(root->left, k);
        if(found) return;
        
        count++;
        if(count == k) {
            answer = root->val;
            found = true;
            return;
        } 

        inOrder(root->right, k);
    }
};
