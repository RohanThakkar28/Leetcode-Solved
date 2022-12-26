#define ll long long int
class Solution {
public:
    const int mod=1e9+7;
    long long binpow(long long a, long long b) {
        if (b == 0)
            return 1;
        long long res = binpow(a, b / 2);
        if (b % 2){
            ll x=((res%mod) * (res%mod))%mod;
            return ( x* (a%mod))%mod;
            
        }
        else
            return ((res%mod) * (res%mod)%mod)%mod;
    }
    
    int countAnagrams(string s) {
        vector<string>a;
        string tmp="";
        int n=s.size();
        int m=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                a.push_back(tmp);
                int ss=tmp.size();
                m=max(m,ss);
                tmp="";
            }
            else{
                tmp+=s[i];
            }
        }

        a.push_back(tmp);
        m=max(m,(int)tmp.size());
        vector<ll>dp(m+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=m;i++){
            dp[i]=(ll)(i)*dp[i-1];
            dp[i]%=mod;
        }
        ll ans=1;
        for(int i=0;i<a.size();i++){
            vector<int>mp(26,0);
            ll tot=dp[a[i].size()];
            for(int j=0;j<a[i].size();j++){
                mp[a[i][j]-'a']++;
            }
            ll div=1;
            for(int j=0;j<26;j++){
                div*=dp[mp[j]];
                div%=mod;
                
            }
           // cout<<tot<<" "<<div<<endl;
            ll f=tot*(binpow(div,mod-2));
            f%=mod;
            ans*=(ll)f;
            ans%=mod;
            
        }
        return ans%mod;
        
        
    }
};