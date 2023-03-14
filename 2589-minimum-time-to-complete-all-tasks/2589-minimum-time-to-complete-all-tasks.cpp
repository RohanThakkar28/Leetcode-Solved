class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        map<int,int>c;
        int m=0;
        for(int i=0;i<tasks.size();i++){
            m=max(m,tasks[i][1]);
        }
        
        sort(tasks.begin(),tasks.end(),comp);
       
        map<int,int>vis;
        int ans=0;
        for(int i=0;i<n;i++){
            int l=tasks[i][0];
            int r=tasks[i][1];
            int t=tasks[i][2];
          //  cout<<l<<" "<<r<<" "<<t<<endl;
            int j=r;
            for(int k=r;k>=l;k--){
               // cout<<k<<endl;
                if(vis[k]>0){
                    t--;
                }
            }
            //cout<<"hi"<<endl;
            while(j>=l && t>0){
                if(vis[j]>0){
                    
                  //  t--;
                    j--;
                    continue;
                }
                else{
                  //  cout<<j<<endl;
                    ans++;
                    vis[j]++;
                    t--;
                }
                j--;
            }
        }
        return ans;
        
    }
};
