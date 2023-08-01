class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,int n,int k,int i){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i>n){
            return;
        }
        solve(ans,temp,n,k,i+1);
        temp.push_back(i);
        solve(ans,temp,n,k,i+1);
        temp.pop_back();
        i--;
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(ans,temp,n,k,1);
        ///set<vector<int>>a;
        return ans;
        
        
        
    }
};