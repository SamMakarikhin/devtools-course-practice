// Copyright 2020 Poletueva Anastasia

#include "include/quick_sort.h"
#include "../include/quick_sort_app.h"
#include <string>
#include <sstream>
#include <vector>

QuickSortApp::QuickSortApp() : message_(""), vec() {}

std::string  QuickSortApp::operator()(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return message_;
  }
  try {
    for (int i = 1; i < argc; i++) {
      vec.push_back(std::stoi(argv[i]));
    }
  }
  catch (std::exception) {
    return std::string("Wrong number format!");
  }

  std::ostringstream stream;
  QuickSort qsort(vec);

  qsort.QSort(0, (vec.size()-1));

  std::vector<int> res = qsort.GetVector();

  int sz = res.size();
  for (int i = 0; i < sz -1; ++i) stream << res[i] << " ";
  stream << res[sz-1];

  message_ = stream.str();

  return message_;
}

void QuickSortApp::help(const char * appname, const char * message) {
  message_ =
    std::string(message) +
    "This is a quick sort application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <integer numbers>"  +
    "Where  <integer numbers> is a set of some integer numbers\n";
}
