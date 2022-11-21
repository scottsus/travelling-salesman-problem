#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define NUM_NODES 15

int input_graph(size_t, int (*a)[*], const char *);
void find_min_cost_tour(int);
int bellman_held_karp(int);
void log_graph(int[NUM_NODES][NUM_NODES]);

int graph[NUM_NODES][NUM_NODES];
int visited[NUM_NODES];
int limit = NUM_NODES, cost = 0;

int main(int argc, char **argv)
{
    if (input_graph(NUM_NODES, graph, "data.txt") != 0)
    {
        printf("Error reading from file\n");
        return 1;
    }
    log_graph(graph);
    printf("\nPath: ");
    find_min_cost_tour(0);
    printf("\nCost of shortest tour: %d\n", cost);
    return 0;
}

int bellman_held_karp(int city)
{
    int count, nearest_city = INFINITY;
    int min = INFINITY, temp;
    for (int count = 0; count < limit; count++)
    {
        if ((graph[city][count] != 0) && (visited[count] == 0))
        {
            if (graph[city][count] < min)
            {
                min = graph[city][count];
                temp = graph[city][count];
                nearest_city = count;
            }
        }
    }
    if (min != INFINITY)
    {
        cost += temp;
    }
    return nearest_city;
}

void find_min_cost_tour(int city)
{
    visited[city] = 1;
    printf("%d ", city);
    int nearest_city = bellman_held_karp(city);
    if (nearest_city == INFINITY)
    {
        nearest_city = 0;
        printf("%d ", nearest_city);
        cost += graph[city][nearest_city];
        return;
    }
    find_min_cost_tour(nearest_city);
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
        visited[i] = 0;
    }
    fclose(datafile);
    return 0;
}

void log_graph(int graph[NUM_NODES][NUM_NODES])
{
    printf("Printing Graph...\n");
    for (int i = 0; i < NUM_NODES; i++)
    {
        for (int j = 0; j < NUM_NODES; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}