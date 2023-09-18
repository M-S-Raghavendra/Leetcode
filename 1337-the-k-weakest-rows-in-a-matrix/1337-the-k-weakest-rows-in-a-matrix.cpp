class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        
        for(int i=0;i<m;i++)
        {
            int cnt = bsearch(mat[i]);
            pq.push({cnt,i});
        }
        
        for(int i=0;i<k;i++)
        {
            int ind = pq.top().second;
            pq.pop();
            ans.push_back(ind);
        }
        
        return ans;
    }
    
    int bsearch(vector<int> &nums)
    {
        int s = 0, e = nums.size()-1;
        while(s <= e)
        {
            int m = (s+e)/2;
            if(nums[m] == 1)
                s = m+1;
            else
                e = m-1;
        }
        
        return e;
    }
};