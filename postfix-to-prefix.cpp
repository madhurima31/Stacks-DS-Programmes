#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    switch(c)
    {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
    return true;

    }
    return false;

}

string postfixToPrefix(string s)
{
    stack <string> st;
    int len = s.size();
    for(int i=0;i<len;i++)
    {
        if(isOperator(s[i]))
        {
            string op1= st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp= s[i]+op2+op1;
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}

int main() {
  string post_exp = "ABC/-AK/L-*";
  cout << "Postfix : " << postfixToPrefix(post_exp);
  return 0;
}
