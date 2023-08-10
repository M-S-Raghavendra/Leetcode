class MedianFinder {
private:
    priority_queue<int> mxpq;
    priority_queue<int,vector<int>,greater<int>> mnpq;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        mxpq.push(num);
        if(mxpq.size() > mnpq.size())
        {
            mnpq.push(mxpq.top());
            mxpq.pop();
        }
        
        if(mnpq.size() > mxpq.size())
        {
            mxpq.push(mnpq.top());
            mnpq.pop();
        }
    }
    
    double findMedian() {
        int n = mxpq.size() + mnpq.size();
        if(n%2 == 1)
            return mxpq.top();
        else
            return (mxpq.top() + mnpq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */