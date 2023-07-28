class Solution {
public:
            vector<string>lessthan20{"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    
    vector<string>tens{"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety ","Hundred "};
    
    
    vector<string>thousand{"Thousand ","Million ","Billion "};

    
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        string ans="";
        vector<string>a;
        
        int j=-1;
        while(num>0){
            ans="";
            int nu=num%1000;
           // cout<<nu<<endl;
            num/=1000;
            if(nu==0){
                a.push_back(ans);
                j++;
                continue;
            }
            if(nu<20){
                ans=ans+lessthan20[nu];
                a.push_back(ans);
                //cout<<nu<<" "<<ans<<endl;
                j++;
                continue;
            }
            if(nu>=100){
               // cout<<nu<<endl;
                ans=ans+lessthan20[nu/100]+"Hundred ";
               // cout<<ans<<endl;
                int last2=nu%100;
                if(last2<20){
                    ans=ans+lessthan20[last2];
                    
                }
                else{
                 //   cout<<"hi"<<endl;
                    ans=ans+tens[last2/10-2]+lessthan20[last2%10];
                }
                j++;
            }
            else{
                ans=ans+tens[nu/10-2]+lessthan20[nu%10];
            }
           // cout<<nu<<" "<<ans<<endl;
            a.push_back(ans);
            ans="";
        }
        j=a.size()-2;
     //   cout<<a.size()<<endl;
        reverse(a.begin(),a.end());
        ans="";
        for(int i=0;i<a.size();i++){
          //  cout<<a[i]<<endl;
            ans+=a[i];
            if(j>=0 && a[i].size()>0){
                ans+=thousand[j];
            }
            j--;
        }
        if(ans[ans.size()-1]==' '){
            
            ans.pop_back();
            
        }
            

        return ans;
        
    }
};