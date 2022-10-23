#define ll long long int
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i;j<n;j++){
                g=gcd(nums[j],g);
                if(g==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};