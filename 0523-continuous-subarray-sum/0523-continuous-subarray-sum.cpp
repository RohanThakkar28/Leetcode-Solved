#define ll long long int
static bool comp(pair<ll,ll>&a,pair<ll,ll>&b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
class Solution {
public:
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
    
        ll sum=0;
        map<ll,vector<ll>>vec;
        vec[0].push_back(-1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=k;
            vec[sum].push_back(i);
           // vec.push_back({sum,i});
            //c[sum]++;
        }
        for(auto it:vec){
            vector<ll>tmp=it.second;
            if(tmp.size()>=3){
                return true;
            }
            if(tmp.size()==2){
                if(tmp[1]-tmp[0]>1){
                    return true;
                }
            }
        }
        return false;
        ///sort(vec.begin(),vec.end(),comp);
        
        
    }
};