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
    void dfs(TreeNode* root,vector<int>&h){
        if(root==NULL){
            return;
        }
        dfs(root->left,h);
        dfs(root->right,h);
        if(root->left){
            h[root->val]=max(h[root->val],h[root->left->val]+1);
        }
        if(root->right){
            
            h[root->val]=max(h[root->val],h[root->right->val]+1);
            
        }
    }
    int cal(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int c=1+cal(root->left)+cal(root->right);
        return c;
    }
    static int comp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=cal(root);
        vector<int>h(n+1,0);
        dfs(root,h);
        int curr=h[root->val];
        cout<<curr<<endl;
        map<int,int>level;
        queue<TreeNode*>q;
        vector<vector<pair<int,int>>>vec;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int len=q.size();
            vector<pair<int,int>>a;
            for(int i=0;i<len;i++){

                auto node=q.front();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
                
                a.push_back({node->val,h[node->val]});
                level[node->val]=lvl;
                
                
            }
            lvl++;
            vec.push_back(a);
            
            
        }
        for(int i=0;i<vec.size();i++){
            sort(vec[i].begin(),vec[i].end(),comp);
        }
        vector<int>ans;
        //cout<<h[3]<<endl;
        for(int i=0;i<queries.size();i++){
            int node=queries[i];
            int lvl=level[node];
            vector<pair<int,int>>v=vec[lvl];
            if(v[0].first!=node){
                
                ans.push_back(curr);
            }
            else{
                int l=v[0].second;
                int m=-1;
                if(v.size()>1){
                    m=v[1].second;
                }
                ans.push_back(max(curr-l+m,0));
            }
        }
        return ans;
        /*
            1
               5
              3 
            2   4
            
        
        */
        
        
        
        
    }
};