#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
       return true;
       }
       return false;
}

string getInfix(string s)
{
    stack <string> st;
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        if(isOperand(s[i])){
            st.push(string(1,s[i]));
        }
        else{
           string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp ="("+op2+s[i]+op1+")";
            st.push(temp);
        }

    }
    return st.top();
}

int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}
