#include<bits/stdc++.h>
using namespace std;

struct Mystack
{
    stack <int> s;
    int minEle;

    void getMin()
    {
        if(s.empty()){
            cout<<"stack is empty";
        }
        else{
            cout<<"min element is : "<<minEle;
        }
    }

    void getTopElement()
    {
        if(s.empty()){
            cout<<"empty stack";
        }
        else{
            int x= (s.top()>minEle)?s.top():minEle;
            cout<<"top element is:"<<x;
        }
    }
    void push(int x)
    {
        if(s.empty())
        {
            minEle=x;
            s.push(x);
            return;
        }
        if(x<minEle){
            s.push(2*x-minEle);
            minEle=x;
        }
        else{
            s.push(x);
        }
    }
    void pop(){
        int x;
        if(s.empty()){
            cout<<"empty stack";
            return ;
        }
        x = s.top();
        s.pop();
        if(x<minEle){
            cout<<"popped element is :"<<minEle<<endl;
            minEle=2*minEle-x;
        }
        else{
            cout<<"popped element is :"<<x<<endl;
        }

    }
};

int main()
{
    Mystack s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    s.getTopElement();
    s.pop();
    s.pop();
     s.pop();
    s.pop();

    return 0;
}
