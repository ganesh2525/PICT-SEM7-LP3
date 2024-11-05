#include<bits/stdc++.h>
#include<ctime>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int deterministicPartition(vector<int>&arr, int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void determinisiticQuicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=deterministicPartition(arr,low,high);
        determinisiticQuicksort(arr,low,pi-1);
        determinisiticQuicksort(arr,pi+1,high);
    }
}

int randomizedPartition(vector<int>&arr,int low,int high){
    int rindex = low + rand() % (high-low+1);
    swap(arr[rindex],arr[high]);
    return deterministicPartition(arr,low,high);
}

void randomizedQuicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=randomizedPartition(arr,low,high);
        randomizedQuicksort(arr,low,pi-1);
        randomizedQuicksort(arr,pi+1,high);
    }
}

void printArray(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    srand(time(0));
    vector<int>arr1 = {12,13,14,8,7,6,5,4,3};
    vector<int>arr2 = arr1;

    cout<<"\nOriginal array: ";
    printArray(arr1);

    cout<<"\nDetermintic quicksort: ";
    determinisiticQuicksort(arr1,0,arr1.size()-1);
    printArray(arr1);

    cout<<"\nRandomized quicksort: ";
    randomizedQuicksort(arr2,0,arr2.size()-1);
    printArray(arr2);

    return 0;
}