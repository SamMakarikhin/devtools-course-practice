// Copyright 2020 Vladislav Golubev

#include <gtest/gtest.h>
#include <vector>
#include "include/distance_between_vectors.h"

class DistanceBetweenVectorsTest : public ::testing::Test {
 protected:
  double epsilon = 0.001;
};

TEST(DistanceBetweenVectorsTest, default_first_vec) {
  // Arrange
  std::vector<float> defaultVec(1);
  // Act
  Metrics metrics;

  // Assert
  EXPECT_EQ(metrics.getFirst(), defaultVec);
}

TEST(DistanceBetweenVectorsTest, default_sec_vec) {
  // Arrange
  std::vector<float> defaultVec(1);

  // Act
  Metrics metrics;

  // Assert
  EXPECT_EQ(metrics.getSecond(), defaultVec);
}

TEST(DistanceBetweenVectorsTest, create_with_two_vectors) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };

  // Act
  Metrics metrics(first, second);

  // Assert
  EXPECT_EQ(metrics.getFirst(), first);
  EXPECT_EQ(metrics.getSecond(), second);
}

TEST(DistanceBetweenVectorsTest, cannot_create_for_vec_of_different_div) {
  // Arrange
  int div1 = 5;
  int div2 = 10;
  std::vector<float> first(div1);
  std::vector<float> second(div2);

  // Act & Assert
  ASSERT_ANY_THROW(Metrics metrics(first, second));
}
