class Solution {
public:
    int overlap(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        int r=min({n,m});
        int l=0;
        int ans=0;
        for(int len=0;len<=r;len++){
            bool ye=true;
            int i=s1.size()-len;
            int j=0;
            while(i<s1.size()){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }
                else{
                    ye=false;
                    break;
                }
            }
            if(ye){
                ans=len;
            }
            
        }
        return ans;
    }
    bool issubstr(string &s1,string &s2){
        int i=0;
        int j=0;
        for(int i=0;i<s1.size();i++){
            if(s1.substr(i,s2.size())==s2){
                return true;
            }
        }
        return false;
    }
    string minimumString(string a, string b, string c) {
        vector<pair<int,string>>ans;
       
            
        int ov1=overlap(b,a);
       // cout<<ov1<<endl;
        int ov2=overlap(a,c);
        string ans1=b.substr(0,b.size()-ov1)+a.substr(0,a.size()-ov2)+c;
        ans.push_back(make_pair(ans1.size(),ans1));
        ov1=overlap(c,a);
        ov2=overlap(a,b);
        
        ans1=c.substr(0,c.size()-ov1)+a.substr(0,a.size()-ov2)+b;
       // cout<<ov1<<" "<<ov2<<" "<<ans1<<endl;
        ans.push_back(make_pair(ans1.size(),ans1));
        
        ov1=overlap(a,b);
        ov2=overlap(b,c);
        
        ans1=a.substr(0,a.size()-ov1)+b.substr(0,b.size()-ov2)+c;
        ans.push_back(make_pair(ans1.size(),ans1));
        
        ov1=overlap(c,b);
        ov2=overlap(b,a);
        
        ans1=c.substr(0,c.size()-ov1)+b.substr(0,b.size()-ov2)+a;
        ans.push_back(make_pair(ans1.size(),ans1));
        
        ov1=overlap(a,c);
        ov2=overlap(c,b);
        
        ans1=a.substr(0,a.size()-ov1)+c.substr(0,c.size()-ov2)+b;
        ans.push_back(make_pair(ans1.size(),ans1));
        
        ov1=overlap(b,c);
        ov2=overlap(c,a);
        //cout<<ov1<<" "<<ov2<<endl;
        
        
        ans1=b.substr(0,b.size()-ov1)+c.substr(0,c.size()-ov2)+a;
        ans.push_back(make_pair(ans1.size(),ans1));
        
        
        if(issubstr(a,b)){
            ov1=overlap(a,c);
            ans1=a.substr(0,a.size()-ov1)+c;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(c,a);
            ans1=c.substr(0,c.size()-ov1)+a;
            ans.push_back(make_pair(ans1.size(),ans1));
        }
        if(issubstr(b,a)){
            ov1=overlap(b,c);
            ans1=b.substr(0,b.size()-ov1)+c;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(c,b);
            ans1=c.substr(0,c.size()-ov1)+b;
            ans.push_back(make_pair(ans1.size(),ans1));
        }
        if(issubstr(c,b)){
             ov1=overlap(a,c);
            ans1=a.substr(0,a.size()-ov1)+c;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(c,a);
            ans1=c.substr(0,c.size()-ov1)+a;
            ans.push_back(make_pair(ans1.size(),ans1));
        }
        if(issubstr(b,c)){
            ov1=overlap(b,a);
            ans1=b.substr(0,b.size()-ov1)+a;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(a,b);
            ans1=a.substr(0,a.size()-ov1)+b;
            ans.push_back(make_pair(ans1.size(),ans1));
        }
        if(issubstr(a,c)){
            ov1=overlap(b,a);
            ans1=b.substr(0,b.size()-ov1)+a;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(a,b);
            ans1=a.substr(0,a.size()-ov1)+b;
            ans.push_back(make_pair(ans1.size(),ans1));
        }
        if(issubstr(c,a)){
            ov1=overlap(b,c);
            ans1=b.substr(0,b.size()-ov1)+c;
            ans.push_back(make_pair(ans1.size(),ans1));
            
            ov1=overlap(c,b);
            ans1=c.substr(0,c.size()-ov1)+b;
            ans.push_back(make_pair(ans1.size(),ans1));
            
        }
        if(issubstr(a,b) && issubstr(a,c)){
            return a;
        }
        if(issubstr(b,a) && issubstr(b,c)){
            return b;
        }
        if(issubstr(c,b) && issubstr(c,a)){
            return c;
        }

        sort(ans.begin(),ans.end());
        
        
       
        return ans[0].second;
            
        
        
    }
};