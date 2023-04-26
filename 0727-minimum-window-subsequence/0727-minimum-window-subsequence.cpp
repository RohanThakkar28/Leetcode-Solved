#define ll long long int
class Solution {
public:
    string minWindow(string s1, string s2) {
        vector<set<ll>>v(26);
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a'].insert(i);
        }
        ll ans=1e9;
        ll l=-1;
        ll r=-1;
        ll ansl=l;
        ll ansr=r;
        
       
        for(int i=0;i<s1.size();i++){
            ll l1=-1;
            ll r1=-1;
            auto it1=v[s2[0]-'a'].lower_bound(i);
            if(it1==v[s2[0]-'a'].end()){
                
                break;
            }
            l1=*it1;
            r1=l1;
            //cout<<r1<<endl;
           
            ll j=l1;
            ll id2=1;
            while(id2<s2.size()){
                auto it1=v[s2[id2]-'a'].lower_bound(r1+1);
                if(it1==v[s2[id2]-'a'].end()){
                    l1=0;
                    r1=1e9;
                    
                    break;
                    
                }
                r1=*it1;
                id2++;
                
            }
            //cout<<l1<<" "<<r1<<endl;
            if(r1-l1+1<ans){
                ans=r1-l1+1;
                
                ansl=l1;
                ansr=r1;
            }
            
        }
        if(ans==1e9){
            return "";
        }
        return s1.substr(ansl,ansr-ansl+1);
        
        
    }
};