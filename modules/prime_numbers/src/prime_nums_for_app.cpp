// Copyright 2020 Dobrohotov Vitaly

#include <sstream>
#include <string>
#include<vector>

#include "include/prime_nums_for_app.h"
#include "include/TPrime_Nums.h"

PrimeNums::PrimeNums() : message_("") {}

void PrimeNums::help(const char* appname, const char* error_message) {
    message_ += std::string(error_message);
    message_ += "This is a primary numbers application.\n";
    message_ += "Please provide arguments in the following format:\n";
    message_ += "<left border> <right border>\n";
    message_ += "Where all arguments are int numbers,\n";
    message_ += "left border less than right border,\n";
    message_ += "and both of border not equal null";
}

bool PrimeNums::checkArgs(int argc, const char** argv) {
    int a, b;
    if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments\n");
        return false;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a < 0) {
        help(argv[0], "ERROR: Left border can't be less than zero\n");
        return false;
    }
    if (a > b) {
        help(argv[0], "ERROR: Left border must be less than right\n");
        return false;
    } else if (a == 0 || b == 0) {
        help(argv[0], "ERROR: incorrect input data\n");
        return false;
    }
    return true;
}

std::string PrimeNums::operator()(int argc, const char** argv) {
    int a;
    int b;
    if (!checkArgs(argc, argv)) {
        return message_;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    TPrime_Nums pn(a, b);
    std::vector <unsigned int> v = pn.Get_Prime_Nums();
    message_ = "Interval: " + std::to_string(pn.GetInterval().first) +"-" +
        std::to_string(pn.GetInterval().second) + "\nPrimary numbers: ";
    for (auto i : v) {
       message_ += std::to_string(i) + " ";
    }
    return message_;
}
