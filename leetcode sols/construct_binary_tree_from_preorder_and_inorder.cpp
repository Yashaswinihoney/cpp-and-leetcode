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
    int index=0;
    int search(vector<int> in, int n, int s,int e){
        if(s>e) return -1;
        for(int i=s;i<=e;i++){
            if(n==in[i]) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> pre, vector<int> in, int s,int e){
        if(s>e) return NULL;
        int curr=pre[index++];
        TreeNode* root=new TreeNode(curr);
        if(s==e) return root;
        int pos=search(in,curr,s,e);
        root->left=build(pre,in,s,pos-1);
        root->right=build(pre,in,pos+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=build(preorder, inorder, 0,preorder.size()-1);
        return root;
    }
};