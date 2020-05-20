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
    bool numbersofarguments(int argc, const char** argv);
    std::vector<int> parsevector(int argc, const char** argv);
    std::vector<int> sorting(const std::vector<int>& vec);
    std::string createmessage(const std::vector<int>& vec);
    std::string message_;
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APP_H_
