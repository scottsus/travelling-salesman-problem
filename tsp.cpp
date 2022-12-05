#include "route_iterator.h"
#include "route_cost.h"
#include "utils.h"
#include "timer.h"

#include <cstdio> 
#include <cstdlib> 
#include <iostream>

template<int N>
route_cost find_best_route(int const* distances)
{
  	int64_t num_routes = factorial(N);

	#pragma omp declare reduction(route_min : route_cost : omp_out = route_cost::min(omp_out, omp_in)) \
  		initializer(omp_priv = route_cost())
  	route_cost best_route;

	#pragma omp parallel for reduction(route_min : best_route)
  	for (int64_t i = 0; i < num_routes; ++i)
  	{
    	int cost = 0;
    	route_iterator<N> itr(i);
    	int from = itr.first();

		while (!itr.done())
   		{
   			int to = itr.next();
   			cost += distances[to + N*from];
   			from = to;
   		}
   		best_route = route_cost::min(best_route, route_cost(i, cost));
	}
  	return best_route;
}


template <int N>
void tsp(int nbRepeat = 1)
{

  	auto distances_small = init_distance_matrix_small(N);
  	route_cost best_route;

  	SimpleTimer timer;
  	timer.start();
  	for (int i = 0; i<nbRepeat; ++i)
    	best_route = find_best_route<N>(distances_small.data());
  	timer.stop();
  	double time = timer.elapsedSeconds()/nbRepeat;

  	printf("Travelling Salesman Problem for input graph %dx%d\n", N, N);
	printf("The best route incurs cost: %d\n", best_route.cost);
	printf("Execution time: %f seconds\n", time);
  	
	route_iterator<N> itr(best_route.route);
  	itr.print();
} 


int main(int argc, char* argv[])
{
  	int n = 8;
  	if (argc == 2)
    	n = atoi(argv[1]);

	// if n is small:
		// run tsp 10,000 times
		// and average the execution time
	// else:
		// run the program once
	
  	if (n == 4)
    	tsp<4>(10000);
  	else if (n == 5)
      	tsp<5>(10000);
  	else if (n == 6)
      	tsp<6>(1000);
  	else if (n == 7)
    	tsp<7>(1000);
  	else if (n == 8)
    	tsp<8>(100);
  	else if (n == 9)
    	tsp<9>(10);
  	else if (n == 10)
    	tsp<10>();
  	else if (n == 11)
    	tsp<11>();
  	else if (n == 12)
    	tsp<12>();
  	else if (n == 13)
    	tsp<13>();
  	else if (n == 14)
    	tsp<14>();
  	else if (n == 15)
    	tsp<15>();
 	else if (n == 16)
    	tsp<16>();

  return 0;
}

