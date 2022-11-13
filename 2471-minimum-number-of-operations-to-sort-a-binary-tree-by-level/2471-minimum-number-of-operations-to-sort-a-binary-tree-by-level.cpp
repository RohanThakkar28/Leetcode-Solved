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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>vec;
            for(int i=0;i<n;i++){
                auto tmp=q.front();
                q.pop();
                vec.push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            vector<int>tmp=vec;
            sort(tmp.begin(),tmp.end());
            
            map<int,int>p;
            for(int i=0;i<vec.size();i++){
                p[tmp[i]]=i;
            }
            vector<bool>vis(n,false);
            for(int i=0;i<n;i++){
                if(vis[i] || p[vec[i]]==i){
                    vis[i]=true;
                    continue;
                }
                int j=i;
               // cout<<j<<endl;
                int c=0;
                while(!vis[j]){
                    vis[j]=true;
                    j=p[vec[j]];
                   // cout<<j<<endl;
                    c++;
                }
                
                ans+=(c-1);
                
            }
         //   cout<<c<<endl;
            
            
        }
        return ans;
    }
};