class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] != '0') return false;
        
        queue<int> q;
        q.push(0);
        
        int i = 0;
        int j;
        int mxInd = 0;
        
        while(!q.empty())
        {
            i = q.front();
            q.pop();
            
            if(i == n-1) return true;
            
            for(j = max(i+minJump, mxInd) ; j <= min(n-1, i+maxJump) ; j++)
            {
                if(s[j] == '0')
                    q.push(j);
            }
            mxInd = min(n, i+maxJump+1);
        }
        
        return false;
    }
};