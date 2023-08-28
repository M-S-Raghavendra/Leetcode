class MyStack {
private:
    queue<int> s;
    
    void insert(int x)
    {
        s.push(x);
        int size = s.size() - 1;
        while(size--)
        {
            s.push(s.front());
            s.pop();
        }
    }
    
public:
    MyStack() {
    }
    
    void push(int x) {
        insert(x);
    }
    
    int pop() {
        int value = s.front();
        s.pop();
        return value;
    }
    
    int top() {
        return s.front();
    }
    
    bool empty() {
        return (s.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */