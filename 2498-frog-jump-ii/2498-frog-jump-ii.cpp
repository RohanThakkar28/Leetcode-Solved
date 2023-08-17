class Solution {
public:
    bool ch(vector<int>&a,int m){
        int n=a.size();
        vector<bool>vis(n,false);
        int i=0;
        while(i!=n-1){
            int j=i+1;
            while(j<n && a[j]-a[i]<=m){
                j++;
            }
            j--;
            if(i==j){
                return false;
            }
            i=j;
            vis[i]=true;
        }
        vis[n-1]=false;
        i=n-1;
        while(i>0){
            int j=i-1;
            int id=i;
            while(j>=0 && a[i]-a[j]<=m){
                if(vis[j]==false){
                    id=j;
                }
                j--;
            }
            if(id==i){
                return false;
            }
            i=id;
        }
        return true;
        
    }
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int l=1;
        int r=stones[n-1]-stones[0];
        vector<int>a;
        int m=l+(r-l)/2;
        int ans=r;
        while(l<=r){
            m=l+(r-l)/2;
            a=stones;
            //cout<<m<<" ";
            if(ch(a,m)){
               // cout<<"1"<<endl;
                ans=m;
                r=m-1;
                
                
            }
            else{
               // cout<<"0"<<endl;
                l=m+1;
            }
            
        }
        return ans;
        
    }
};