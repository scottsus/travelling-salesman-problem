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
    //ifstream file;
    V=n;
//
//    if (n==4){
//        file.open("data4.txt" );
//
//        V=4;
//    }
//    else if (n==7){
//        file.open("data7.txt" );
//        V=7;
//    }
//    else if (n==15){
//        file.open("data15.txt" );
//        V=15;
//    }
//    else if (n==22){
//        file.open("data22.txt" );
//        V=22;
//    }
//    else if (n==30){
//        file.open("data30.txt" );
//        V=30;
//    }
//    else if (n==57){
//        file.open("data57.txt" );
//        V=57;
//    }
ifstream file;

    if (n==30){
        file.open("data30.txt" );
    }
    else{
        file.open("data.txt" );
    }
    if (!file.is_open()){
        cout<<"NO DATA"<<endl;
        vector<int> null;
        return null;
    }

    int graph [V][V];
    for (int i{}; i != V; ++i) {
        for (int j{}; j != V; ++j) {
          file >> graph[i][j];
          //cout<<graph[i][j]<<" ";
     }
     //cout<<endl<<endl;
    }



  std::vector<int> distances(V*V);
    for (int from=0 ; from<V; from++ ){
        for (int to=0; to<V ; to++){
            distances[ to + V*from ]= graph[to][from];
            //cout<<distances[ to + V*from ]<< " ";
            
        }
        //cout<<endl;
    }
    


  return distances;

} // init_distance_matrix


std::vector<int> init_distance_matrix_small(int n)
{



  auto distances = init_distance_matrix(n);

  std::vector<int> distances_small(V*V);

  for (int from=0; from<n; ++from)
  {
    for (int to=0; to<n; ++to)
    {

      distances_small[to + V*from] = distances[to+ V*from];

    }
  }

  return distances_small;

} 

#endif // TSP_H_


