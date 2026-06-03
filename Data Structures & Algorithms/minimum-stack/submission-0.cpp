class MinStack {
public:
    stack<int>st;
    stack<int>minstack;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(!minstack.empty()){
        if(val<minstack.top()){
            minstack.push(val);
            return;
        }
        else{minstack.push(minstack.top());return;}     
        }
        minstack.push(val);
        return;
        
    }
    
    void pop() {
        st.pop();
        minstack.pop();
        return;
    }
    
    int top() {
        st.top();
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
