class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        
        while(low <= high)
        {
            int m = (low + high)/2;
            if((m == 0 or arr[m] > arr[m-1]) and (m == n-1 or arr[m] > arr[m+1]))
                return m;
            else if(m == 0 or arr[m] > arr[m-1])
                low = m + 1;
            else
                high = m - 1;
        }
        
        return -1;
    }
};