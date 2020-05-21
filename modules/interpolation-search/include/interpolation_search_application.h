// Copyright 2020 Mityagina Daria

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APPLICATION_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APPLICATION_H_

#include <string>
#include <vector>
#include <sstream>
#include "include/interpolation_search.h"

class InterpolationSearchApp {
 public:
    InterpolationSearchApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    int ParseValue(const std::string& data);

    using Arguments = struct {
      std::vector<int> vec;
      int toFind;
    };

    std::stringstream _sstream;
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APPLICATION_H_
