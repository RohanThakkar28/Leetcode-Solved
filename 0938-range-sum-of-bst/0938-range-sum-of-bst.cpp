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
    int ans=0;
    void sol(TreeNode* root,int low,int high){
        if(!root){
            return;
        }
        int v=root->val;
        if(v>=low && v<=high){
            ans+=v;
        }
        sol(root->left,low,high);
        
        sol(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sol(root,low,high);
        return ans;
    }
};