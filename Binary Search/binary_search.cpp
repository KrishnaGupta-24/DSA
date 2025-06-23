#include<bits/stdc++.h>
using namespace std;
int fun(int arr[], int tar,int low,int high){
  
    int mid=(low+high)/2;
    if(arr[mid]==tar){
        return -1;
    }
    if(arr[mid]>tar){
        return fun(arr,tar,low,mid-1);
    }
    else{
        return fun(arr,tar,mid+1,high);
    }
}
int main(){
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tar;
    cout<<"enter the targeted element";
    cin>>tar;
    int ans=fun(arr,tar,0,n-1);    
    if(ans==-1){
        cout<<"element found";
    }
    else{
        cout<<"elemnet not found";
    }
}