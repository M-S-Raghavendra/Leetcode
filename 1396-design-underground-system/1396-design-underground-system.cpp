class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> in;
    unordered_map<string,pair<long,long>> avg;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(in.find(id) == in.end())
        {
            in.insert({id,{stationName,t}});
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if(in.find(id) != in.end())
        {
            auto data = in[id];
            string stn = data.first;
            int time = data.second;
            in.erase(id);
            string inout = stn + "->" + stationName;
            
            avg[inout].first += (t - time);
            avg[inout].second++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = 0;
        string p = startStation + "->" + endStation;
        ans = 1.0 * avg[p].first / avg[p].second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */