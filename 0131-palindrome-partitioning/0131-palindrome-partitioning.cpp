class Solution {
public:
    bool ispalin(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        if(s==s1){
            
            return true;
        }
        return false;
    }
    vector<vector<string>>ans;
    
    void sol(int i,string s,vector<string>&temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        string s1="";
        for(int j=i;j<s.size();j++){
            s1+=s[j];
            if(ispalin(s1)){
             //   cout<<s1<<" "<<j<<endl;
                temp.push_back(s1);
                sol(j+1,s,temp);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        sol(0,s,temp);
        return ans;
        
    }
};