class Solution {
public:
    bool ye=false;
    int ans=1e9;
    void sol(int i,vector<string>&bank,string curr,vector<bool>&vis,string tar,int c){
        if(i!=-1 && vis[i]){
            return;
        }
        if(i!=-1 && bank[i]==tar){
            ans=min(c,ans);
            return;
        }
        if(i!=-1){

            vis[i]=true;
            
        }
        for(int j=0;j<bank.size();j++){
            if(vis[j]){
                continue;
            }
            int dif=0;
            
            for(int k=0;k<8;k++){
                dif+=(curr[k]!=bank[j][k]);
            }
            if(dif==1){
                
                sol(j,bank,bank[j],vis,tar,c+1);
                
            }
        }
        if(i!=-1){

            vis[i]=false;
        }
        
    }
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool>vis(bank.size(),false);
        sol(-1,bank,start,vis,end,0);
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};