tsp_gnu_openmp: tsp.cpp tsp_utils.h route_cost.h route_iterator.h
	g++ -std=c++17 -Wall -march=native -O3 -fopenmp $< -o $@

	
all: tsp_gnu_openmp
