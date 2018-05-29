#include<iostream>
#include<stack>
using namespace std;

bool checkParenthesis(string s)
{
    stack <char> st;
    char c;
    int len = s.length();
    for(int i=0;i<len;i++){
            if(s[i]=='['||s[i]=='('||s[i]=='{'){
                    st.push(s[i]);
            }

            else{
                switch(s[i]){

                      case ']':
                         c=st.top();
                        st.pop();
                        if(c=='('||c=='{')
                            return false;
                        break;
                      case ')':
                        c=st.top();
                        st.pop();
                        if(c=='['||c=='{')
                            return false;
                        break;
                      case '}':
                        c=st.top();
                        st.pop();
                        if(c=='['||c=='(')
                            return false;
                        break;

                    }
                }

    }
    if(st.empty()){
        return true;
    }
    else
        return false;
}

int main(){

string s;
cout<<"enter a string";
cin>>s;
if(checkParenthesis(s)){
    cout<<"balanced";
}
else{
    cout<<"not balanced";
}
return 0;
}
