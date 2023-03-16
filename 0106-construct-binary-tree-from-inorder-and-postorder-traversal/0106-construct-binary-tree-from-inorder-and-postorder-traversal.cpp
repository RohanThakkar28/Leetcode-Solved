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
    TreeNode* sol(vector<int>&inorder,vector<int>&postorder){
        int n=inorder.size();
        if(n==0){
            return NULL;
        }
       
        TreeNode* root=new TreeNode(postorder[n-1]);
        vector<int>lo;
        vector<int>ro;
        int i=0;
        while(inorder[i]!=postorder[n-1]){
            lo.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i<n){
            ro.push_back(inorder[i]);
            i++;
        }
        int n1=lo.size();
        int n2=ro.size();
        vector<int>lp;
        vector<int>rp;
        for(int i=0;i<n1;i++){
            lp.push_back(postorder[i]);
        }
        for(int i=n1;i<n1+n2;i++){
            rp.push_back(postorder[i]);
        }
        root->left=sol(lo,lp);
        root->right=sol(ro,rp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return sol(inorder,postorder);
        
        
        
    }
};