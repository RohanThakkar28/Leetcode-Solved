class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        
            
            for(int j=0;j<n;j++){
                s.insert(nums[j]);
            }
            
                  
            
        
        for(int i=0;i<=31;i++){
            if((s.find((1<<i))==s.end())){
                return (1<<i);
            }
        }
    
        return 0;
        
        
    }
};