class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        
        return a.second>b.second;
    }
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>>arr;
        int n=pt.size();
        for(int i=0;i<n;i++){
            arr.push_back(make_pair(pt[i],gt[i]));
        }
        sort(arr.begin(),arr.end(),comp);
        int maxt=0;
        int lastp=0;
        for(int i=0;i<n;i++){
          //  cout<<arr[i].first<<" "<<arr[i].second<<endl;
            maxt=max(maxt,lastp+arr[i].first+arr[i].second);
            lastp=lastp+arr[i].first;
        }
        return maxt;
    }
};