class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        int n=people.size();
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            int pos=0;
            int rem=people[i][1];
           
            pos=rem;
            int j=0;

            while(j<n-1 && rem>0){
                if(ans[j].size()==0 ){
                    rem--;
                }
                else if(ans[j][0]==people[i][0]){
                    rem--;
                }
                j++;
            }
            while(j<n-1 && ans[j].size()>0){
                j++;
            }
            
         //   cout<<people[i][0]<<" "<<people[i][1]<<" "<<j<<endl;
                
                
            
            ans[j]=people[i];
        }
        return ans;
        
    }
};