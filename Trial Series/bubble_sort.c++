#include<iostream>
using namespace std;

int main(){
    int n;
    int temp;
    cout<<"enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"the new sorted array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }

}