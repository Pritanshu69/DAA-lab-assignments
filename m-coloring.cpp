#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

//function to check if the current colour assessment is safe or not
bool isSafe(int v,const vector<vector<int>> &graph, const vector<int> &color, int c){
    for(int i=0;i<graph.size();i++){
        if(graph[v][i] && color[i]==c){
            return false;
        }
    }
    return true;
}

//recursive util to solve the m-coloring
bool graphColoringUtil(const vector<vector<int>> &graph, int m, vector<int> &color, int v){
    if(v==graph.size()){
        return true;
    }
    for(int c=1;c<=m;c++){
        if(isSafe(v,graph,color,c)){
            color[v]=c;

            if(graphColoringUtil(graph,m,color,v+1)){
                return true;
            }
            color[v]=0;
        }
    }
    return false;
}
bool graphColoring(const vector<vector<int>> &graph, int m){
    vector<int> color(graph.size(), 0);

    if(!graphColoringUtil(graph,m,color,0)){
        cout<<"no soluton"<<endl;
        return false;
    }
    cout<<"solution: \n";
    for(int i=0;i<graph.size();i++){
        cout<<"Vertex: "<<i<<"-->color: "<<color[i]<<endl;
    }
    return true;
}
int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, 3);

    return 0;
}