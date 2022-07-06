/* 47. Most Frequent */

/*
 * keywords:
 * {Number, Times}.
 * - {1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5} -> {5,3}, {8,3}
 */
#include <chrono>
#include <iostream>

#include "most_frequent.h"

int main()
{
  auto range = std::vector<int>{
      1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8,
      5, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5, 1, 3, 5, 8, 13, 3, 5, 8, 8};

  auto start = std::chrono::system_clock::now().time_since_epoch();
  auto result = find_most_frequent(range);
  auto finish = std::chrono::system_clock::now().time_since_epoch();

  auto time_count =
      std::chrono::duration_cast<std::chrono::microseconds>(finish - start)
          .count();

  std::cout << "elapsed time: " << time_count << " us." << std::endl;

  for (auto const& e : result)
  {
    std::cout << e.first << " : " << e.second << std::endl;
  }
}