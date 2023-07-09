class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;
        
        multiset<int> s(hand.begin(),hand.end());
        int gp;
        
        while(!s.empty())
        {
            gp = groupSize;
            int ele = *s.begin() - 1;
            while(gp--)
            {
                ele++;
                auto it = s.find(ele);
                if(it == s.end())
                    return false;
                s.erase(it);
            }
        }
        
        return true;
    }
};