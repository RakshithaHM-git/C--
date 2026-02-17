#include <iostream>
using namespace std;

int main() {
    int g[7][7] = {0}, indeg[7] = {0};

    // Edges
    g[5][2]=1; g[5][1]=1;
    g[2][4]=1; g[2][6]=1;
    g[1][6]=1;
    g[4][3]=1; g[6][3]=1;

    // Calculate indegree
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            if(g[i][j]) indeg[j]++;

    cout << "Topological Order: ";

    for(int k=1;k<=6;k++){
        for(int i=1;i<=6;i++){
            if(indeg[i]==0){
                cout << i << " ";
                indeg[i] = -1;  // visited
                for(int j=1;j<=6;j++)
                    if(g[i][j]) indeg[j]--;
            }
        }
    }
    return 0;
}