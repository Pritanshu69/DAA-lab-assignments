#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

const int MAX=6;

void dfs(int startVertex, int adj[MAX][MAX]){
    bool visited[MAX]={false};
    stack<int>s;
    s.push(startVertex);

    while(!s.empty()){
        int vertex = s.top();
        s.pop();

        if(!visited[vertex]){
            cout<<"Visited"<<vertex<<endl;
            visited[vertex]=true;
        }
        for(int adjvertex=MAX-1;adjvertex>=0;--adjvertex){
            if(adj[vertex][adjvertex] && !visited[adjvertex]){
                s.push(adjvertex);
            }
        }
    }
}
int main() {
    int adj[MAX][MAX];
    ifstream inputFile("dfs.txt");

    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Read the adjacency matrix from the file
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            inputFile >> adj[i][j];
        }
    }
    inputFile.close();

    // Perform DFS starting from vertex 0
    cout << "DFS starting from vertex 0:" << endl;
    dfs(0, adj);

    return 0;
}