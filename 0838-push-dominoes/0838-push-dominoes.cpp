class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
        string ans = dominoes;
        int n = dominoes.size();
        
        for(int i=0;i<n;i++)
            if(dominoes[i] != '.')
                q.push(i);
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            if(ans[i] == 'L')
            {
                if(i == 0) continue;
                else if(ans[i-1] == '.')
                {
                    ans[i-1] = 'L';
                    q.push(i-1);
                }
            }
            else {
                if(i == n-1) continue;
                else if(ans[i+1] == '.') {
                    if(i+2 < n and ans[i+2] == 'L')
                    {
                        q.pop();
                        continue;
                    }
                    ans[i+1] = 'R';
                    q.push(i+1);
                }
            }
        }
        
        return ans;
    }
};