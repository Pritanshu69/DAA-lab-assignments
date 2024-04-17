#include<iostream>
using namespace std;

struct job{
    char id;
    int deadline;
    int profit;
};
void swap(job& a, job& b){
    job temp = a;
    a = b;
    b = temp;
}
void sortJobsByProfit(job arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j].profit<arr[j+1].profit){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printJobSchedule(job arr[],int n){
    sortJobsByProfit(arr,n);
    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++)
        slot[i]=false;

        for(int i=0;i<n;i++){
            for(int j=std::min(n,arr[i].deadline)-1;j>=0;j--){
                if(!slot[j]){
                    result[j]=i;
                    slot[j]=true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(slot[i])
                cout<<arr[result[i]].id<<" ";
        }
        cout<<endl;
    }
int main(){
     job arr[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The maximum profit sequence of jobs is: ";
    printJobSchedule(arr, n);

    return 0;
    
}