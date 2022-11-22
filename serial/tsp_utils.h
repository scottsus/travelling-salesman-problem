#ifndef TSP_H_
#define TSP_H_
#define V 22
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// ==================================================
// ==================================================
auto makeCityMap()
{
  std::map<std::string, int> city2index;

  city2index.insert(std::make_pair("Paris",0));
  city2index.insert(std::make_pair("Marseille",1));
  city2index.insert(std::make_pair("Bordeaux",2));
  city2index.insert(std::make_pair("Toulouse",3));
  city2index.insert(std::make_pair("Brest",4));
  city2index.insert(std::make_pair("Nantes",5));
  city2index.insert(std::make_pair("Lille",6));
  city2index.insert(std::make_pair("Metz",7));
  city2index.insert(std::make_pair("Nancy",8));
  city2index.insert(std::make_pair("Lyon",9));
  city2index.insert(std::make_pair("Clermont-Ferrand",10));
  city2index.insert(std::make_pair("Strasbourg",11));
  city2index.insert(std::make_pair("Tours",12));
  city2index.insert(std::make_pair("Limoges",13));

  return city2index;
}

// ==================================================
// ==================================================
std::vector<int> init_distance_matrix()
{
    
    ifstream file { "data.txt" };
    if (!file.is_open()){
        cout<<"NO DATA"<<endl;
        vector<int> null;
        return null;
    }

    int graph [V][V]{};
    for (int i{}; i != V; ++i) {
        for (int j{}; j != V; ++j) {
          file >> graph[i][j];
          //cout<<graph[i][j]<<" ";
     }
     //cout<<endl<<endl;
    }

  // distances à vol d'oiseau

  auto cityIndex = makeCityMap();
  auto size = cityIndex.size();

  std::vector<int> distances(size*size);
    for (int to=0 ; to<22; to++ ){
        for (int from=0; from<22 ; from++){
            distances[ to + V*from ]= graph[to][from];
        }
    }


  return distances;

} // init_distance_matrix

// ==================================================
// ==================================================
//! extract a smaller matrix for debug purpose
std::vector<int> init_distance_matrix_small(int n)
{

  auto cityIndex = makeCityMap();
  auto size = cityIndex.size();

  auto distances = init_distance_matrix();

  std::vector<int> distances_small(n*n);

  for (int from=0; from<n; ++from)
  {
    for (int to=0; to<n; ++to)
    {

      distances_small[to + n*from] = distances[to+size*from];

    }
  }

  return distances_small;

} // init_distance_matrix_small

#endif // TSP_H_


