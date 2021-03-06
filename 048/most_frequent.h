#include <algorithm>
#include <map>
#include <vector>

template <typename T>
std::vector<std::pair<T, size_t>> find_most_frequent(const std::vector<T>& set)
{
  std::map<T, size_t /*, std::greater<T>*/> map;
  size_t max = 0;

  for (auto&& i : set)
  {
    // mapの要素をキーに登場した要素の回数をカウントしていく
    map[i] += 1;

    // if (max < map[i])
    //   max = map[i];
  }

  std::vector<std::pair<T, size_t>> result;
  // for (auto i = map.begin(); i != map.end(); i++)
  // {
  //   if (i->second == max)
  //     result.push_back(std::make_pair(i->first, i->second));
  // }

  // std::mapのAllocatorがstd::pairを標準にしているため、
  // 引数(i1,i2)はstd::pair<const Key, T>型になる。
  auto first_max = std::max_element(
      map.begin(), map.end(),
      [](const auto i1, const auto i2) { return i1.second < i2.second; });

  max = first_max->second;

  std::copy_if(map.begin(), map.end(), std::back_inserter(result),
               [&max](const auto i) { return max == i.second; });

  return result;
}