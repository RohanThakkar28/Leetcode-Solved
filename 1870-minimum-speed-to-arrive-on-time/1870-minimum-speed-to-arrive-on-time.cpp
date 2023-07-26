class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
       // sort(dist.begin(),dist.end());
        //reverse(dist.begin(),dist.end());
        int l=1;
        int r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            double h=0;
            for(int i=0;i<dist.size();i++){
                if(i==dist.size()-1){
                    h+=(dist[i]/(mid*1.0));
                    continue;
                }
                if(dist[i]%mid==0){
                    h+=(dist[i]/mid);
                }
                else{
                    h+=(dist[i]/mid)+1;
                }
                
            }
            //cout<<mid<<" "<<h<<" "<<hour<<endl;
            if(h<=hour){
                ans=mid;
                r=mid-1;
                
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
        
    }
};