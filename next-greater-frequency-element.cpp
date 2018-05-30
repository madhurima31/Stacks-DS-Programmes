#include<iostream>
#include<stack>
using namespace std;

void nextNFE(int a[],int n)
{
    int _hash[7]={0};
    for(int i=0;i<n;i++){
        _hash[a[i]]+=1;
    }
    int freq[n];
    for(int i=0;i<n;i++){
        freq[i]=_hash[a[i]];
    }
    stack <int> st;
    int output[n];
    output[n-1]=-1;
    st.push(n-1); //push index position;
    for(int i=n-2;i>=0;i--){
        if(freq[i]<freq[st.top()]){
            output[i]=a[st.top()];
        }
        else{
            while(!st.empty()){
                if(freq[st.top()]<=freq[i]){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                output[i]=-1;
            }
            else{
                output[i]=a[st.top()];
            }
        }
        st.push(i);
    }
for(int i=0;i<n;i++){
    cout<<output[i];
}

}

int main()
{
    int a[] = {1, 1, 2, 3, 4, 2, 1};
    nextNFE(a,7);
    return 0;
}
