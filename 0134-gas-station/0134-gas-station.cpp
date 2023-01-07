class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int>a;
        for(int i=0;i<gas.size();i++){
            a.push_back(gas[i]-cost[(i)%(gas.size())]);
        }
        for(int i=0;i<gas.size();i++){
            a.push_back(a[i]);
        }
       /* for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }*/
        cout<<endl;
        int n=gas.size();
        int i=0;
        while(i<n){
            if(a[i]<0){
                i++;
                continue;
            }
            int j=i;
          //  cout<<i<<endl;
            int sum=0;
            while(sum>=0 && j-i<n){
                sum+=a[j];
                j++;
            }
           // cout<<i<<" "<<j<<" "<<sum<<endl;
            if(j-i==n && sum>=0){
                return i;
            }
            else{
                i=j;
            }
        }
        return -1;
        
    }
};

/*

-1 -1 1 -1 -1 1


*/