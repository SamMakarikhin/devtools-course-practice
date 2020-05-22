// Copyright 2020 Makarikhin Semen

#ifndef MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
#define MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_

#include <vector>

std::vector<int> Batcher(const std::vector<int>& vec1,
  const std::vector<int>& vec2);
std::vector<int> shuffle(const std::vector<int>& vec);
std::vector<int> merge_odd_even(const std::vector<int>& vec1,
  const std::vector<int>& vec2);
std::vector<int> unshuffle(const std::vector<int>& odd,
  const std::vector<int>& even);

#endif  // MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
