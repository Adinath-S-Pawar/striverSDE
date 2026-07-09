#include<iostream>
using namespace std; 
//using arr , hw)using linked list
class stack{
 //  top,size,arr  
    int *arr;
    int top;
    int size;
    public:
    //behaviour
    stack(int size){ // constructor
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element)
    {
        if( (size - top) > 1) // space available , or use size-1 == top
        {  top++;
          arr[top] = element;
        }
        else
          cout<<"stack overflow "<<endl;
    }

    void pop()
    {
        if(top >= 0 )
        {
            top--;
        }
        else
           cout<<"stack underflow"<<endl;
    }

    int peek() //top element
    {
        if (top >=0)
        {
            return arr[top];
        }
        else{
            cout<<"stack empty"<<endl;
            return -1;
        }
        
    }

    bool isempty()
    {
        if(top == -1)
        {
            return true;
        }
        else
          return false;
    }

};

int main(){

    stack s(5);
    cout<<s.isempty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.peek()<<endl;
    cout<<"pop"<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isempty()<<endl;

    
    return 0;
}