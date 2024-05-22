#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int v){
    for(int k=0;k<v;++k){
        for(int i=0;i<v;++i){
            for(int j=0;j<v;++j){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
//print the solution
void printSolution(const vector<vector<int>> &dist, int v){
    cout<<"shortest path for the paris: \n";
    for(int i=0;i<v;++i){
        for(int j=0;j<v;++j){
            if(dist[i][j]==INF){
                cout<<setw(7)<<"INF";
            }
            else{
                cout<<setw(7)<<dist[i][j];
            }
        }
        cout<<endl;
    }
}
int main(){
    int v=4;
    vector<vector<int>> dist = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    floydWarshall(dist, v);
    printSolution(dist,v);

    return 0;
}