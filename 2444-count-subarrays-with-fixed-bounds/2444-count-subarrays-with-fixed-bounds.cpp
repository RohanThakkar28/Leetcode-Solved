#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int>mina;
        vector<int>maxa;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==minK){
                mina.push_back(i);
            }
            if(nums[i]==maxK){
                maxa.push_back(i);
            }
        }
        int i=0;
        ll ans=0;
        while(i<n){
            if(nums[i]>maxK && nums[i]<minK){
                i++;
                continue;
            }
            int s=i;
            while(i<n && nums[i]<=maxK && nums[i]>=minK){
                i++;
            }
            int l=s-1;
            //cout<<s<<" "<<i<<endl;
            
            for(int j=s;j<i;j++){
                if(nums[j]==minK){
                    //cout<<"hi"<<endl;
                    int id=lower_bound(maxa.begin(), maxa.end(),j)-maxa.begin();
                //    cout<<maxa[id]<<endl;
                    if(id==maxa.size() || maxa[id]>=i){
                        continue;
                    }
                    int l1=j-l;
                    int l2=i-maxa[id];
                  //  cout<<l1<<" "<<l2<<endl;
                    ans+=(ll)(l1*l2);
                    l=j;


                }
                else if(nums[j]==maxK){
                    auto id=lower_bound(mina.begin(), mina.end(),j)-mina.begin();
                    if(id==mina.size() || mina[id]>=i){
                        continue;
                    }
                    int l1=j-l;
                    int l2=i-mina[id];
                    ans+=(ll)(l1*l2);
                    l=j;

                }

            }
            i++;

        }
        return ans;
        
    }
};