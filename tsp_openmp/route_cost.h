#ifndef ROUTE_COST_H_
#define ROUTE_COST_H_

#include <cstdint>
#include <limits>


struct route_cost
{
  int64_t route;
  int cost;

  route_cost()
    : route(-1),
      cost(std::numeric_limits<int>::max())
  { }

  route_cost(int64_t route, int cost)
    : route(route),
      cost(cost)
  { }

  static
  route_cost min(const route_cost& first, const route_cost& second)
  {
    if (first.cost < second.cost)
    {
      return first;
    }
    return second;
  }

};

#endif 