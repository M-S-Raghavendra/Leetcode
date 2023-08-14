class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int m = nums1.size();
        int n = nums2.size();
        
        int size = n+m;
        int i = 0, j = 0;
        int ind1 = size/2, ind2 = ind1 - 1;
        int val1=-1, val2=-1;
        int cnt = 0;
        
        while(i < m and j < n)
        {
            if(nums1[i] <= nums2[j]) {
                if(cnt == ind1) val1 = nums1[i];
                if(cnt == ind2) val2 = nums1[i];
                cnt++;
                if(val1 != -1 and val2 != -1) break;
                i++;
            }
            else {
                if(cnt == ind1) val1 = nums2[j];
                if(cnt == ind2) val2 = nums2[j];
                cnt++;
                if(val1 != -1 and val2 != -1) break;
                j++;
            }
        }
        
        while(i < m)
        {
            if(cnt == ind1) val1 = nums1[i];
            if(cnt == ind2) val2 = nums1[i];
            cnt++;
            if(val1 != -1 and val2 != -1) break;
            i++;
        }
        
        while(j < n)
        {
            if(cnt == ind1) val1 = nums2[j];
            if(cnt == ind2) val2 = nums2[j];
            cnt++;
            if(val1 != -1 and val2 != -1) break;
            j++;
        }
        
        if(size % 2 == 1)
            return val1;
        else
            return (val1 + val2)/2.0;
    }
};