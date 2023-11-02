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
    pair<int,int> sol(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }
        pair<int,int>a=sol(root->left);
        pair<int,int>b=sol(root->right);
        int va=a.first+b.first+root->val;
        int c=a.second+b.second+1;
        if(root->val==(va/c)){
            ans++;
        }
        return make_pair(va,c);
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        sol(root);
        return ans;
    }
};