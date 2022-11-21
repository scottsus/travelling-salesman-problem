
#include <bits/stdc++.h>
using namespace std;
#define V 4
#include <fstream>
vector<int> vertex;
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][25], int s)
{
    // store all vertex apart from source vertex
    
    for (int i = 0; i < 25; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        //cout<<graph[k][s]<<" ";
        // update minimum
        min_path = min(min_path, current_pathweight);
        

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Driver Code
int main()
{
    // matrix representation of graph
//     int graph[][V] = { { 0, 10, 15, 20 },
//                     { 10, 0, 35, 25 },
//                     { 15, 35, 0, 30 },
//                     { 20, 25, 30, 0 } };

    ifstream file { "data.txt" };
    if (!file.is_open()) return -1;

    int graph [25][25]{};
    for (int i{}; i != 25; ++i) {
        for (int j{}; j != 25; ++j) {
          file >> graph[i][j];
          cout<<graph[i][j]<<" ";
     }
     cout<<endl<<endl;
    }
    
    int s = 0;
    cout << endl<<travllingSalesmanProblem(graph, s) << endl;

    return 0;
}

