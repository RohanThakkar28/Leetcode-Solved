class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>c1;
        map<int,int>c2;
        priority_queue<pair<int,int>>q1;
        priority_queue<pair<int,int>>q2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            c2[nums[i]]++;
        }
        for(auto i:c2){
            q2.push({i.second,i.first});
        }
        for(int i=0;i<n;i++){
            c1[nums[i]]++;
            q1.push({c1[nums[i]],nums[i]});
            c2[nums[i]]--;
            q2.push({c2[nums[i]],nums[i]});
            //cout<<q1.size()<<endl;
            //cout<<c1[q1.top().second]<<" "<<q1.top().first<<endl;
            while(c1[q1.top().second]!=q1.top().first){
                q1.pop();
            }
            //cout<<i<<endl;
            while(c2[q2.top().second]!=q2.top().first){
                q2.pop();
            }
            if(q1.top().second==q2.top().second && (q1.top().first)*2>(i+1) && (q2.top().first)*2>(n-i-1)){
                return i;
            }
        }
        return -1;
    }
};