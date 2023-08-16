class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int>ans;
        int n=s.size();
      //  cout<<n<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int>left=diffWaysToCompute(s.substr(0,i));
                
                vector<int>right=diffWaysToCompute(s.substr(i+1));
                
                if(s[i]=='+'){
                    for(auto j:left){
                        for(auto k:right){
                            ans.push_back(j+k);
                        }
                    }
                }
                if(s[i]=='-'){
                    for(auto j:left){
                        for(auto k:right){
                            ans.push_back(j-k);
                        }
                    }
                    
                }
                if(s[i]=='*'){
                    for(auto j:left){
                        for(auto k:right){
                            ans.push_back(j*k);
                        }
                    }
                    
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(s));
        }
        
        
        
        
        return ans;
    }
};