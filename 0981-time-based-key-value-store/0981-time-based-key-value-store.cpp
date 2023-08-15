class TimeMap {
private:
    unordered_map<string,vector<pair<string,int>>> m;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int s=0, e=m[key].size()-1;
        string ans = "";
        
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(m[key][mid].second <= timestamp)
            {
                ans = m[key][mid].first;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */