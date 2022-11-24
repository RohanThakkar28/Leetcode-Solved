class Solution {
public:
    bool ye=false;
    void sol(int i,int j,int k,vector<vector<char>>&b,vector<vector<bool>>&vis,string &word){
        //int n=word.size();
        if(k==word.size()){
            ye=true;
            return;
        }
        int n=b.size();
        int m=b[0].size();
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(vis[i][j]){
            return;
        }
        if(word[k]!=b[i][j]){
            return;
        }
        vis[i][j]=true;
        sol(i+1,j,k+1,b,vis,word);
        sol(i-1,j,k+1,b,vis,word);
        sol(i,j+1,k+1,b,vis,word);
        sol(i,j-1,k+1,b,vis,word);
        vis[i][j]=false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ye){
                    break;
                }
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                sol(i,j,0,board,vis,word);
            }
            if(ye){
                break;
            }
        }
        if(ye){
            return true;
        }
        else{
            return false;
        }
        
    }
};