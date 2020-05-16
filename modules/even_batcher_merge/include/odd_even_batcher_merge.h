// Copyright 2020 Makarikhin Semen

#ifndef MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
#define MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_

#include <vector>

std::vector<int> Batcher(std::vector<int> vec1,
  std::vector<int> vec2);
std::vector<int> Shuffle(const std::vector<int>& vec);
std::vector<int> OddEvenMerge(const std::vector<int>& vec1,
  const std::vector<int>& vec2);
std::vector<int> Unshuffle(const std::vector<int>& odd,
  const std::vector<int>& even);

#endif  // MODULES_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
