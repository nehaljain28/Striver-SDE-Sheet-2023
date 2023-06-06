int search(int* arr, int n, int key) {
    // Write your code here.
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)return mid;
        if(arr[mid]>=arr[l])
        {
            if(arr[l]<=key&&arr[mid]>=key)r=mid-1;
            else l=mid+1;
        }
        else
        {
            if(arr[mid]<=key&&arr[r]>=key)l=mid+1;
            else r=mid-1;
        }
    }
    return -1;
}
