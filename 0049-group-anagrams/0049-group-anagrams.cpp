class Solution {
public:
    static int cmp(pair<int,string> &a,pair<int,string> &b){
        return a.second<b.second;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp;
        int n=strs.size();
        map<int,string>ans;
        for(int i=0;i<n;i++){
            string s;
            s=strs[i];
            sort(s.begin(),s.end());
            ans[i]=s;
        }
        vector<pair<int,string>>anss(ans.begin(),ans.end());
        sort(anss.begin(),anss.end(),cmp);
        vector<vector<string>>aa;
        vector<string>bb;
        string prev="";
        int i=0;
        for (auto& it : anss) {
            if(i==0){
                bb.push_back(strs[it.first]);
                prev=it.second;
                i++;
            }
            else if(it.second==prev){
                bb.push_back(strs[it.first]);
                
            }
            else{
                aa.push_back(bb);
                bb.clear();
                bb.push_back(strs[it.first]);
                prev=it.second;
              //  cout<<prev<<" "<<endl;
            }

            
            
        }
        if(!bb.empty()){
            aa.push_back(bb);
        }
        
        return aa;
        
    }
};