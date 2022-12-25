class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto i:sticks){
            q.push(i);
        }
        int ans=0;
        while(q.size()!=1){
            auto i1=q.top();
            q.pop();
            auto i2=q.top();
            q.pop();
            ans+=(i1+i2);
            q.push(i1+i2);
        }
        return ans;
        
    }
};