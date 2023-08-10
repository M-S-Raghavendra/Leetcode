class MedianFinder {
private:
    multiset<int> ms;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        ms.insert(num);
    }
    
    double findMedian() {
        auto it1 = ms.begin();
        int n = ms.size();
        advance(it1,n/2);
        
        if(n % 2 == 0)
        {
            auto it2 = it1--;
            return (*it1 + *it2)/2.0;
        }
        else
            return *it1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */