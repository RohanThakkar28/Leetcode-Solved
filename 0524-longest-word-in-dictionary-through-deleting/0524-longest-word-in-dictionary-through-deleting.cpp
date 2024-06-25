class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans="";
        for(int i=0;i<d.size();i++){
            string tmp=d[i];
            int j=0;
            int k=0;
            while(j<tmp.size() && k<s.size()){
                if(tmp[j]==s[k]){
                    j++;
                    k++;
                }
                else{
                    k++;
                }
            }
            if(j==tmp.size()){
                if(ans.size()<tmp.size()){
                    ans=tmp;
                }
                else if(ans.size()==tmp.size()){
                    if(tmp<ans){
                        ans=tmp;
                    }
                }
            }
        }
        return ans;
        
        
    }
};