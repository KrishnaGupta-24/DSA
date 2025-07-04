#include<bits/stdc++.h>
using namespace std;
int part(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while (arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pindex=part(arr,low,high);
        qs(arr,low,pindex-1);
        qs(arr,pindex+1,high);
    }
}
int main(){
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    cout<<"enter the elements of the array";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    qs(arr,0,n-1);
    cout<<"printing the sorted array";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}