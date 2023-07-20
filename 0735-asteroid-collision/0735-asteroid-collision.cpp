class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--)
        {
            int a = asteroids[i];
            bool enter = false;
            while(!s.empty() and (s.top() < 0 and a > 0))
            {
                int top = s.top();
                s.pop();
                if(abs(top) > abs(a))
                {
                    s.push(top);
                    enter = true;
                    break;
                }
                else if(abs(a) > abs(top))
                    continue;
                else {
                    enter = true;
                    break;
                }
            }
            
            if(!enter)
                s.push(a);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};