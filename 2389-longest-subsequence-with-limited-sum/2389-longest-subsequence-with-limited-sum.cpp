class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(auto x:queries)
        {
            int sum=0, cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                if(sum + nums[i] <= x)
                {
                    sum += nums[i];
                    cnt++;
                }
                else
                    break;
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};