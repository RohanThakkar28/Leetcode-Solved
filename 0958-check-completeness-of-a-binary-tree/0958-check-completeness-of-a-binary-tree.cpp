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
    int hei(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(hei(root->left),hei(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        int h=hei(root);
        int l=1;
        cout<<h<<endl;
        queue<TreeNode*>q;
        q.push(root);
        bool ye=true;
        while(l<h){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto r=q.front();
                q.pop();
                if(ye && !r->left && !r->right){
                    ye=false;
                }
                else if(ye && r->left && !r->right){
                    ye=false;
                }
                else if((r->right || r->left) && !ye){
                    return false;
                }
                if(r->right && !r->left){
                    return false;
                }
                q.push(r->left);
                q.push(r->right);
                
            }
            l++;
        }
        return true;
        
    }
};