#define ll long long int
class Solution {
public:
    long long maxPower(vector<int>& stations, int r1, int k) {
        int n=stations.size();
        vector<ll>a(n,0);
        vector<ll>b(n,0);
        a[0]=stations[0];
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+stations[i];
            if(i-r1-1>=0){
                a[i]-=stations[i-r1-1];
            }
            
        }
        b[n-1]=stations[n-1];
        for(int i=n-2;i>=0;i--){
            b[i]+=b[i+1]+stations[i];
            if(i+r1+1<n){
                b[i]-=stations[i+r1+1];
            }
            
            
        }
        ll l=1e18;
        for(int i=0;i<n;i++){
            a[i]+=(b[i]-stations[i]);
            //cout<<a[i]<<" ";
            l=min(a[i],l);
        }
      //  cout<<l<<endl;
        ll r=1e18;
        ll ans=l;
        while(l<=r){
            ll m=l+(r-l)/2;
            ll c=0;
            vector<int>tmp(n,0);
            ll curr=0;
            bool ye=true;
            for(int i=0;i<n;i++){
                curr-=tmp[i];
                if(curr+a[i]<m){
                    ll diff=(m-a[i]-curr);
                    curr+=diff;
                    if(i+2*r1+1<n){
                        tmp[i+2*r1+1]+=diff;
                        
                        
                    }
                    c+=diff;
                    
                }
                
            }
            if(k-c<0){
                
                ye=false;

            }
            if(ye){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
          
            
        }
        
        
        return ans;
        
    }
};