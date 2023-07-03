class Solution {
public:
    int countCollisions(string d) {
        stack<char> s;
        int n = d.size();
        int ans = 0;
        
        int i = 0;
        while(i < n and d[i] == 'L')
            i++;
        
        int carsComgingRight = 0;
        for(;i<n;i++)
        {
            if(d[i] == 'R')
                carsComgingRight++;
            else {
                if(d[i] == 'S')
                    ans += carsComgingRight;
                else if(d[i] == 'L')
                    ans += carsComgingRight + 1;    // one (RL) collision and others (RS)
                carsComgingRight = 0;
            }
        }
        
        return ans;
    }
};