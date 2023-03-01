class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        
        mergeSort(nums,0,n-1);
        return nums;
    }
    
    void mergeSort(vector<int> &a, int l, int r)
    {
        if(l < r)
        {
            int m = (l+r)/2;
            mergeSort(a,l,m);
            mergeSort(a,m+1,r);
            merge(a,l,m,r);
        }
    }
    
    void merge(vector<int> &a, int l, int m, int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int left[n1], right[n2];
        
        for(int i=0;i<n1;i++)
            left[i] = a[i+l];
        for(int i=0;i<n2;i++)
            right[i] = a[m+1+i];
        
        int i = 0, j = 0, k = l;
        
        while(i < n1 and j < n2)
        {
            if(left[i] <= right[j])
                a[k++] = left[i++];
            else
                a[k++] = right[j++];                    
        }
        
        while(i < n1)
        {
            a[k++] = left[i++];
        }
        
        while(j < n2)
        {
            a[k++] = right[j++];
        }           
    }
};