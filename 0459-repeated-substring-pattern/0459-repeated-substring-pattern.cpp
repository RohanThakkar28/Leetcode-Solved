class Solution {
public:
    bool ch(string &s,int d){
        string chs="";
        for(int i=0;i<d;i++){
            chs+=s[i];
        }
        
        int i=d;
        //cout<<chs<<" "<<d<<endl;
        while(i<s.size()){
            chs+=s[i-d];
            i++;
        }
        //cout<<chs<<" "<<d<<endl;
        return (s==chs);
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=sqrt(n);i++){
            cout<<n/i<<" "<<i<<endl;
            if(n%i==0){
                if(n/i!=n && ch(s,n/i)){
                    return true;
                }
                if(i!=n && ch(s,i)){
                    return true;
                }
                
            }
        }
        return false;
        
    }
};