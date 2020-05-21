// Copyright 2020 Mityagina Daria

#include <iostream>
#include <string>
#include "include/interpolation_search_application.h"

int main(int argc, const char** argv) {
  InterpolationSearchApp app;
  std::cout << app(argc, argv) << std::endl;

  return 0;
}
