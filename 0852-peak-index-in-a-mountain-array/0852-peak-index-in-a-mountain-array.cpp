class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1;
        int n=arr.size();
        int r=n-2;
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
                ans=m;
                break;
            }
            if(arr[m]<arr[m+1]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};