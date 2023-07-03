class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double maxTime = -1;
        double time;
        int ans = 0;
        unordered_map<int,int> m;
        
        for(int i=0;i<position.size();i++)
            m[position[i]] = speed[i];
        sort(position.begin(),position.end());
        
        for(int i=position.size()-1;i>=0;i--)
        {
            time = (1.0*(target-position[i]))/m[position[i]];
            if(time > maxTime)
            {
                ans++;
                maxTime = time;
            }
        }
        
        return ans;
    }
};