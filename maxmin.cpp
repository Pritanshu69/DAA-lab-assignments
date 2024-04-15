#include<iostream>
using namespace std;

void minMax(int arr[],int right, int left, int& minVal, int& maxVal){
    if(right==left){           //ANCHOR -  for single element
        minVal == arr[left];
        maxVal == arr[right];
        return;
    }
    else if(right == left+1){
        if(arr[right]>arr[left]){
            minVal = arr[left];
            maxVal = arr[right];
        }
        else{
            minVal = arr[right];
            maxVal = arr[left];
        }
    }
    else{
        int mid = left + (right - left)/2;   //Finding the middle element of array.
        int leftMin, leftMax, rightMin, rightMax;

        minMax(arr, left, mid, leftMin, leftMax);
        minMax(arr, mid+1,  right, rightMin, rightMax);

        minVal = std ::min(leftMin, leftMax);
        maxVal = std ::min(rightMin, rightMax);
    }
}

int min(){
    int n;
    cout << "Enter size of array: ";
    cin>> n;

    int arr[n];
    cout<<"Enter elements of array:"<<endl;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        int minVal,maxVal;
        minMax(arr,0,n-1,minVal,maxVal);
             
            cout << "minimum element"<<minVal<<endl;
            cout << "maximum element"<<maxVal<<endl;

            return 0;
    }
};