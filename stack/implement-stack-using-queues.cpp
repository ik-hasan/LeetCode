class MyStack {

private:
    queue<int>*q;
    int s;
public:
    MyStack() {
        q = new queue<int>();
    }
    
    void push(int x) {
        q->push(x);
    }
    
    int pop() {
        s = q->size();
        while(s!=1)
        {
            int x = q->front();
            q->pop();
            q->push(x);
            s--;
        }
        int x = q->front();
        q->pop();
        return x;
    }
    
    int top() {
         s = q->size();
        while(s!=1)
        {
            int x = q->front();
            q->pop();
            q->push(x);
            s--;
        }
        int x = q->front();
        q->pop();
        q->push(x);
        return x;
        
    }
    
    bool empty() {
        if(q->empty()) return true;
        else return false;
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