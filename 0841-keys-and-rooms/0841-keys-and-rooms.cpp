class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool ye=true;
        int n=rooms.size();
        vector<bool>vis(n,false);
        
        
        vector<bool>key(n,false);
        key[0]=true;
        while(true){
            int c=0;
            int h=0;
            
            for(int i=0;i<n;i++){
                if(vis[i]){

                    c++;
                    continue;
                }
                if(key[i]){
                    vis[i]=true;
                    h++;
                  //  cout<<i<<endl;
                    
                    for(int j=0;j<rooms[i].size();j++){
                        
                        if(!key[rooms[i][j]]){
                            key[rooms[i][j]]=true;
                            
                        }
                    }
                    
                    
                }
                
            }
      //   cout<<c<<endl;
            if(c==n){
                break;
            }
            if(h==0){
                ye=false;
                break;
            }
        }
        return ye;
        
    }
};