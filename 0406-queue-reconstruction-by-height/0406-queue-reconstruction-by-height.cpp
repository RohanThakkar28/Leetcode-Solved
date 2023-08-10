class Solution {
public:
    int seg[4*100005];
    void build(int id,int l,int r){
        if(l==r){
        //    cout<<id<<endl;
            seg[id]=1;
            return;
        }
        int m=l+(r-l)/2;
        build(2*id+1,l,m);
        build(2*id+2,m+1,r);
        seg[id]=seg[2*id+1]+seg[2*id+2];
    }
    void update(int id){
        while(id>0){
            
            seg[id]--;
            id=(id-1)/2;
        }
    }
    int query(int k,int id,int l,int r){
        if(l==r){
           update(id);
            return l;
        }
        int lf=seg[2*id+1];
        int m=l+(r-l)/2;
        if(k<=lf){
            return query(k,2*id+1,l,m);
        }
        else{
            return query(k-lf,2*id+2,m+1,r);
        }
        
    }
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
            
        }
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),sortcol);
        
        int n=people.size();
        // for(int i=0;i<n;i++){
        //     cout<<people[i][0]<<" "<<people[i][1]<<endl;
        // }
        build(0,0,n-1);
     //   cout<<"hi"<<endl;
        vector<vector<int>>ans(n);
        
        for(int i=0;i<n;i++){
          //  cout<<i<<" "<<pendl;
            // for(int j=0;j<12;j++){
            //     cout<<seg[j]<<" ";
            // }
            // cout<<endl;
            int id=query(people[i][1]+1,0,0,n-1);
           // cout<<id<<" "<<people[i][1]<<endl;
            ans[id]=people[i];
        }
        return ans;
        
    }
};