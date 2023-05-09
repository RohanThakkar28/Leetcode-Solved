#include <bits/stdc++.h>
class Solution {
public:
    int fans=0;
    int dfs(int i,vector<int>&cost,int n){
        
        if(i>n){
            return 0;
        }
        int a1=cost[i-1]+dfs(2*i,cost,n);
        int a2=cost[i-1]+dfs(2*i+1,cost,n);
        fans+=max(a1,a2)-min(a1,a2);
        return max(a1,a2);
        
        
        
        
    }
    int minIncrements(int n, vector<int>& cost) {
        vector<int>c;
        int temp=dfs(1,cost,n);
        return fans;
        
        
    }
};