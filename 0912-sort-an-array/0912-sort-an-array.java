class Solution {
    public void merge(int[] arr , int l , int mid , int r)
    {
        int n1 = mid-l+1;
        int n2 = r-mid;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i=0;i<n1;i++)
        {
            L[i] = arr[i+l];
         }
        for(int i=0;i<n2;i++)
        {
            R[i] = arr[i+mid+1];
        }
        int i=0,j=0;
        int k = l;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                arr[k++] = L[i++];
            }
            else 
            {
                arr[k++] = R[j++];
            }
        }
        while(i<n1)
        {
            arr[k++] = L[i++];
        }
    }
    public void merge_sort(int[] nums , int l , int r)
    {
        if(l<r)
        {
            int mid = l+(r-l)/2;
            merge_sort(nums , l , mid);
            merge_sort(nums,mid+1,r);
            merge(nums , l , mid , r);
        }
    }
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        merge_sort(nums , 0 , n-1);
        return nums; 
    }
}