class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        
        int p1 = f(0,n-1,0,nums);
        int p2 = total - p1;
        cout<<p1<<endl;
        return p1 >= p2;
    }
    
    int f(int i, int j, int turn, vector<int> &nums)\
    {
        if(i > j)
            return 0;
        // cout<<i<<" "<<j<<" "<<turn<<endl;
        
        if(turn == 0)
            return max(nums[i] + f(i+1,j,1,nums), nums[j] + f(i,j-1,1,nums));
        else
            return min(f(i+1,j,0,nums), f(i,j-1,0,nums));
    }
};