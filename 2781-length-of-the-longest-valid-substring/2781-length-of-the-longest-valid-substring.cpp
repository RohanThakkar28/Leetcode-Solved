class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string>s;
        for(auto i:forbidden){
            s.insert(i);
        }
        int i=0;
        string ans="";
        int maxy=0;
        int n=word.size();
        while(i<n){
            //cout<<ans<<" "<<i<<endl;
            ans+=word[i];
            
            bool ch=true;
            string tmp="";
            for(int j=ans.size()-1;j>=max(0,(int)(ans.size()-10));j--){
                tmp=ans[j]+tmp;
                //cout<<tmp<<endl;
                if(s.find(tmp)!=s.end()){
                    ch=false;
                    
                    ans=tmp.substr(1);
                    break;
                }
            }
            //cout<<ans<<endl;
            maxy=max(maxy,(int)ans.size());
            i++;
            
        }
        return maxy;
        
        
    }
};