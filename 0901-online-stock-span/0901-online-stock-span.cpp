class StockSpanner {
public:
    stack<pair<int,int>>s;
    int curr=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int ans=1;
        
        while(!s.empty() && s.top().first<=price){
            ans=max(curr-s.top().second+1,ans);
            s.pop();
        }
        if(!s.empty()){
            ans=max(curr-s.top().second,ans);
        }
        else{
            ans=max(ans,curr+1);
        }
        s.push({price,curr});
        curr++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */