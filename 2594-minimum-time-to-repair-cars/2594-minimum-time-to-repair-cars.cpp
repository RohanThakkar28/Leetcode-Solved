#define ll long long int
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans=1e18;
        ll l=1;
        ll r=1e18;
        while(l<=r){
            ll m=l+(r-l)/2;
            ll c=0;
            for(int i=0;i<ranks.size();i++){
                c+=sqrt(m/ranks[i]);
            }
            if(c>=cars){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};