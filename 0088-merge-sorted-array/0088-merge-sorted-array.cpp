class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
        {
            for(int j=0;j<n;j++)
                nums1[m+j] = nums2[j];
            return ;
        }
        if(n == 0) return ;
        int i = 0, j = 0;
        
        while(i < m)
        {
            if(nums1[i] > nums2[j])
            {
                swap(nums1[i],nums2[j]);
                // Insertion logic of insertion sort
                int k;
                int key = nums2[j];
                for(k=j+1;k<n;k++)
                {
                    if(nums2[k] < key)
                        nums2[k-1] = nums2[k];
                    else break;
                }
                nums2[k-1] = key;
                // while(k < n-1 and nums2[k] > nums2[k+1])
                // {
                //     swap(nums2[k],nums2[k+1]);
                //     k++;
                // }
            }
            i++;
        }
        
        for(int j=0;j<n;j++)
            nums1[i+j] = nums2[j];
    }
};