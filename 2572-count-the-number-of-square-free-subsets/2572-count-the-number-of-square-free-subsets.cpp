#define ll long long int
class Solution {
public:
    vector<int>f;
    
    vector<int>c;
    int mod=1e9+7;
    ll ans=0;
    void sol(int i,vector<int>&arr,vector<int>&fact,vector<int>&num){
        int n=arr.size();
        
        if(i==n){
            ll r=1;
            for(int j=1;j<=30;j++){
            
                if(num[j]>0){
                    r*=(ll)c[j];
                    r%=mod;
                }
            }
         //   cout<<r<<endl;
            ans+=r;
            ans%=mod;
        }
        else{
            //int ans=0;
            bool ye=true;
            for(int j=0;j<f.size();j++){
                if(arr[i]%f[j]==0 && fact[f[j]]>0){
                    ye=false;
                }
            }
            if(ye){
                
                for(int j=0;j<f.size();j++){
                    if(arr[i]%f[j]==0){
                        fact[f[j]]++;
                        
                    }
                }
                num[arr[i]]++;
                sol(i+1,arr,fact,num);
                num[arr[i]]--;
                for(int j=0;j<f.size();j++){
                    if(arr[i]%f[j]==0){
                        fact[f[j]]--;
                        
                    }
                }
                
                sol(i+1,arr,fact,num);
                
                
                
                
                
                
            }
            else{
                sol(i+1,arr,fact,num);
                
            }
            
        }
        
    }
    int squareFreeSubsets(vector<int>& nums) {
        vector<int>f1{2,3,5,7,11,13,17,19,23,29};
        f=f1;
        c.resize(31,0);
        for(auto i:nums){
            c[i]++;
        }
        vector<int>arr;
        vector<int>na{1,4,8,9,12,16,18,20,24,25,27,28};
       // na.push_back({4,8,9,12,16,18,20,24,25,27,28});
        for(int i=1;i<=30;i++){
            if(c[i]>0){
                bool ye=false;
                for(int j=0;j<na.size();j++){
                    if(na[j]==i){
                        ye=true;
                    }
                }
                if(!ye){
                    arr.push_back(i);
                }
            }
        }
       // cout<<arr.size()<<endl;
        
        vector<int>fact(31,0);
        vector<int>num(31,0);
        sol(0,arr,fact,num);
        for(int i=0;i<c[1];i++){
            ans*=2;
            ans%=mod;
        }
       
        return ans-1;
        
        
        
        
        
        
    }
};