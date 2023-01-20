class Solution {
private:
    struct hashFunction 
    {
      size_t operator()(const vector<int> 
                        &myVector) const 
      {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector) 
        {
          answer ^= hasher(i) + 0x9e3779b9 + 
                    (answer << 6) + (answer >> 2);
        }
        return answer;
      }
    };
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<vector<int>,hashFunction> s;
        vector<int> v;
        
        f(nums.size()-1,nums,v,s);
        vector<vector<int>> ans;
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
    
    void f(int ind, vector<int> &nums, vector<int> &v, unordered_set<vector<int>,hashFunction> &s)
    {
        if(ind < 0)
        {
            if(v.size() > 1)
            {
                vector<int> t;
                for(int i=v.size()-1;i>=0;i--)
                    t.push_back(v[i]);
                s.insert(t);
            }
            return ;
        }
        
        f(ind-1,nums,v,s);
        
        if(v.empty() or nums[ind] <= v.back())
        {
            v.push_back(nums[ind]);
            f(ind-1,nums,v,s);
            v.pop_back();
        }
    }
};