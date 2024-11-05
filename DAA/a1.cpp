#include<iostream>
using namespace std;

int iterativeFibo(int n){
    int a=0,b=1,c=0;
    if(n>=1) {
        cout<<a<<" ";
        c=a;
    }
    if(n>=2){
        cout<<b<<" ";
        c=b;
    }
    if(n>=3){
        for(int i=3;i<=n;i++){
            c=a+b;
            cout<<c<<" ";
            a=b;
            b=c;
        }
    }
    cout<<endl;
    return c;
}

int recursiveFibo(int n){
    if(n==0 || n==1) return n;
    return recursiveFibo(n-1)+recursiveFibo(n-2);
}

int main(){
    int n;
    while(true){
        cout<<"\nn = ";
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<recursiveFibo(i)<<" ";
        }
        int num=recursiveFibo(n);
        cout<<"nth num = "<<num<<endl;
        if(n==-1) break;
    }
    return 0;
}