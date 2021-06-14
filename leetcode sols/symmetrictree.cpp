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
    bool sym(TreeNode* l, TreeNode* r){
        if((l==NULL&&r!=NULL)||(l!=NULL&&r==NULL)) return false;
        if(l==NULL&&r==NULL) return true;
        if(l->val==r->val)
            return(sym(l->left,r->right)&sym(l->right,r->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return sym(root->left,root->right);
    }
};