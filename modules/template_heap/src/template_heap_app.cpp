// Copyright 2020 Myshkin Andrey

#include "include/template_heap.h"
#include "include/template_heap_app.h"

#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>


std::string Heap_App::HelpMessage(const char* appname) {
    return std::string("") +
        "      This is an application which allows you \n" +
        "      to sort numbers in reverse order\n" +
        "      Please provide arguments in the following format:\n" +
        "         $" + appname + " value_1 value_2 ... value_n\n" +
        "      You can use any data type for numbers\n";
}

bool Heap_App::ValidateNumderOfArguments(int argc, const char** argv) {
    auto no_argumnets = [&argc] { return argc == 1; };
    auto first_arg_is_help = [&argv] { return std::string(argv[1]) == "help"; };

    if (no_argumnets() || first_arg_is_help()) {
        printf("%s", HelpMessage(argv[0]).c_str());
        return false;
    }

    try {
        for (int i = 1; i < argc; ++i)
            Argc_app.emplace_back(std::stof(argv[i]));
    }
    catch (std::exception&) {
        printf("      Input error\n\n%s", HelpMessage(argv[0]).c_str());
        return false;
    }

    return true;
}

std::string Heap_App::operator()(int argc, const char** argv) {
    if (!ValidateNumderOfArguments(argc, argv))
        return "";

    THeap<float> heap;
    std::ostringstream result;

    for (auto value : heap.HeapSorting(Argc_app))
        result << value << " ";
    result << "\n";

    return result.str();
}
