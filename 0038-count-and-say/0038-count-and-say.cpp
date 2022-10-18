class Solution {
public:
    string countAndSay(int n) {
        string ans;
        vector<string>temp;
        temp.push_back("1");
        for(int i=1;i<n;i++){
            string t=temp[i-1];
            string neww="";
           // cout<<t<<endl;

            for(int j=0;j<t.size();j++){
                int count=1;
                
                while(j+1<t.size() && t[j]==t[j+1]){
                    j++;
                    count++;
                }
                if(j==t.size()-1 && t.size()>1){
                    if(t[t.size()-1]==t[t.size()-2]){
        
                    }
                    else{
                        count=1;
                    }
                }
                
             //   cout<<count<<" "<<j<<" "<<t[j]<<endl;
                neww+=to_string(count)+t[j];
              //  cout<<neww<<" "<<j<<endl;
            }
            temp.push_back(neww);
        }
        return temp[temp.size()-1];
    }
};