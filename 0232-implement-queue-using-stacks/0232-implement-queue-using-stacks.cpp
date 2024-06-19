class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty() == false){
            int y = s2.top();
            s2.pop();
            return y;
        }  
        int temp;
        while(!s1.empty()){
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
       int y =  s2.top();
       s2.pop();
    //    while(!s2.empty()){
    //         temp = s2.top();
    //         s1.push(temp);
    //         s2.pop();
    //     }
       return y;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        int temp;
        while(!s1.empty()){
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int y = s2.top();
        // while(!s2.empty()){
        //     temp = s2.top();
        //     s1.push(temp);
        //     s2.pop();
        // }
        return y;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */