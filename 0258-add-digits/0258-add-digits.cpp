class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()!=1){
            int n=0;
            while(num>0){
                n+=num%10;
                num/=10;
            }
            num=n;
            s=to_string(num);
            
        }
        return num;
        
    }
};