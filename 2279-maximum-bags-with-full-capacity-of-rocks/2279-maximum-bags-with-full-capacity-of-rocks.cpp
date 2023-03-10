class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            rocks[i] = capacity[i] - rocks[i];
        }
        
        sort(rocks.begin(),rocks.end());
        int i = 0;
        
        while(i < n and additionalRocks >= rocks[i])
        {
            ans++;
            additionalRocks -= rocks[i++];
        }
        
        return ans;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i=0;i<n;i++)
//         {
//             if(capacity[i] == rocks[i])
//                 ans++;
//             else
//             {
//                 int diff = capacity[i] - rocks[i];
//                 pq.push(diff);
//             }
//         }
        
//         while(!pq.empty() and additionalRocks > 0)
//         {
//             int top = pq.top();
//             pq.pop();
            
//             additionalRocks -= top;
//             if(additionalRocks >= 0)
//                 ans++;
//         }
//         return ans;
    }
};