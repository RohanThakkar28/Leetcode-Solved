class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        vector<int>tt;
        tt.push_back(1e9);
        tt.push_back(1e9);
        intervals.push_back(tt);
        sort(intervals.begin(),intervals.end(),comp);
        int i=0;
       
        while(i+1<intervals.size()){
            if(intervals[i][1]<intervals[i+1][0]){
                ans.push_back(intervals[i]);
                i++;
            }
            else{
             ///   cout<<"hi"<<endl;
                int l=intervals[i][0];
                int rmaxy=intervals[i][1];
                while(i+1<intervals.size() && rmaxy>=intervals[i+1][0]){
                    rmaxy=max(rmaxy,intervals[i+1][1]);
                    i++;
                }
                int r=rmaxy;
                i++;
                
                //cout<<l<<" "<<r<<endl;
                vector<int>tmp;
                tmp.push_back(l);
                tmp.push_back(r);
                ans.push_back(tmp);
                
            }
                              
        }
        return ans;
        
        
    }
};