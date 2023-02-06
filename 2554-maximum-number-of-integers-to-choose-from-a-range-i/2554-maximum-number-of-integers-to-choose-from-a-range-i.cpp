class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       // int c=0;
        int sum=0;
        set<int>s;
        int ans=0;
        for(auto i:banned){
            s.insert(i);
        }
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                if(sum+i>maxSum){
                    break;
                }
                sum+=i;
                ans++;
            }
        }
        return ans;
    }
};