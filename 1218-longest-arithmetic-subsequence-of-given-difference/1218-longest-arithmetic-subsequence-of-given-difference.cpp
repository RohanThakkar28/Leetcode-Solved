class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>c;
        int maxy=1;
        for(int i=0;i<arr.size();i++){
            c[arr[i]+difference]=1+c[arr[i]];
            maxy=max(maxy,c[arr[i]+difference]);
        }
        return maxy;
        
    }
};