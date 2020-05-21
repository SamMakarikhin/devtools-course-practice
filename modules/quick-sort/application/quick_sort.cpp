// Copyright 2020 Poletueva Anastasia

#include <iostream>
#include <string>

#include "include/quick_sort_app.h"

int main(int argc, const char** argv) {
    QuickSortApp app;
    std::string output = app(argc, argv);
    std::cout << "%s"<< std::endl << output.c_str() << std::endl;
    return 0;
}
