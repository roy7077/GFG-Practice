
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()) return -1;
           int y=s.top();
           s.pop();
           int x;
           if(y<0) {
               x=minEle;
               minEle=minEle-y;
           }
           else {
               x=minEle+y;
           }
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()) {
               minEle=x;
               s.push(0);
           }
           else {
               s.push(x-minEle);
               minEle=min(minEle,x);
           }
       }
};

/*
     A new unique approach and How I thought it
     Say, we have to currently push x and current minElement is minEle
     Now, we are going to use approach in which instead of pushing and popping actual elements, we would perform some operations before pushing and popping. The aim is to somehow obtain the last minEle when an item would be popped without scanning whole current stack.
     So, let's say, y is being pushed actually into stack instead of x and current minElement is minEle.
     Now, following conditions arises,

 

    while pushing
    
       * y=x-minEle   //only difference is pushed as if while popping, we can check if y<0 => minEle would be changed else would be same as current
    
       * minEle=min(minEle,x) //updating current minEle

 

    while Popping
    
       y=top element of stack

 

   if(y≥0):

    * there would be no change as element which was pushed currently was greater than minEle, so no change in minEle. But x=minEle+y

 

   if(y<0):

  * x=minEle //imagine this if x was being pushed and it was less than current minEle, minEle would be updated

  * minEle=minEle-y //minEle updated to last minEle at time of last element in stack was pushed

 

    If not following, just observe how elements would be pushed according to formula y=x-minEle and track all three variables x,y,minEle at each push operation
    
    Apply it on this test case,

 

    push(2)
    
    push(3)
    
    push(1)
    
    push(6)
    
    push(0)

 

    Now, start popping each one and try to calculate last minEle, x from y and current minEle.
*/