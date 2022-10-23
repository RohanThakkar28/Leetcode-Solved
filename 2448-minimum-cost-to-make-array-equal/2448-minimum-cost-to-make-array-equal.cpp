#define ll long long int
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<vector<int>>a;
        for(int i=0;i<n;i++){
            vector<int>tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(cost[i]);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end(),comp);
        int id=0;
        int l=a[0][0];
        int r=a[n-1][0];
        vector<ll>pref;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=(ll)a[i][1];
            pref.push_back(sum);
        }
        sum=0;
        vector<ll>suff;
        for(int i=n-1;i>=0;i--){
            sum+=(ll)a[i][1];
            suff.push_back(sum);
        }
        map<int,int>c;
        for(int i=0;i<n;i++){
            c[nums[i]]++;
        }
        ll curr=0;
        for(int i=0;i<n;i++){
            curr+=(ll)(a[i][0]-a[0][0])*(a[i][1]);
            
            
        }
        
        ll ans=curr;
        while(id<n && a[id][0]==l){
            id++;
        }
        if(id==n){
            return ans;
        }
        l++;
        reverse(suff.begin(),suff.end());
        
        for(int k=l;k<=r;k++){
        //    cout<<id<<" "<<k<<endl;
            if(k==a[id][0]){
                curr+=pref[id-1];
                curr-=suff[id];
            //    cout<<pref[id-1]<<" "<<suff[id]<<endl;
                while(id<n && a[id][0]==k){
                    id++;
                }
                ans=min(ans,curr);
                
                
                
            }
            else{
                curr+=pref[id-1];
                curr-=suff[id];
                ans=min(ans,curr);
            }
            
            
            
        }
        return ans;
        
        
        
    }
};