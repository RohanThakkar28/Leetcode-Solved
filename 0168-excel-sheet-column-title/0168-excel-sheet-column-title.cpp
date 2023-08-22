class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        map<int,char>c;
        for(int i=0;i<26;i++){
            c[i]=((i)+'A');
        }
      
        while(columnNumber>0){
            //cout<<columnNumber<<endl;
            columnNumber-=1;
            ans+=c[columnNumber%26];
            columnNumber/=26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};