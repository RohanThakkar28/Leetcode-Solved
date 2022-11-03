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
    map<pair<int,int>,int>pos;
    vector<pair<pair<int,int>,int>>arr;
    void sol(TreeNode* root,int x,int y){
        if(!root){
            return;
        }
        arr.push_back({{x,y},root->val});
        sol(root->left,x+1,y-1);
        sol(root->right,x+1,y+1);
    }
    static bool comp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
        if(a.first.second==b.first.second && a.first.first==b.first.first){
            return a.second<b.second;
        }
        if(a.first.second==b.first.second){
            return a.first.first<b.first.first;
        }
        
        return a.first.second<b.first.second;
    }
        
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        sol(root,0,0);
        sort(arr.begin(),arr.end(),comp);
        int i=0;
        int n=arr.size();
        while(i<arr.size()){
            vector<int>tmp;
            tmp.push_back(arr[i].second);
            
            int c=arr[i].first.second;
            i++;
            while(i<n && arr[i].first.second==c){
                tmp.push_back(arr[i].second);
                i++;
            }
            ans.push_back(tmp);
            
        }
        return ans;
        
    }
};