#include<bits/stdc++.h>
using namespace std;

void printNGE(int input[],int n)
{
    int output[n];
    int i;
    stack <int> s;
    s.push(input[n-1]);
    output[n-1]=-1;
    for(i=n-2;i>=0;i--){
        if(input[i]<s.top()){
            output[i]=s.top();
        }
        else{
            while(!s.empty()){
                //keep popping all elements in the stack which are lesser than input[i]
                if(input[i]>s.top()){
                    s.pop();
                }
                //when an element greater than input[i] is encountered, stop popping
                else{
                    break;
                }
            }
            //if all elements of stack are popped out, that means no element is greater than input[i]
            if(s.empty()){
                output[i]=-1;
            }
            else{
                output[i]=s.top();
            }
        }
        s.push(input[i]);

    }

//print output array ;
    for(i=0;i<n;i++){
        cout<<output[i]<<" " ;
    }
}

int main()
{
    int arr[]={10,20,1,5,25,500,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    printNGE(arr,n);

}
