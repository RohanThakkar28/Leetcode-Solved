class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        map<int,int>c;
        for(auto i:tasks){
            c[i]++;
        }
        for(auto i:c){
            int num=i.second;
            if(num%3==0){
                ans+=num/3;
                
            }
            else if(num-2>=0 && (num-2)%3==0){
                ans+=(1+(num-2)/3);
            }
            
            else if(num-4>=0 && (num-4)%3==0){
                ans+=(2+(num-4)/3);
            }
            else{
                ans=-1;
                break;
            }
        }
        return ans;
        
        
    }
};