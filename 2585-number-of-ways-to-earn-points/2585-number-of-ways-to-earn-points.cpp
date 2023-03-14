#define ll long long int;
const int mod=1e9+7;
class Solution {
public:
    int sol(int i,vector<vector<int>>&arr,int tar,vector<vector<int>>&dp){
       /// cout<<tar<<" "<<i<<endl;
        int n=arr.size();
        if(tar==0){
        //    cout<<i<<endl;
            return 1;
        }
        if(i==n || tar<0){
            return 0;
        }
        int ans=0;
        if(dp[i][tar]!=-1){
            return dp[i][tar];
        }
        for(int j=0;j<arr[i].size();j++){
            int a=sol(i+1,arr,tar-arr[i][j],dp);
            a%=mod;
            ans+=a;
            ans%=mod;
        }
        return dp[i][tar]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>>arr;
        for(int i=0;i<types.size();i++){
            int a=types[i][0];
            int b=types[i][1];
            vector<int>v;
            
            for(int j=0;j<=a;j++){
                v.push_back(j*b);
                
                
            }
            arr.push_back(v);
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
       /* for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int ans=sol(0,arr,target,dp);
        return ans;
        
    }
};