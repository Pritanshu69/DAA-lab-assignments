#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;

    int choice;
    while(true){
        cout<<"\nPriority Queue operations\n";
        cout<<"1. Insert Elements\n";
        cout<<"2. Extract Max element\n";
        cout<<"3. Display Max element\n";
        cout<<"4. Display Size\n";
        cout<<"5. Check if empty\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1){
            int element;
            cout<<"Enter an element: \n";
            cin>>element;
            pq.push(element);
            cout<<"Inserted\n";
        }
        else if(choice==2){
            if(!pq.empty()){
                cout<<"top element: "<<pq.top()<<endl;
                pq.pop();
            }
            else{
                cout<<"Queue is empty"<<endl;
            }
        }
        else if(choice==3){
            if(!pq.empty()){
                cout<<"top element: "<<pq.top()<<endl;
            }
            else{
                cout<<"Queue is empty"<<endl;
            }
        }
        else if(choice==4){
            cout<<"Size: "<<pq.size()<<endl;
        }
        else if(choice==5){
            if(pq.empty()){
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<"Queue is not empty"<<endl;
            }
        }
        else if(choice == 6){
            break;
        }
        else{
            cout<<"invalid choice"<<endl;
        }
    }
    return 0;
}