class Solution {
public:
    static bool comp(string a,string b){
        return a<b?true:false;
    }
    static bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
        if(a.second==b.second){
            return a.first<b.first;
        }
        
    return (a.second > b.second);
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>count;
        int n=words.size();
        set<string>x;
        for(int i=0;i<n;i++){
            count[words[i]]++;
            x.insert(words[i]);
        }
        vector<string>ans;
        vector<pair<string,int>>c;
        for(auto i:x){
            c.push_back(make_pair(i,count[i]));
            
        }
        sort(c.begin(),c.end(),sortbysec);
        int z=0;
        for(auto i:c){
            ans.push_back(i.first);
            z++;
            if(z==k){
                break;
            }
        }
        
        
        return ans;
        
    }
};