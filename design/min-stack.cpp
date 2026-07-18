class MinStack {
public:
    MinStack() {
        
    }
    int minm = INT_MAX;
    int index = -1;
    vector<pair<int,int>> v;
    void push(int value) {
        index++;
        minm = min(minm,value);
        v.push_back({value,minm});
    }
    
    void pop() {
        if(index >= 0){
            v.pop_back();
            index--;
        }
    }
    
    int top() {
        return (index>=0) ? v[index].first : -1;
    }
    
    int getMin() {
        return v[index].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */