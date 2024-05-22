#include<iostream>
#include<queue>

using namespace std;

const int MAX_VERTICES = 6;

void bfs(int startVertex, int adj[MAX_VERTICES][MAX_VERTICES],int num){
    bool visited[MAX_VERTICES]={false};
    queue<int> q; //queue 

    visited[startVertex]=true;
    q.push(startVertex);

    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        cout<<"Visited  "<<currentVertex<<endl;

        //explore all other vertices
        for(int adjVertex=0;adjVertex<num;++adjVertex){
            if(adj[currentVertex][adjVertex]==1 && !visited[adjVertex]){
                visited[adjVertex]=true;
                q.push(adjVertex);
            }
        }
    }
}

int main(){
    int adj[MAX_VERTICES][MAX_VERTICES]={
        {0, 1, 1, 0, 0, 0}, // Vertex 0 is connected to Vertex 1 and 2
        {1, 0, 0, 1, 1, 0}, // Vertex 1 is connected to Vertex 0, 3, and 4
        {1, 0, 0, 0, 0, 1}, // Vertex 2 is connected to Vertex 0 and 5
        {0, 1, 0, 0, 0, 0}, // Vertex 3 is connected to Vertex 1
        {0, 1, 0, 0, 0, 1}, // Vertex 4 is connected to Vertex 1 and 5
        {0, 0, 1, 0, 1, 0}  // Vertex 5 is connected to Vertex 2 and 4
    };
    int num = 6;
    int startVertex = 0;

    cout<<"bfs from first"<<startVertex<<endl;
      bfs(startVertex, adj, num);

      return 0;
}
