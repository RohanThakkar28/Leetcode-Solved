class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long int x=0;
        int n=word.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            x=x*10+(word[i]-'0');
            x%=m;
            if(x==0){
                ans[i]=1;
            }
        }
        return ans;
        
    }
};