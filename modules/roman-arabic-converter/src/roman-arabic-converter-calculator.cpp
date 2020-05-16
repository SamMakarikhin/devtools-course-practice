// Copyright 2020 Arisova Anastasiia

#include "include/roman-arabic-converter.h"
#include "include/roman-arabic-converter-calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

RomanArabicConvertCalculator::
    RomanArabicConvertCalculator() : message_("") {}

void RomanArabicConvertCalculator::
    help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a  Roman-Arabic Convert calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          appname + " <count of elements>" +
          "<mode for first element> <first element>" +
          "<mode for second element> <second element> " +
          "... <mode for last element> <last element>\n\n" +

          "Where count of elements is a natural numbers, " +
          "mode is one of 'roman to arabic', 'arabic to roman'.\n" + 
          "Please, input correct value of number for right work of converter!";
}

int parseInt(const char* arg) {
    int value;
    try {
        value = std::stoi(arg);
    }
    catch(...) {
        throw std::string("Wrong number format!");
    }

    return value;
}

bool RomanArabicConvertCalculator::
    validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } 
    int count_of_elements = parseInt(argv[1]);
    if (argc == 2 * count_of_elements + 2) {
        return true;
    }
    help(argv[0],
        "ERROR: incorrect number of parameters. Please try again.\n\n");
    return false;
}

std::string parseMode(const char* arg) {
    std::string op(arg);
    if (op == "roman to arabic") {
        op = "roman to arabic";
    } else if (op == "arabic to roman") {
        op = "arabic to roman";
    } else {
        throw std::string("Wrong mode format!");
    }
    return op;
}

std::string RomanArabicConvertCalculator::
    operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.count_of_elements = parseInt(argv[1]);
        for (int i = 0, j = 2; i < args.count_of_elements * 2; i++, j += 2) {
            std::pair <std::string, std::string> temp(parseMode(argv[j]), std::string(argv[j + 1]));
            args.elements[i] = temp;
        }
    }
    catch(std::string& str) {
        return str;
    }
    RomanArabicConverter converter;

    std::ostringstream stream;

    try {
        stream << "Results of the conversion: "<< std::endl;
        for (int i = 0; i < args.count_of_elements; i++) {
            int res_arabic;
            std::string res_roman;
            if(args.elements[i].first == "arabic to poman") {
                res_roman = converter.arabicToRoman(std::stoi(args.elements[i].second));
                stream << args.elements[i].second << " -> " << res_roman << std::endl;
            } else {
                res_arabic = converter.romanToArabic(args.elements[i].second);
                stream << args.elements[i].second << " -> " << res_arabic << std::endl;
            }
        }
    }
    catch(std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
