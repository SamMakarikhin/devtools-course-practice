// Copyright 2020 Savin Dmitry

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/MortgageCalc.h"
#include "include/mortgage-calculator.h"

MortgageCalculator::MortgageCalculator() : message_("") {}

void MortgageCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a mortgage calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <c_cost> <d_downPayment> " +
          "<c_creditTerm> <i_interestRate> \n\n" +

          "Where all arguments are integer numbers, " +
          "and <i_interestRate> is double-precision number.\n";
}

bool MortgageCalculator::validateNumberOfArguments(int argc,
const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 0);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string MortgageCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.c_cost      = parseInt(argv[1]);
        args.d_downPayment = parseInt(argv[2]);
        args.c_creditTerm      = parseInt(argv[3]);
        args.i_interestRate = parseDouble(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    MortgageCalc calculator(args.c_cost, args.d_downPayment,
    args.c_creditTerm, args.i_interestRate);
    calculator.calc();
    std::ostringstream stream;
    stream << "c_cost = " << calculator.getCost() << " "
           << "d_downPayment = " << calculator.getDownPayment() << " "
           << "c_creditTerm = " << calculator.getCreditTerm() << " "
           << "i_interestRate = " << calculator.getInterestRate() << " "
           << "payment = " << calculator.getMonthlyPayment();


    message_ = stream.str();
    return message_;
}
