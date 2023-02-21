class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        int l=0;
        int r=n-1;
        if(n==1){
            return a[0];
        }
        while(l<=r){
            int m=l+(r-l)/2;
            if((m-1>=0 && a[m-1]==a[m]) || (m+1<n && a[m+1]==a[m])){
                if((m-1>=0 && a[m-1]==a[m])){
                    int rem=n-m-1;
                    if(rem%2==0){
                        r=m-1;
                    }
                    else{
                        l=m+1;
                    }
                }
                else{
                    int rem=n-m-2;
                    if(rem%2==0){
                        r=m-1;
                    }
                    else{
                        l=m+1;
                    }
                    
                }
            }
            else{
                return a[m];
            }
            
        }
        return 0;
        
    }
};