// Copyright 2020 Makarikhin Semen

#include "include/odd_even_batcher_merge.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> Batcher(const std::vector<int>& in_vec1,
  const std::vector<int>& in_vec2) {
  std::vector<int> vec1 = Shuffle(in_vec1);
  std::vector<int> vec2 = Shuffle(in_vec2);
  std::size_t size_odd1 = vec1.size() / 2 + vec1.size() % 2;
  std::size_t size_odd2 = vec2.size() / 2 + vec2.size() % 2;

  std::vector<int> odd1(vec1.begin(), vec1.begin() + size_odd1);
  std::vector<int> odd2(vec2.begin(), vec2.begin() + size_odd2);
  std::vector<int> even1(vec1.begin() + size_odd1, vec1.end());
  std::vector<int> even2(vec2.begin() + size_odd2, vec2.end());

  std::vector<int> OddMerge(OddEvenMerge(odd1, odd2));
  std::vector<int> EvenMerge(OddEvenMerge(even1, even2));
  std::vector<int> res(Unshuffle(OddMerge, EvenMerge));
  return res;
}

std::vector<int> Shuffle(const std::vector<int>& vec) {
  std::vector<int> tmp(vec.size());
  for (std::size_t i = 0; i < vec.size() / 2 + vec.size() % 2; i++) {
    tmp[i] = vec[2 * i];
  }
  for (std::size_t i = 1; i < vec.size(); i += 2) {
    tmp[vec.size() / 2 + vec.size() % 2 + i / 2] = vec[i];
  }
  return tmp;
}

std::vector<int> OddEvenMerge(const std::vector<int>& vec1,
  const std::vector<int>& vec2) {
  std::vector<int> res(vec1.size() + vec2.size());
  std::size_t j = 0, k = 0, l = 0;

  while (j < vec1.size() && k < vec2.size()) {
    if (vec1[j] < vec2[k])
      res[l++] = vec1[j++];
    else
      res[l++] = vec2[k++];
  }

  while (j < vec1.size())
    res[l++] = vec1[j++];
  while (k < vec2.size())
    res[l++] = vec2[k++];
  return res;
}

std::vector<int> Unshuffle(const std::vector<int>& odd,
  const std::vector<int>& even) {
  std::vector<int> res(odd.size() + even.size());
  std::size_t j = 0, k = 0, l = 0;

  while (j < odd.size() && k < even.size()) {
    res[l++] = odd[j++];
    res[l++] = even[k++];
  }

  while (j < odd.size())
    res[l++] = odd[j++];

  for (size_t i = 1; i < res.size() - 1; i += 2) {
    if (res[i] > res[i + 1])
      std::swap(res[i], res[i + 1]);
  }

  return res;
}
