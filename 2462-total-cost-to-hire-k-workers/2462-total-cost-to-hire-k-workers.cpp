class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int i = 0, j = n-1;
        
        long long tot = 0;
        while(k--)
        {
            // It is enough that an element is in pq1 or pq2 (not required to be in both)
            while(pq1.size() < candidates and i <= j)
                pq1.push(costs[i++]);
            while(pq2.size() < candidates and i <= j)
                pq2.push(costs[j--]);
            
            int leftTop = (pq1.empty()) ? INT_MAX : pq1.top();
            int rightTop = (pq2.empty()) ? INT_MAX : pq2.top();
            
            if(leftTop <= rightTop) {
                tot += leftTop;
                pq1.pop();
            }
            else {
                tot += rightTop;
                pq2.pop();
            }
        }
        
        return tot;
    }
};