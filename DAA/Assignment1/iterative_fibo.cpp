#include <iostream>
using namespace std;

int fibonacciNonRecursive(int n) {
    int a = 0, b = 1, c;
    if(n==1) {
        cout<<a<<" ";
        return a;
    }
    if(n==2){
        cout<<b<<" ";
        return b;
    }
    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n=0;
    cout<<"\nEnter the n: ";
    cin>>n;
    cout<<"\nFibonacci series: ";
    int num=fibonacciNonRecursive(n);
    cout<<"\nnth num: "<<num<<endl;
    return 0;
}

//Time Complexity: 𝑂(𝑛)
//Space Complexity: 𝑂(1)


