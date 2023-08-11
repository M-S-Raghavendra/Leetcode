class MyCircularQueue {
private:
    int f = -1, r = -1;
    vector<int> q;
    int n;
    int cnt = 0;
    
public:
    MyCircularQueue(int k) {
        q.resize(k);
        n = k;
    }
    
    bool enQueue(int value) {
        if(cnt == n) return false;
        r = (r+1)%n;
        q[r] = value;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0) return false;
        f = (f+1)%n;
        cnt--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        int p = (f+1)%n;
        int val = q[p];
        return val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */