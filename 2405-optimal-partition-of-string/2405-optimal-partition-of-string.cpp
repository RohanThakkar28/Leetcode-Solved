class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        int n=s.size();
        map<char,int>a;
        for(int i=0;i<n;i++){
            if(a.find(s[i])!=a.end()){
                //cout<<i<<endl;
                ans++;
                a.clear();
                
            }
            a[s[i]]++;
            
        }
        return ans;
        
    }
};