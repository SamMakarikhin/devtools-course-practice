// Copyright 2020 Makarikhin Semen

#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include "include/odd_even_batcher_merge.h"

TEST(Odd_Even_Batcher_Merge, Merge_Zero_Size_Vec) {
  std::vector<int> vec1;
  std::vector<int> vec2{ 1, 6, 12 };

  std::vector<int> vec3 = Batcher(vec1, vec2);
  ASSERT_EQ(vec2, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Ordered_Vec) {
  std::vector<int> vec1{ 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> vec2{ 9, 10, 11, 12, 13 };
  std::vector<int> res{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

  std::vector<int> vec3 = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Vec_One_Size_Elem) {
  std::vector<int> vec1{ 1 };
  std::vector<int> vec2{ 2 };
  std::vector<int> res{ 1, 2 };

  std::vector<int> vec3 = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Vec_With_Negative_Elem) {
  std::vector<int> vec1{ -17, -3, 5, 2 };
  std::vector<int> vec2{ -11, 3, 5, 23, 51 };
  std::vector<int> res{ -17, -11, -3, 2, 5, 3, 5, 23, 51 };

  std::vector<int> vec3 = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Vec_With_Repeat_Elem) {
  std::vector<int> vec1{ 1, 1, 1, 1 };
  std::vector<int> vec2{ 2, 2, 2, 2, 2 };
  std::vector<int> res{ 1, 1, 1, 1, 2, 2, 2, 2, 2 };

  std::vector<int> vec3 = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}


TEST(Odd_Even_Batcher_Merge, Merge_Vec_Same_Length) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));

  std::size_t length = 20;
  std::vector<int> vec1(length);
  std::vector<int> vec2(length);

  for (auto& val : vec1) {
    val = gen() % 100;
  }
  for (auto& val : vec2) {
    val = gen() % 100;
  }

  std::vector<int> vec3(length * 2);
  std::copy(vec1.begin(), vec1.end(), vec3.begin());
  std::copy(vec2.begin(), vec2.end(), vec3.begin() + length);
  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());
  std::sort(vec3.begin(), vec3.end());

  std::vector<int> res = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Vec_Odd_Length) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));

  std::size_t length1 = 7;
  std::size_t length2 = 21;
  std::vector<int> vec1(length1);
  std::vector<int> vec2(length2);

  for (auto& val : vec1) {
    val = gen() % 100;
  }
  for (auto& val : vec2) {
    val = gen() % 100;
  }

  std::vector<int> vec3(length1 + length2);
  std::copy(vec1.begin(), vec1.end(), vec3.begin());
  std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());
  std::sort(vec3.begin(), vec3.end());

  std::vector<int> res = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Vec_Even_Length) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));

  std::size_t length1 = 8;
  std::size_t length2 = 16;
  std::vector<int> vec1(length1);
  std::vector<int> vec2(length2);

  for (auto& val : vec1) {
    val = gen() % 100;
  }
  for (auto& val : vec2) {
    val = gen() % 100;
  }

  std::vector<int> vec3(length1 + length2);
  std::copy(vec1.begin(), vec1.end(), vec3.begin());
  std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());
  std::sort(vec3.begin(), vec3.end());

  std::vector<int> res = Batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}

TEST(Odd_Even_Batcher_Merge, Merge_Big_Vec) {
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));

  std::size_t length1 = 700;
  std::size_t length2 = 700;
  std::vector<int> vec1(length1);
  std::vector<int> vec2(length2);

  for (auto& val : vec1) {
    val = gen() % 1000;
  }
  for (auto& val : vec2) {
    val = gen() % 1000;
  }

  std::vector<int> vec3(length1 + length2);
  std::copy(vec1.begin(), vec1.end(), vec3.begin());
  std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
  std::sort(vec1.begin(), vec1.end());
  std::sort(vec2.begin(), vec2.end());
  std::sort(vec3.begin(), vec3.end());

  std::vector<int> res = merge_batcher(vec1, vec2);
  ASSERT_EQ(res, vec3);
}
