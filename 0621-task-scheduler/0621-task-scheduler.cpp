class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> m;
        int ans = 0;
        
        for(auto x:tasks)
            m[x]++;
        for(auto x:m)
            pq.push(x.second);
        
        while(!pq.empty())
        {
            int cycles = n+1;
            int time = 0;
            vector<int> temp;
            
            for(int i=0;i<cycles and !pq.empty();i++)
            {
                temp.push_back(pq.top());
                pq.pop();
                time++;
            }
              
            for(auto x:temp)
            {
                x--;
                if(x)
                    pq.push(x);
            }
            
            if(pq.empty())
                ans += time;
            else
                ans += cycles;
        }
        
        return ans;
    }
};