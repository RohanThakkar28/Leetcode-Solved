#define ll long long int
class Solution {
public:
    int minMoves(vector<int>& a, int k) {
        
        vector<ll>pref(2*k+2,0);
        ll n=a.size();
        vector<ll>c(2*k+2,0);
        for(int i=0;i<n/2;i++){
            ll a1=a[i];
            ll a2=a[n-i-1];
            c[a1+a2]++;
            ll l=min(a1,a2)+1;
            ll r=max(a1,a2)+k;
            pref[l]++;
            pref[r+1]--;
        }
        for(int i=1;i<=2*k;i++){
            pref[i]+=pref[i-1];

        }
        ll ans=n;
        for(int i=2;i<=2*k;i++){
            ll c0=c[i];
            ll c1=pref[i]-c0;
            ll c2=n/2-c0-c1;
            ans=min(ans,c1+2*c2);

        }
        return ans;

        
    }
};