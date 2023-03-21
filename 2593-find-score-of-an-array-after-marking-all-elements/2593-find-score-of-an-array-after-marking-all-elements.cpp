#define ll long long int
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<n;i++){
            q.push({nums[i],i});
            
        }
        ll ans=0;
        map<ll,ll>m;
        while(q.size()>0){
            auto t=q.top();
            q.pop();
            if(m.find(t.second)==m.end()){
                ans+=(ll)t.first;
                m[t.second]++;
                
                m[t.second-1]++;
                m[t.second+1]++;
            }
            
            
        }
        return ans;
    
    }
};