class Solution {
public:
    bool confusingNumber(int n) {
        map<int,int>c;
        c[0]=0;
        c[1]=1;
        c[2]=-1;
        c[3]=-1;
        c[4]=-1;
        c[5]=-1;
        c[6]=9;
        c[7]=-1;
        c[8]=8;
        c[9]=6;
        bool ye=true;
        int c1=n;
        int ans=0;
        while(n!=0){
            int num=n%10;
            if(c[num]==-1){
                return false;
                break;
            }
            else{
                ans=ans*10+c[num];
            }
            n/=10;
        }
        int an=0;
        
        return (ans!=c1);
        
    }
};