class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int maxy=0;
        for(int i=0;i<w.size();i++){
            maxy=max(maxy,w[i]);
        }
        int l=maxy;
        int r=1e9;
        int ans;
        int n=w.size();
        while(l<=r){
            int m=l+(r-l)/2;
            int c=1;
            int curr=0;
            bool ye=true;
            for(int i=0;i<n;i++){
                
                if(curr+w[i]>m){
                    c++;
                    curr=w[i];
                }
                else{
                    curr+=w[i];
                }
                
            }
            if(c<=days){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
            
            
            
        }
        return ans;
        
    }
};