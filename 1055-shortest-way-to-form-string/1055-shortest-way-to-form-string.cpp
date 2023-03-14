class Solution {
public:
    int shortestWay(string s, string t) {
        map<char,vector<int>>m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end()){
                return -1;
            }
        }
        int i=-1;
        int ans=0;
        for(int j=0;j<t.size();j++){
            vector<int>a=m[t[j]];
         //   cout<<i<<endl;
            auto id=lower_bound(a.begin(),a.end(),i)-a.begin();
           // cout<<i<<" "<<id<<" n"<<endl;
            if(id==a.size()){
                ans++;
                i=-1;
                id=lower_bound(a.begin(),a.end(),i)-a.begin();
               /// cout<<id<<" h"<<endl;
                
            }
            //cout<<id<<endl;
           
            i=a[id]+1;
            
            
        }
        return ans+1;
    }
};