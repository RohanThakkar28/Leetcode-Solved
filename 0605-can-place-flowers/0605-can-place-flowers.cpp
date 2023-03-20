class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int c=0;
        int i=1;
        reverse(f.begin(),f.end());
        f.push_back(0);
        reverse(f.begin(),f.end());
        f.push_back(0);
        while(i<f.size()-1){
            if(f[i-1]==0 && f[i+1]==0 && f[i]==0){
                c++;
                i+=2;
            }
            else{
                i++;
            }
            
        }
        return c>=n;
        
    }
};