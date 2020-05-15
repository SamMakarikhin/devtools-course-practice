// Copyright 2020 Myshkin Andrey

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/template_heap_app.h"


int main(int argc, const char** argv) {
    Heap_App App;
    std::string output = App(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
