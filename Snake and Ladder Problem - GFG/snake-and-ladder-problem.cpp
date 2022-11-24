//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sol(int i,map<int,int>&s,vector<int>&dp,vector<bool>&vis){
        if(i>30){
            return 1e9;
        }
        if(i==30){return 0;}
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;
        if(s.find(i)!=s.end()){
            if(vis[i]){
                return 1e9;
            }
            vis[i]=true;
            return dp[i]=min(ans,sol(s[i],s,dp,vis));
            vis[i]=false;
        }
       // int ans=1e9;
        for(int j=1;j<=6;j++){
            int c=1+sol(i+j,s,dp,vis);
            
            ans=min(ans,c);
        }
        return dp[i]=ans;
    }
    int minThrow(int N, int arr[]){
        // code here
        map<int,int>s;
        for(int i=0;i<2*N;i+=2){
           // cout<<i<<endl;
            s[arr[i]]=arr[i+1];
        }
        vector<int>dp(31,-1);
        vector<bool>vis(31,false);
        int ans=sol(1,s,dp,vis);
       /* for(int i=1;i<=30;i++){
            cout<<dp[i]<<" ";
        }*/
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends