class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>s;
        int n=nums.size();
        for(int i=x;i<n;i++){
            s.insert(nums[i]);
        }
        int j=x;
        int i=0;
        int ans=1e9;
    //    cout<<"hi"<<endl;
        while(j<n){
           // cout<<"hi"<<endl;
           // cout<<i<<" "<<j<<endl;
           // cout<<s.size()<<endl;
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end()){
                ans=min(ans,abs(*it-nums[i]));
            }
            if(it!=s.begin()){
                 it--;
                if(it!=s.end()){
                    ans=min(ans,abs(*it-nums[i]));
                }
                
            }
            //cout<<"h1"<<endl;
            auto tmp=s.find(nums[j]);
            
           // cout<<"h1"<<endl;
            if(tmp!=s.end()){
                
                
            s.erase(tmp);
                
            }
           
            j++;
            i++;
        }
        return ans;
        
    }
};