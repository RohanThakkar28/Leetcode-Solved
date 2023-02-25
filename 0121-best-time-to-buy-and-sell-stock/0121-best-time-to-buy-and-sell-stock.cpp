class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int m=prices[0];
        for(int i=1;i<prices.size();i++){
            //cout<<m<<endl;
            ans=max(ans,prices[i]-m);
            m=min(m,prices[i]);
            
        }
        return ans;
        
    }
};