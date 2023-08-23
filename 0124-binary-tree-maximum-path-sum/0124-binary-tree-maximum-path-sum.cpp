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
    int ans=-1e9;
    int sol(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ls=sol(root->left);
        int rs=sol(root->right);
        int temp=max(max(ls,rs)+root->val,root->val);
        ans=max(ans,root->val+ls+rs);
        ans=max(ans,temp);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        sol(root);
        return ans;
        
    }
};