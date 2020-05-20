// Copyright 2020 Myshkin Andrey

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

#include "include/template_heap_app.h"


int main(int argc, const char** argv) {
    Heap_App App;
    std::string output = App(argc, argv);
    std::cout << output.c_str() << std::endl;
    return 0;
}
