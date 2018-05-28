#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string s)
{
    stack <char> st;
    st.push('N');
    int len =s.length();
    string output;
    for(int i=0;i<len;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&& s[i]<='Z')){
           output+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(st.top()!='N' && st.top()!='('){
                char c=st.top();
                st.pop();
                output+=c;
            }
            if(st.top()=='(')
                 st.pop();
        }
        else{
            while(st.top()!='N' && precedence(s[i])<=precedence(st.top())){
               char c=st.top();
               st.pop();
               output+=c;
               }
               st.push(s[i]);
        }
    }
     while(st.top()!='N'){
        char c= st.top();
        st.pop();
        output+=c;
    }

    return output;
}
string infixToPrefix(string s)
{
    int len=s.length();
    reverse(s.begin(),s.end());

    for(int i=0;i<len;i++){
        if(s[i]=='('){
            s[i]=')';
           }
        else if(s[i]==')'){
            s[i]='(';
        }
    }

    string convertedToPos = infixToPostfix(s);

    reverse(convertedToPos.begin(),convertedToPos.end());

    return convertedToPos;
}
int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << std::endl;
    return 0;
}
