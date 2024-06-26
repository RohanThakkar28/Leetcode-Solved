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
    vector<int>a;
    TreeNode* create(int l,int r){
        if(l>r){
            return NULL;
        }
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(a[m]);
        root->left=create(l,m-1);
        root->right=create(m+1,r);
        return root;
    }
    void trans(TreeNode* root){
        if(!root){
            return;
        }
        a.push_back(root->val);
        trans(root->left);
        trans(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        trans(root);
        sort(a.begin(),a.end());
        TreeNode* ans=create(0,a.size()-1);
        return ans;
        
    }
};