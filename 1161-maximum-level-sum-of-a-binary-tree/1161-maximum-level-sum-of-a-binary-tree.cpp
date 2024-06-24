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
    
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        int maxy=root->val;
        queue<TreeNode*>q;
        q.push(root);
        int l=1;
        while(q.size()>0){
            int sum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                sum+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(sum>maxy){
                ans=l;
                maxy=sum;
            }
            l++;
        }
        return ans;
        
        
    }
};