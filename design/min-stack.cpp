class MinStack {
public:
    int minm=INT_MAX, secondMinm=INT_MAX;
    vector<int> v;
    int index=-1;
    MinStack() {
    }
    
    void push(int value) {
        if(minm>value){
            secondMinm = minm;
            minm = value;
        }
        v.push_back(value);
        index++;
    }
    
    void pop() {
        if(index==-1) return;
        if(minm == v[index]){
            minm = secondMinm;
        }
        index--;
    }
    
    int top() {
        if(index==-1) return 0;
        return v[index];
    }
    
    int getMin() {
        return minm;
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