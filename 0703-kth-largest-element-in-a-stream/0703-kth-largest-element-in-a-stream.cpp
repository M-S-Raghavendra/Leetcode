class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk;
    
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        int i = 0;
        int n = nums.size();
        while(k-- and i < n)
            pq.push(nums[i++]);
        while(i < n) 
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if(pq.size() < kk)
        {
            pq.push(val);
            return pq.top();
        }
        
        if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */