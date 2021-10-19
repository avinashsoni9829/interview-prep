	class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> a, m;
    int mi;
    MinStack() {
        a.clear();
        m.clear();
    }
    
    void push(int x) {
        if (a.empty())
        {
            m.push_back(x);
            a.push_back(x);
        }
        else
        {
            a.push_back(x);
            m.push_back(min(x, m.back()));
        }
    }
    
    void pop() {
        a.pop_back();
        m.pop_back();
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return m.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
