class Solution {
public:
    vector<string>ans;
    void sol(int i,int j,string &s,vector<vector<bool>>&dp,vector<string>&tmp){
        int n=s.size();
        if(j==n){
            if(i==n){
                string t1="";
                for(auto k:tmp){
                    t1+=k;
                    t1+=" ";
                }
                t1.pop_back();
                ans.push_back(t1);
            }
            return;
        }
        if(dp[i][j]){
            //cout<<i<<" "<<j<<endl;
           // cout<<s.substr(i,j-i+1)<<endl;
            tmp.push_back(s.substr(i,j-i+1));
            sol(j+1,j+1,s,dp,tmp);
            tmp.pop_back();
            sol(i,j+1,s,dp,tmp);
            
        }
        else{
            sol(i,j+1,s,dp,tmp);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=i;j<n;j++){
                tmp+=s[j];
                if(st.find(tmp)!=st.end()){
                    dp[i][j]=true;
                }
            }
        }
        vector<string>tmp;
        sol(0,0,s,dp,tmp);
        return ans;
        
    }
};