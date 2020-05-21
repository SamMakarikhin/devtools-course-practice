// Copyright 2020 Mityagina Daria

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "include/interpolation_search_application.h"

int InterpolationSearchApp::ParseValue(const std::string& data) {
  int number = 0;
  for (auto& s : data) {
    if ((!isdigit(s) || s == ',' || s == '.' || s == ' ' || s == '-')) {
      _sstream << help("Wrong arguments \n\n");
      return -2;
    }
  }
  number = std::stoi(data);
	
  return number;
}

std::string InterpolationSearchApp::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return _sstream.str();
  }
  try 
  {
    int n = ParseValue(argv[1]);
    args.vec = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
      args.vec[i] = ParseValue(argv[i+2]);
    }
    args.toFind = ParseValue(argv[n + 2]);

    _sstream << interpolationSearch(&args.vec, args.toFind);

    return _sstream.str();
  }
  catch (std::exception& exc) {
    return exc.what();
  }
}

std::string InterpolationSearchApp::help(const char* appname, const char* message) {
  std::cout << message << std::endl;
  return std::string(message) + "This is a Interpolation Search application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + " <size> " + "<el_1>" + "<el_2>" + "..." + "<el_n>" + "<el_to_find>" + "\n\n" +
        "Where <size> is number of elements in vector\n" +
		"<el_1>, <el_2> and so on are vector's elements (int)\n" + 
		"<el_to_find> is the value you are looking for \n\n";
}

bool InterpolationSearchApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    _sstream << help(argv[0]);
    return false;
  } else if (argc != ParseValue(argv[1]) + 3 || ParseValue(argv[1]) <= 0) {
    _sstream << help("Wrong arguments \n\n");
    return false;
  }

  return true;
}
