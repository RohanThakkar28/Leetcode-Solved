class Solution {
public:
    
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& z) {
        vector<pair<int,int>>a;
        int n=p.size();
        for(int i=0;i<n;i++){
            a.push_back({p[i],z[i]});
        }
        sort(a.begin(),a.end(),comp);
        priority_queue<pair<int,int>>q;
        int i=0;
        int t=0;
        int ans=0;
        int c=w;
        while(t<k){
          //  cout<<a[0].second<<" "<<c<<endl;
            while(i<n && a[i].second<=c){
            
                q.push({a[i].first,a[i].second});
                i++;
            }
           // cout<<i<<endl;
            if(q.size()>0){
                t++;
                ans+=q.top().first;
                c+=q.top().first;
                q.pop();
                //cout<<ans<<endl;
                
                
            }
            else{
                //cout<<"hi"<<endl;
                break;
            }
            
        }
     //   cout<<c<<endl;
        return c;
        
    }
};