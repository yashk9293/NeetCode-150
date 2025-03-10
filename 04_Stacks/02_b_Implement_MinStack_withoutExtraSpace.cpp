// Question Link :- https://leetcode.com/problems/min-stack/description/
// 155. Min Stack -> getMin() in O(1) time and O(1) extra space

// SPECIAL STACK


// S.C = O(1)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long mini;
    MinStack() {
        
    }
    
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else if(data <= mini) {
            s.push(2ll*data - mini);
            mini = data;
        }   
        else {
            s.push(data);
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        if(s.top() < mini){
            mini = 2ll*mini - s.top();
        }
        s.pop();
    }
    
    // critical part
    int top() {
        if(s.empty())
            return -1;
        
        if(s.top() < mini) {
            return mini;
        }
        return s.top();
    }
    
    int getMin() {
        if(s.empty()) {
            return -1;
        }
        return mini;
    }
};