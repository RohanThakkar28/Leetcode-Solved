class Solution {
public:
    int uniqueLetterString(string s) {
        map<char,vector<int>>c;
        int n=s.size();
        for(int i=0;i<n;i++){
            c[s[i]].push_back(i);
        }
        int ans=0;
        for(auto z:c){
            vector<int>a=z.second;
            if(a.size()==0){
                continue;
            }
            a.push_back(n);
            a.insert(a.begin(),-1);
            for(int i=1;i<a.size()-1;i++){
                ans+=(a[i]-a[i-1])*(a[i+1]-a[i]);
            }
        }
        return ans;
        
    }
};