#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999
#define NUM_NODES 15

int input_graph(size_t, int (*a)[*], const char *);
int find_min_cost_tour(int **, int *, int, int, int);
int bellman_held_karp(int **, int *, int, int, int);

int main(int argc, char **argv)
{
    int graph[NUM_NODES][NUM_NODES];
    if (input_graph(NUM_NODES, graph, "data.txt") != 0)
    {
        printf("Error reading from file\n");
        return 1;
    }
    int visited[NUM_NODES];
    int limit, cost = 0;
    int min_cost_tour = find_min_cost_tour(graph, visited, limit, cost, 0);
    printf("Cost of shortest tour: %d\n", min_cost_tour);
    return 0;
}

int bellman_held_karp(int **graph, int *visited, int limit, int cost, int city)
{
    int temp, nearest_city = INFINITY, min = INFINITY;
    for (int count = 0; count < limit; count++)
    {
        if ((graph[city][count] != 0) && (visited[count] == 0))
        {
            if (graph[city][count] < min)
            {
                min = graph[count][0] + graph[city][count];
            }
            temp = graph[city][count];
            nearest_city = count;
        }
    }
    if (min != INFINITY)
    {
        cost += temp;
    }
    return nearest_city;
}

int find_min_cost_tour(int **graph, int *visited, int limit, int cost, int city)
{
    visited[city] = 1;
    int nearest_city = tsp(city);
    if (nearest_city == INFINITY)
    {
        nearest_city = 0;
        cost = cost + graph[city][nearest_city];
        return cost;
    }
}

int input_graph(size_t n, int (*a)[n], const char *filename)
{
    FILE *datafile;
    datafile = fopen(filename, "r");
    if (datafile == NULL)
    {
        printf("data.txt not found\n");
        return 1;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            fscanf(datafile, "%d", a[i] + j);
        }
    }
    fclose(datafile);
    return 0;
}