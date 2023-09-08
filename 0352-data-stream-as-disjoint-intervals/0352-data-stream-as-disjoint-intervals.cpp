class SummaryRanges {
private:
    set<int> s;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(s.empty())
            return {};
        
        int prev = -1;
        vector<vector<int>> ans;
        vector<int> v(2,-1);
        
        for(auto x:s)
        {
            if(v[0] == -1)
            {
                v[0] = x;
                prev = x;
            }
            else {
                if(prev+1 == x)
                    prev = x;
                else {
                    v[1] = prev;
                    prev = x;
                    ans.push_back(v);
                    v.resize(2,-1);
                    v[0] = x;
                }
            }
        }
        v[1] = prev;
        ans.push_back(v);
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */