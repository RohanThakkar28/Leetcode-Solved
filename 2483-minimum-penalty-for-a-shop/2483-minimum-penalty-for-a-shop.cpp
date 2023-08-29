class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int yc=0;
        int nc=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                yc++;
            }
            else{
                nc++;
            }
        }
        int ans=yc;
        
        int pen=0;
        int day=0;
        
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                yc--;
            }
  
            int tmp=pen+yc;
            if(tmp<ans){
                ans=tmp;
                day=i+1;
            }
            ans=min(ans,tmp);
            if(customers[i]=='N'){
                pen++;
            }
            
        }
        
        return day;
    }
};