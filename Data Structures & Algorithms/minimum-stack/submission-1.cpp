class MinStack {
    private:
       stack<int> stk;
        stack<int> minStk;
public:
    MinStack() {
     
    }
    
    void push(int val) {
        stk.push(val);
       int minVal = min(val,minStk.empty()?val:minStk.top());
        minStk.push(minVal);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();

    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
