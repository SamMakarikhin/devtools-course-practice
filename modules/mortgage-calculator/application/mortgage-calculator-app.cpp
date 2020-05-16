// Copyright 2020 Savin Dmitry

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/mortgage-calculator.h"

int main(int argc, const char** argv) {
    MortgageCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
