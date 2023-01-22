#define ll long long int
class Solution {
public:
    ll cost(int i,vector<int>&nums,int k,vector<vector<int>>&pre,vector<ll>&dp){
        int n=nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        ll ans=1e18;
        for(int j=i;j<n;j++){
            ll a=(ll)k+(ll)pre[i][j]+(ll)cost(j+1,nums,k,pre,dp);
            ans=min(ans,a);
            
        }
        return dp[i]=ans;
        
    }
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>pre(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            unordered_map<int,int>c;
            int curr=0;
            for(int j=i;j<n;j++){
                c[nums[j]]++;
                if(c[nums[j]]==2){
                    curr++;
                }
                if(c[nums[j]]>1){
                    curr++;
                }
                pre[i][j]=curr;
                
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cout<<pre[i][j]<<" ";
            }
            cout<<endl;
        }*/
        vector<ll>dp(n,-1);
        ll ans=cost(0,nums,k,pre,dp);
        return ans;
    }
};