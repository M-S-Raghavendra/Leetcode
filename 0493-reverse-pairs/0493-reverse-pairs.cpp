class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
    
    int mergesort(vector<int> &arr, int l, int r)
    {
        int cnt = 0;
        if(l < r)
        {
            int m = (l+r)/2;
            cnt += mergesort(arr,l,m);
            cnt += mergesort(arr,m+1,r);
            cnt += merge(arr,l,m,r);
        }
        return cnt;
    }
    
     int merge(vector<int> &arr, int l, int m, int r)
    {
        int n1 = m-l+1, n2 = r-m;
        long long left[n1], right[n2];
        int cnt = 0;
        
        for(int i=0;i<n1;i++)
            left[i] = arr[l+i];
        for(int i=0;i<n2;i++)
            right[i] = arr[m+1+i];
        
        int x = 0, y = 0;
        for(int x=0;x<n1;x++)
        {
            while(y < n2 and left[x] > 2LL*right[y])
                y++;
            cnt += y;
        }
         
        int i = 0, j = 0, k = l;
        while(i < n1 and j < n2)
        {
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else 
                arr[k++] = right[j++];
        }
        
        while(i < n1)
            arr[k++] = left[i++];
        while(j < n2)
            arr[k++] = right[j++];
        
        return cnt;
    }
};