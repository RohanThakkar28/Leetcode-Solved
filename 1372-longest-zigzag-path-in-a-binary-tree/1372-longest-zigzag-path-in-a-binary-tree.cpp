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
    map<TreeNode*,pair<int,int>>dp;
    void sol(TreeNode* root){
        if(!root){
            return;
        }
        sol(root->left);
        sol(root->right);
        
        dp[root]={0,0};
        
        if(root->left){
            dp[root].first=1+dp[root->left].second;
            
            
        }
        if(root->right){
            dp[root].second=1+dp[root->right].first;
            
        }
        
    }
    int longestZigZag(TreeNode* root) {
        int maxy=0;
        sol(root);
        for(auto i:dp){
            int i1=i.second.first;
            int i2=i.second.second;
            maxy=max({maxy,i1,i2});
        }
        return maxy;
        
    }
};