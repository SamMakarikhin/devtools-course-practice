// Copyright 2020 Poletueva Anastasia

#ifndef MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_H_
#define MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_H_

#include<string>
#include<vector>
#include<stack>

struct HuffmanNode {
  HuffmanNode* left;
  HuffmanNode* right;
  unsigned char val;
  int freq;
};



class HuffmanTree {
  HuffmanNode* root;
  std::vector<std::string> encodingTable;

 public:
  explicit HuffmanTree(std::string s = "");
  void CreateEncodingTable();
  void CreateEncodingTable(HuffmanNode* node, std::string code,
    std::string direct);
  void SortQueue(std::vector<HuffmanNode*> *queue,
    const std::vector<int> & hist);
  std::string getSimbolCode(char val);
  std::vector <std::string> Encode(std::string s);
  std::vector<int> CreateHistogram(std::string s);

  ~HuffmanTree();
};


#endif  // MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_H_
