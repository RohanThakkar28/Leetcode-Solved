class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>c;
        int ans=0;
        for(int i=0;i<words.size();i++){
            string tmp=words[i];
            reverse(tmp.begin(),tmp.end());
            if(c[tmp]>0){
                
                c[tmp]--;
                ans+=4;
            }
            else{
                c[words[i]]++;
            }
            
        }
        for(auto i:c){
            if(i.second>0){
                string w=i.first;
                string tmp=w;
                reverse(tmp.begin(),tmp.end());
                if(tmp==w){
                    ans+=2;
                    break;
                }
                
            }
        }
        return ans;
        
        
    }
};