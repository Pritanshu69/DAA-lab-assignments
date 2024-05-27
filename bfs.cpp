#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

const int MAX_VERTICES = 6;

void bfs(int startVertex,int adj[MAX_VERTICES][MAX_VERTICES],int num){
    queue<int>q;
    bool visited[MAX_VERTICES] = {false};

    visited[startVertex]=true;
    q.push(startVertex);

    while(!q.empty()){
        int currenVertex =q.front();
        q.pop();
        cout<<"visited-> "<<currenVertex<<endl;

        for(int adjVertex=0;adjVertex<num;++adjVertex){
            if(adj[currenVertex][adjVertex]!=1 && !visited[adjVertex]){
                visited[adjVertex]=true;
                q.push(adjVertex);
            }
        }
    }
}
int main(){
    int adj[MAX_VERTICES][MAX_VERTICES];
    int num=MAX_VERTICES;

    ifstream inputFile("bfs.txt");
    if(!inputFile){
        cout<<"Error"<<endl;
    }
    for(int i=0;i<num;++i){
        for(int j=0;j<num;++j){
            inputFile>>adj[i][j];
        }
    }
    inputFile.close();

    bfs(0,adj,num);
    return 0;
    // cout<<"BFS starting from vertex 0:\n"<<"visited-> 0\n"<<endl;
}   