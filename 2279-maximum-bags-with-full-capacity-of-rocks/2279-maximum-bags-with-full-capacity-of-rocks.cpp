class Solution {
public:
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int R) {
        vector<int>vec;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            vec.push_back(capacity[i]-rocks[i]);
        }
        sort(vec.begin(),vec.end());
        int c=0;
        for(int i=0;i<n;i++){
            if(R>=vec[i]){
                c++;
                R-=vec[i];
            }
            
        }
        return c;
        
    }
};