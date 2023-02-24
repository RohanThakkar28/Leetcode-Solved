class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        }
    
        
    };
     
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>q;
        int m=0;
        for(int i=0;i<n;i++){
            
            int c=nums[i];
            if(c%2==1){
                q.push({c,2*c});
                m=max(m,c);
                continue;
            }
            while(c%2==0){
                c=c/2;
            }
            m=max(m,c);
            //cout<<c<<endl;
            q.push({c,nums[i]});
        }
        int ans=m-q.top().first;
       // cout<<ans<<endl;
      //  cout<<q.top().first<<endl;
        while(true){
            if(q.top().first==q.top().second){
               // cout<<"hi"<<endl;
                break;
            }
            auto it=q.top();
            q.pop();
            m=max(m,2*it.first);
            q.push({2*it.first,it.second});
            ans=min(m-q.top().first,ans);
        }
        return ans;
        
        
        
       
    }
};