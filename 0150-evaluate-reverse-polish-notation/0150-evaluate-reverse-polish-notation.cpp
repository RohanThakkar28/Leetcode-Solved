#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        for(auto ch:tokens){
            if(ch=="+" || ch=="/" ||ch=="-" || ch=="*"){
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                ll x=stoll(s1);
                ll y=stoll(s2);
                if(ch=="+"){
                    string tmp=to_string((ll)(x+y));
                    s.push(tmp);
                }
                
                if(ch=="-"){
                    string tmp=to_string((ll)(y-x));
                    s.push(tmp);
                }if(ch=="/"){
                    string tmp=to_string((ll)(y/x));
                    s.push(tmp);
                }if(ch=="*"){
                    string tmp=to_string((ll)(x*y));
                    s.push(tmp);
                }
                
            }
            else{
                s.push(ch);
            }
        }
        int ans=stoi(s.top());
        return ans;
        
        
    }
};