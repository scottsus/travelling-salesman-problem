# Travelling Salesman Problem


## Introduction

From an undergraduate perspective, a problem without an efficient solution would be one that lies in the NP-Complete space, an ideal target for parallel implementations to accelerate. One such instance would be the Travelling Salesman Problem (TSP), which has an algorithmic time complexity of O(N!) and space complexity of O(N<sup>2</sup>). Formally, the TSP is defined as follows: given a weighted, directed, non-negative graph, is it possible to find the path of least cost that visits all the vertices in the graph and returns to the origin? Effectively, we’re trying to find the value and route of the shortest Hamiltonian Cycle.

Importantly, the TSP is a pervasive problem that appears very frequently in route planning, logistics, microchip manufacturing, DNA sequencing, and so many more. Its O(N!) serial time complexity means that modern computers are unable to solve inputs of more than 14 nodes in a realistic amount of time. Because of its time complexity, algorithms experts have designed numerous algorithms to attempt to solve the problem.

<img width="531" alt="image" src="https://user-images.githubusercontent.com/88414565/205586085-9f612c7f-3e35-423b-9a56-199cc8c7f363.png">


## Serial Brute Force and Parallelization Strategy

Before beginning the experiment, it would be prudent to understand why the serial brute force approach has such a nasty O(N!) time complexity, and what we’re doing to parallelize the serial approach. Essentially, we are generating every possible permutation for a list of cities that we could traverse and calculating the costs of travelling that permutation, and finding the minimum cost across all permutations.

Hence, an intuitive yet non-trivial approach would be to spawn a new thread at each decision branch, with each child thread responsible for aggregating the minimum cost across the remaining paths having taken that particular route in the algorithm. At the end of the execution, the main thread would reduce a list of costs and return the lowest cost of all the possible routes, solving the TSP in a parallel fashion.


## Hypothesis

This brings us to our hypothesis. While the serial brute force approach could only solve a 14x14 input graph in a realistic amount of time, we believe that a parallel brute force approach could solve larger problem sizes in a realistic amount of time. More formally, our hypothesis is given as follows:

“Parallelized Brute Force allows us to process input graphs of sizes of 14, 15, and 16, while maintaining the O(N2) time complexity in a realistic amount of time (10 mins).”


## Usage
Go to the CARC Terminal and run the following commands:
```
salloc --time=2:00:00 --cpus-per-task=16
```
```
export OMP_NUM_THREADS=32
```
```
make && ./tsp X
```
where X is the size of the input graph, 10 <= X <= 16

## Experimental Results
The following table shows the results for our serial vs parallel brute force approach for different problem sizes:
<img width="545" alt="image" src="https://user-images.githubusercontent.com/88414565/205585938-4bc94a1e-6c8f-479d-b1dc-b93d826e3ee2.png">


## Analysis
We were able to successfully process a 14x14 input graph in 197s, a little above 3 minutes, well below our own definition of realistic amount of time. However, even with parallelization and additional CPUs from CARC, we were still unable to process graphs of size 15x15 or larger as it took way too long.

As a result, we found some support for our initial hypothesis, achieving massive speedup in the 14x14 input graph. It is highly likely that we would see a much larger speedup in larger problem sizes, but given how large they are, it is unlikely that those speedups would be useful in any practical way. In that sense, we did not find support in our hypothesis.

## Additional Info
Our complete report can be found in the [PDF](https://github.com/susantoscott/travelling-salesman-problem/blob/master/EE451%20Final%20Project%20Report.pdf) in this repository. Thank you for reading!
