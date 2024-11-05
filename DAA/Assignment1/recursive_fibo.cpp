#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n==0 || n==1) return n;
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

int main() {
    int n=0;
    cout<<"\nEnter the n: ";
    cin>>n;
    cout<<"\nFibonacci series: ";
    for (int i = 0; i < n; i++) {
        cout<<fibonacciRecursive(i)<<" ";
    }
    cout<<"\nnth num: "<<fibonacciRecursive(n-1)<<endl;
    return 0;
}

//Time Complexity: 𝑂(2^𝑛) since each call generates two additional calls until reaching the base case
//Space Complexity: 𝑂(𝑛) due to the recursion stack
