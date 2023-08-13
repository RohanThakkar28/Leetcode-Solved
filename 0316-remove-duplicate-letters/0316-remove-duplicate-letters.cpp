class Solution {
public:
    string f(string s) {
        int n = s.size();
        vector<int> last(30, 0);
        vector<int> seen(26, false);
        for(int i=0; i<n; i++) {
            // cout<<(s[i]-'a')<<endl;
            last[(s[i]-'a')] = i;
        }
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            int curr = s[i]-'a';
            if(seen[curr]) continue;
            while(!st.empty() and st.top() > curr and last[st.top()]>i) {
                seen[st.top()] = false;
                st.pop();
            }
            st.push(curr);
            seen[curr] = true;
        }
        string res = "";
        while(!st.empty()) {
            char t = (char)(st.top() + 'a');
            res+=t;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string removeDuplicateLetters(string s) {
        return f(s);
        int n=s.size();
        priority_queue<char,vector<char>,greater<char>>q;
        string ans="";
        map<char,int>c;
        for(auto i:s){
            c[i]++;
        }
        for(int i=0;i<n;i++){
            if(c[s[i]]==0){
                continue;
            }
            if(c[s[i]]==1){
                while(q.size()>0){
                    if(c[q.top()]==0){
                        q.pop();
                        continue;
                    }
                    if(q.top()<s[i]){
                        ans+=q.top();
                        c[q.top()]=0;
                        q.pop();
                    }
                    else{
                        q.pop();
                    }
                }
                
                ans+=s[i];
                c[s[i]]=0;
            }
            else{
                q.push(s[i]);
                c[s[i]]--;
            }
        }
        return ans;
        
    }
};