#ifndef ROUTE_ITERATOR_H_
#define ROUTE_ITERATOR_H_

#include <cstdint>
#include <cstdio>
#include <inttypes.h>
#include <cassert>

uint64_t factorial(uint64_t n)
{
    if (n <= 1)
    	return 1;
    return n * factorial(n - 1);
}

void integer_divide(uint64_t original, uint64_t divisor, uint64_t& quotient, uint64_t& remainder)
{
	quotient = original / divisor;
  	remainder = original - divisor * quotient;
}

template <typename T>
void swap(T& a, T& b)
{
    T c(a); a = b; b = c;
}

template <int N>
class route_iterator
{
public:
  	route_iterator(uint64_t route_id);

  	bool done() const {
  		return m_i == (N - 1);
	};

  	int first() {
		m_i = 0;
		return state[0];
	};

  	int next() {
		m_i++;
		return state[m_i];
	};

  	void print();

private:
  	uint64_t route_id;
  	int m_i;
  	int state[N];

};

template<int N>
route_iterator<N>::route_iterator(uint64_t route_id)
  : route_id(route_id),
    m_i(0)
{
  assert(route_id < factorial(N));

  	for (int k = 0; k < N; ++k)
    	state[k] = -1;

  	for (int k = 0; k < N; ++k)
    	state[k] = k;


  	assert(N >= 2);

  	int divisor = 1;
 	uint64_t iter = route_id;
  	for(int k = 1; k < N; ++k)
  	{

    	uint64_t quotient, remainder;
    	integer_divide(iter/divisor, k + 1, quotient, remainder);

    	if (remainder > 0)
      		swap(state[k], state[k - remainder]);
    	divisor *= (k + 1);
  	}
}

template<int N>
void route_iterator<N>::print()
{
	printf("Optimal Route:\n");
	for (int k=0; k<N; ++k)
    	printf("%2d ", state[k]);
  	printf("\n");
}

#endif

