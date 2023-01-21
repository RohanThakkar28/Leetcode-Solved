class Solution {
public:
    bool val(string s){
        string a="";
       // cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            

            if(s[i]=='.'){
                if(a==""){
                    return false;
                }
                if(a[0]=='0' && a.size()>1){
                    return false;
                }
                
                if(a.size()>3){
                    return false;
                }
                int num=stoi(a);
                if(num>=0 && num<=255){
                    
                }
                else{
                    return false;
                }
                a="";
            }
        
            else{
                a.push_back(s[i]);
            }
            
            
        }
        if(a.size()==0){
            return false;
        }
        if(a[0]=='0' && a.size()>1){
            return false;
        }
        if(a.size()>3){
            return false;
        }
        int num=stoi(a);
        if(num>=0 && num<=255){
                    
        }
        else{
                    return false;
        }
        return true;
        
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    string a="";
                    for(int id=0;id<n;id++){
                        if(id==i || id==j || id==k){
                            a.push_back('.');
                        }
                        a.push_back(s[id]);
                        
                    }
                    if(val(a)){
                            ans.push_back(a);
                    }
                }
            }
        }
        return ans;
    }
};