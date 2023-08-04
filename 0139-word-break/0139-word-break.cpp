class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=wordDict.size();
        int n=s.size();
        bool dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=false;
            }
            
        }
        int l=0;
      //  cout<<s.substr(4,4)<<endl;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n-i;j++){
              
                int y=j+i-1;
                string str=s.substr(j,i);
                
                int pos=0;
                for(int z=0;z<len;z++){
                    if(wordDict[z]==str){
                        pos=1;
                  //      cout<<str;
                        break;
                    }
                }
                if(pos==1){
                    dp[j][y]=1;
                }
                else{
                    
                    
                        int spilt=1;
                        
                        for(int q=spilt;q<=str.size();q++){
                            if(dp[j][j+q-1]==1 && dp[j+q][j+i-1]==1){
                                dp[j][y]=1;
                                break;
                            }
                            
                        }
                        //dp[j][y]=false;
                    }
                
                
                
                
            
            
                
            }
        }
       // cout<<dp[]
       /* for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][n-1];
    }
};
                        
                    
                                    
               