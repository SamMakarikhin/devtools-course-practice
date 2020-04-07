// Copyright 2020 Kornev Nikita

#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_

#include <vector>
#include <stack>
#include <string>
using std::vector;
using std::stack;
using std::string;

class converter {
  vector<int> convert_dec_to_smaller(const vector<int>& value, const int& target_system);
  vector<int> convert_smaller_to_dec(const vector<int>& value, const int& this_system);
  void parse(const vector<int>& value, int& res);
  void parse(const int& value, vector<int>& res);
  vector<int> convert(const vector<int>& value, const int& this_system, const int& target_system);

public:
 
  vector<char> convert_dec_to_hex(const int& value);
  int convert_hex_to_dec(const vector<char>& value);
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_