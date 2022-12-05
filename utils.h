#ifndef TSP_H_
#define TSP_H_

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int V;

std::vector<int> init_distance_matrix(int n)
{
    V = n;
	char filename[20];
	sprintf(filename, "data%d.txt", n);
	cout << "Opening " << filename << "..." << endl;

	ifstream file;
    file.open(filename);
    if (!file.is_open()){
        cout << "Incorrect filename" << endl;
		vector<int> null;
        return null;
    }

    int graph[V][V];
    for (int i = 0; i != V; i++) {
        for (int j = 0; j != V; j++)
          file >> graph[i][j];
    }

 	std::vector<int> distances(V * V);
    for (int from = 0; from < V; from++) {
        for (int to = 0; to < V; to++)
            distances[to + V * from] = graph[to][from];
    }

  	return distances;
} 


std::vector<int> init_distance_matrix_small(int n)
{
  auto distances = init_distance_matrix(n);
  std::vector<int> distances_small(V * V);
  for (int from = 0; from < n; from++)
  {
  	for (int to = 0; to < n; to++)
    	distances_small[to + V * from] = distances[to + V * from];
  }
  return distances_small;

} 

#endif

