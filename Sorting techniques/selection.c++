#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements in  the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }

    cout<<"printing the sorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}