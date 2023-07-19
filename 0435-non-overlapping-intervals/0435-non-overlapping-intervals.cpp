class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        int n=I.size();
        sort(I.begin(),I.end(),comp);
        int ans=0;
        int l=-1;
        int r=-1;
        l=I[0][0];
        r=I[0][1];
        ans++;
        for(int i=1;i<n;i++){
            if(I[i][0]>=r){
                l=I[i][0];
                r=I[i][1];
                ans++;
            }
            if(I[i][1]<=r){
                r=I[i][1];
            }
        }
        return n-ans;
        
    }
};