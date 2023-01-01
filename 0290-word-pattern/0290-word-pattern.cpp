class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int>a;
        vector<int>b;
        map<char,int>c;
        int j=1;
        for(int i=0;i<pattern.size();i++){
            if(c.find(pattern[i])==c.end()){
                c[pattern[i]]=j;
                j++;
            }
            a.push_back(c[pattern[i]]);
        }
        string tmp="";
        s+=' ';
        map<string,int>c1;
        j=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(c1.find(tmp)==c1.end()){
                    c1[tmp]=j;
                    j++;
                
                    
                }
                b.push_back(c1[tmp]);
                tmp="";
                continue;
                
            }
            tmp+=s[i];
        }
        return a==b;
        
    }
};