#include<bits/stdc++.h>
using namespace std;
//using recursion
stack <int> s;

void printstack()
{
    stack <int> s1=s;
    while(!s1.empty()){
        cout<<s1.top();
        s1.pop();
    }
    cout<<endl;
}

void insertAtTheBottom(int item)
{
    if(s.empty()){
        s.push(item);
    }
    else{
       int itemtop = s.top();
       s.pop();
       insertAtTheBottom(item);
       s.push(itemtop);
    }
}

void reverseStack()
{
    if(!s.empty()){
       int item = s.top();
       s.pop();
       reverseStack();
       insertAtTheBottom(item);
    }


}


int main()
{

    s.push(1);
    s.push(2);
     s.push(3);
    s.push(4);
     s.push(5);
    s.push(6);
    cout<<"original stack: ";
    printstack();
    cout<<endl;
    reverseStack();
    cout<<"after reversal: ";
    printstack();


    return 0;
}
