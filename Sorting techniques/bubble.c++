#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of the array ";
    cin>>n;
    int arr[n];
    cout<<"enter the elemnets of the array ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"printing the sorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}