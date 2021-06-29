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
    void mind(TreeNode* root, set<int>& s, int& min){
        if(root){
            mind(root->left,s,min);
            for(auto it=s.begin();it!=s.end();it++){
                if(abs(*it-root->val)<min){
                    min=abs(*it-root->val);
                }
            }
            s.insert(root->val);
            mind(root->right,s,min);
        }
    }
    int minDiffInBST(TreeNode* root) {
        set<int> s;
        int min=INT_MAX;
        mind(root,s,min);
        return min;
    }
};