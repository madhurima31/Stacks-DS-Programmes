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

void infixToPostfix(string s)
{
    string ns;
    int i;
    std::stack <char> st;
    st.push('N');
    int l=s.length();

    for(i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A'&& s[i]<='Z'))
           {
               ns+=s[i];
           }
        else if(s[i]=='(')
            {
                st.push(s[i]);
            }
        else if(s[i]==')'){
            while(st.top()!='N' && st.top()!='('){
                    char c= st.top();
                    st.pop();
                    ns+=c;
                  }
                if(st.top()=='('){
                    char c=')';
                    st.pop();
                   }
            }
        else{
            while(st.top()!='N' && precedence(s[i])<= precedence(st.top())){
                char c=st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);

        }

    }

    while(st.top()!='N'){
        char c= st.top();
        st.pop();
        ns+=c;
    }
    cout<<ns;
}

int main()
{
    string input = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(input);
    return 0;
}
