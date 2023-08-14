class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n=s.size();
        int curr=0;
        char op='+';
       // cout<<n<<endl;
        
        for(int i=0;i<n;i++){
         //   cout<<s[i]<<" "<<i<<endl;
            if(s[i]==' ' && i!=n-1){
                
                continue;
            }
            if(isdigit(s[i])){
                curr=curr*10+(s[i]-'0');
            }
            if(!isdigit(s[i]) || i==n-1){
                ///cout<<i<<" "<<op<<endl;
                if(op=='+'){
                    st.push(curr);
                }
                else if(op=='-'){
                    st.push(-curr);
                }
                else if(op=='*'){
                    int t=st.top();
                    st.pop();
                    t*=curr;
                    st.push(t);
                }
                else if(op=='/'){
                     int t=st.top();
                    st.pop();
                    t/=curr;
                    st.push(t);
                }
                op=s[i];
                curr=0;
            }
            
        }
        int ans=0;
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
        
    }
};