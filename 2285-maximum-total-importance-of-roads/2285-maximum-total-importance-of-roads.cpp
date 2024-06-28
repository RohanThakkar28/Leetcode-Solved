class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>c;
        for(int i=0;i<roads.size();i++){
            c[roads[i][0]]++;
            c[roads[i][1]]++;
        }
        vector<int>a;
        for(auto i:c){
            a.push_back(i.second);
        }
        sort(a.begin(),a.end());
        long long ans=0;
        int z=n;
        for(int i=a.size()-1;i>=0;i--){
            ans+=(long long)(z)*a[i];
            z--;
        }
        return ans;
        
    }
};