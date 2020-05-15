// Copyright 2020 Poletueva Anastasia

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APP_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APP_H_

#include <string>
#include <vector>

class QuickSortApp {
 public:
    QuickSortApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
    std::vector<int> vec;
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APP_H_
