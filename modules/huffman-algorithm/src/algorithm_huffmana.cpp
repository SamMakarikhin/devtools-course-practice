// Copyright 2020 Poletueva Anastasia

#include "include/algorithm_huffmana.h"
#include <string>
#include <vector>
#include <stack>

HuffmanTree::HuffmanTree(std::string s) {
  std::vector<int> hist = CreateHistogram(s);
  std::vector<HuffmanNode*> queue(256);
  for (int i = 0; i < 256; i++) {
    queue[i] = new HuffmanNode();
    queue[i]->val = i;
    queue[i]->freq = hist[i];
  }
  SortQueue(&queue, hist);
  while (queue.size() > 2) {
    HuffmanNode* node = new HuffmanNode();
    node->val = -1;
    node->right = queue.back();
    queue.pop_back();
    node->left = queue.back();
    queue.pop_back();
    node->freq = node->left->freq + node->right->freq;
    auto i = queue.begin();
    while (((*i)->freq > node->freq) && (i != queue.end() - 1))
      i++;
    queue.insert(i, node);
  }
    root = new HuffmanNode();
    root->val = -1;
    root->right = queue.back();
    queue.pop_back();
    root->left = queue.back();
    queue.pop_back();
    root->freq = root->left->freq + root->right->freq;
}

void HuffmanTree::SortQueue(std::vector<HuffmanNode*>* queue,
  const std::vector<int> & hist) {
for (int j = 0; j < 255; j++) {
  int f = 0;
  for (int i = 0; i < 255 - j; i++) {
    if (hist[(*queue)[i]->val] < hist[(*queue)[i + 1]->val]) {
      HuffmanNode* buff = (*queue)[i];
      (*queue)[i] = (*queue)[i + 1];
      (*queue)[i + 1] = buff;
      f = 1;
    }
  }
  if (f == 0)
    break;
}
}

std::vector <std::string> HuffmanTree::Encode(std::string s) {
  std::vector <std::string> str;
  for (unsigned int i = 0; i < s.size(); i++) {
    str.push_back(encodingTable[s[i]]);
  }
  return str;
}

std::vector<int> HuffmanTree::CreateHistogram(std::string s) {
  std::vector<int> hisogram(256);

  for (std::string::iterator it = s.begin();
    it != s.end(); ++it) {
    hisogram[*it]++;
  }
  return hisogram;
}

std::string HuffmanTree::getSimbolCode(char val) {
  return encodingTable[val];
}

void HuffmanTree::CreateEncodingTable() {
  for (int i = 0; i < 256; i++) encodingTable.push_back("");
  CreateEncodingTable(root->left, "", "0");
  CreateEncodingTable(root->right, "", "1");
}

void HuffmanTree::CreateEncodingTable(HuffmanNode* node,
  std::string code, std::string direct) {
  if ((node->left) || (node->right)) {
    CreateEncodingTable(node->left, code + direct, std::string("0"));
    CreateEncodingTable(node->right, code + direct, std::string("1"));
  } else {
    encodingTable[node->val] = code + direct;
  }
}

HuffmanTree::~HuffmanTree() {
  std::stack<HuffmanNode*> st;
  st.push(root);
  while (!st.empty()) {
    HuffmanNode* curr = st.top();
    st.pop();
    if (curr) {
      if (curr->left)
        st.push(curr->left);
      if (curr->right)
        st.push(curr->right);
    }
    delete curr;
  }
}
