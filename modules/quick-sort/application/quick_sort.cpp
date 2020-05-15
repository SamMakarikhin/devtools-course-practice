// Copyright 2020 Poletueva Anastasia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/quick_sort_app.h"

int main(int argc, const char** argv) {
    QuickSortApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
