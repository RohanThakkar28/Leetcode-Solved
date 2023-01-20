/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n=reader.length();
        int l=0;
        int r=n-1;
        int ans;
        while(l<r){
            int m=(l+r)/2;
          //  cout<<m<<endl;
            
        //    cout<<l<<" "<<r<<" "<<m<<endl;
            int len=r-l+1;
            if(len%2==0){
                int r1=reader.compareSub(l,m,m+1,r);
            
                if(r1==1){
                    r=m;
                }
                else if(r1==-1){
                    l=m+1;

                }
                
            }
            else{
                int r1=reader.compareSub(l,m-1,m+1,r);
            
                if(r1==1){
                    r=m;
                }
                else if(r1==-1){
                    l=m;

                }
                else{
                    l=m;
                    break;
                }
                
            }
            
            
        }
        
        return l;
        //int a=
        
    }
};