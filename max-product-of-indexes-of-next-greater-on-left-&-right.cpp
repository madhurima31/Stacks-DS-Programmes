#include<iostream>
#include<stack>
using namespace std;

int LRProduct(int a[],int n)
{
    stack <int> st;
    int L[n];
    st.push(0);
    L[0]=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[st.top()]){
            L[i]=st.top()+1;
        }
        else{
            while(!st.empty()){
                if(a[st.top()]<=a[i]){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                L[i]=0;
            }
            else{
                L[i]=st.top()+1;
            }
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }
    int R[n];
    R[n-1]=0;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[st.top()]){
            R[i]=(st.top())+1;
        }
        else{
            while(!st.empty()){
                if(a[st.top()]<=a[i]){
                    st.pop();
                }
                else
                    break;
            }
            if(st.empty()){
                R[i]=0;
            }
            else{
                R[i]=(st.top())+1;
            }

        }
        st.push(i);
    }

    int LR[n];
    for(int i=0;i<n;i++){
        LR[i]=L[i]*R[i];
        cout<<LR[i];
    }
    cout<<endl;
     for(int i=0;i<n;i++){

        cout<<L[i];
    }
     cout<<endl;
     for(int i=0;i<n;i++){

        cout<<R[i];
    }
    cout<<endl;

    int maxProductOfIndex = LR[0];
    for(int i=1;i<n;i++){
        if(LR[i]>maxProductOfIndex)
            maxProductOfIndex=LR[i];
    }
    return maxProductOfIndex;

}



int main()
{
    int arr[] = { 5, 4, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[1]);

    cout << LRProduct(arr, n);

    return 0;
}
