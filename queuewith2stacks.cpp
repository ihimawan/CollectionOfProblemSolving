class myQueue{
    private:
       stack<int> stack1;
       stack<int> stack2;
    public:
       void push(int x){
           stack1.push(x);
       }
       
       void pop(){
           if (stack2.isEmpty()){
               while(!stack1.isEmpty()){
                   stack2.push(stack1.top());
                   stack1.pop();
               }
           }
           stack2.pop();
       }
       
       int peek(){
           if (stack2.isEmpty()){
               while(!stack1.isEmpty()){
                   stack2.push(stack1.top());
                   stack1.pop();
               }
           stack2.top();
       }
       
       bool isEmpty(){
           return stack1.isEmpty() && stack2.isEmpty();
       }
       
};