class Solution {
public:
    int smallestValue(int n) {
        map<int,int>c;
        c[n]++;
        while(true){
            int num=n;
            int nn=0;
            
            for(int i=2;i*i<=num;i++){
                if(n%i==0){
                    while(n%i==0){
                        nn+=i;
                        n/=i;
                        
                    }
                }
                
                
                
            }
            if(nn==0){
                n=num;
                break;
            }
            if(n>1){
                nn+=n;
            }
            n=nn;
            c[n]++;
            if(c[n]>=2){
                break;
            }
        }
        return n;
    }
};