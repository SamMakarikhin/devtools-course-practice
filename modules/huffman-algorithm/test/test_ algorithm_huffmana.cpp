// Copyright 2020 Poletueva Anastasia

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/algorithm_huffmana.h"

TEST(AlgorithmHuffmanaTest, Can_Create_Histoghram_1) {
  // Arrange
  std::string text = "AAASREESR";

  // Act
  std::vector<int> v = HuffmanTree().CreateHistogram(text);

  // Assert
  EXPECT_EQ(3, v['A']);
  EXPECT_EQ(2, v['S']);
  EXPECT_EQ(2, v['R']);
  EXPECT_EQ(2, v['E']);
}

TEST(AlgorithmHuffmanaTest, Can_Create_Histoghram_2) {
  // Arrange
  std::string text = "AAARAARRREREESRR";

  // Act
  std::vector<int> v = HuffmanTree().CreateHistogram(text);
  HuffmanTree a(text);

  // Assert
  EXPECT_EQ(5, v['A']);
  EXPECT_EQ(1, v['S']);
  EXPECT_EQ(7, v['R']);
  EXPECT_EQ(3, v['E']);
}



TEST(AlgorithmHuffmanaTest, Can_Create_Encoding_Table_1) {
  // Arrange
  std::string text = "AAASAAAAREEAAAAAAAAAAASR";
  std::string expect = "1";

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(expect, Tree.getSimbolCode('A'));
}

TEST(AlgorithmHuffmanaTest, Can_Create_Encoding_Table_2) {
  // Arrange
  std::string text = "AASRRR";
  std::string expect = "1";

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(expect, Tree.getSimbolCode('R'));
}

TEST(AlgorithmHuffmanaTest, Huffman_Coding_Test_1) {
  // Arrange
  std::string text = "AAASRERASR";
  std::vector<std::string> vec = { "1", "1", "1",
    "001", "01", "0001", "01", "1", "001", "01"};

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(vec, Tree.Encode(text));
}

TEST(AlgorithmHuffmanaTest, Huffman_Coding_Test_2) {
  // Arrange
  std::string text = "AAASRERTWTASR";
  std::vector<std::string> vec = { "01", "01", "01",
    "000", "10", "111", "10", "001", "1101", "001",
    "01", "000", "10" };

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(vec, Tree.Encode(text));
}
