class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(),people.end());      
        int ans = 0;
        
        int i = 0, j = n-1;
        
        while(i <= j)
        {
            if(people[i] + people[j]  <= limit)
            {
                i++;
                j--;
            }
            else
                j--;
            
            ans++;
        }
        
        return ans;
    }
};