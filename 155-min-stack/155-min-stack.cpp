class MinStack {
public:
    vector<int> s, min;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
        if(min.empty() || min.back()>=val)
            min.push_back(val);
    }
    
    void pop() {
        if(s.back()==min.back())
            min.pop_back();
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */