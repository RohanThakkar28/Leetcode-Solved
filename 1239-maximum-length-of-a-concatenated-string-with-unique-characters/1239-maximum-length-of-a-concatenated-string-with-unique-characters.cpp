#define ll long long int
class Solution {
public:
    ll ans=0;
    void sol(vector<string>&arr,ll mask,int i){
       // cout<<i<<endl;
        int n=arr.size();
        if(i==n){
            ll len=__builtin_popcountll(mask);
            ans=max(ans,len);
            return;
        }
        string word=arr[i];
        ll currmask=0;
        bool ye=true;
        for(auto ch:word){
            if((1<<(ch-'a')&(mask))){
                ye=false;
                break;
            }
            if((1<<(ch-'a')&(currmask))){
                ye=false;
                break;
            }
            currmask|=(1<<(ch-'a'));
            
            
            
        }
        if(ye){
            sol(arr,(mask|currmask),i+1);
            
            sol(arr,(mask),i+1);
        }
        else{
            sol(arr,mask,i+1);
        }
    }
    int maxLength(vector<string>& arr) {
      
        
        sol(arr,0,0);
        return ans;
        
    }
};