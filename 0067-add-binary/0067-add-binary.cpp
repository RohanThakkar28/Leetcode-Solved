class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
            string temp=a;
            a=b;
            b=temp;
        }
        int n=a.size();
        int m=b.size();
        reverse(a.begin(),a.end());
        
        reverse(b.begin(),b.end());
        int carry=0;
        string ans="";
        int i=0;
        
        while(i<m){
            int sum=(a[i]-'0')+(b[i]-'0')+carry;
            if(sum==1){
                ans+='1';
                carry=0;
                
            }
            else if(sum==2){
                ans+='0';
                carry=1;
            }
            else if(sum==3){
                ans+='1';
                carry=1;
            }
            else if(sum==0){
                ans+='0';
                carry=0;
            }
            i++;
        }
        while(i<n){
            if(carry==1){
                if(a[i]=='1'){
                    ans+='0';
                    carry=1;
                }
                else{
                    ans+='1';
                    carry=0;
                }
            }
            else{
                ans+=a[i];
            }
            i++;
        }
        if(carry==1){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};