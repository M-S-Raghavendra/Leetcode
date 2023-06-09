class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0, e = n-1;
        int ans = '#';
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(letters[mid] > target)
            {
                ans = letters[mid];
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        
        if(ans == '#')
            ans = letters[0];   //if all are < target, then the smallest is ans, bcz of circular wrap
        
        return ans;
    }
};