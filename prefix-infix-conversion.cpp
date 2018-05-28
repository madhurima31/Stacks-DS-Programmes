#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    switch(c){
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
                return true;
            }
    return false;
}

string prefixToInfix(string s)
{
    stack <string> st;
    int len = s.length();

    for(int i=len-1;i>=0;i--)
    {
          if(isOperator(s[i]))
          {
              string op1 = st.top();
              st.pop();
              string op2=st.top();
              st.pop();
              string temp = "("+op1+s[i]+op2+")";

              st.push(temp);
          }
          else{
            st.push(string(1,s[i]));
          }
    }
    return st.top();
}

int main() {
  string prefix_exp = "*-A/BC-/AKL";
  cout << "Infix : " << prefixToInfix(prefix_exp);
  return 0;
}


