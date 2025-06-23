int findFloor(vector<int>& arr, int k) {
    int min=-1;
    int low=0;
    int high=arr.size();
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<=k){
            min=mid;
            low=mid+1;
        }
        
        else{
            high=mid-1;
        }
    }
    
    return min;
}
