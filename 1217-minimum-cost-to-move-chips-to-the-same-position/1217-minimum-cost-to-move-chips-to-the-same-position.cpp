class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int o=0;
        int e=0;
        int n=position.size();
        for(int i=0;i<n;i++){
            if(position[i]%2==0){
                e++;
            }
            else{
                o++;
            }
        }
        return min(o,e);
        
    }
};