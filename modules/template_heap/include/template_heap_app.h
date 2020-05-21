// Copyright 2020 Myshkin Andrey

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_
#define MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_

#include <string>
#include <vector>

class Heap_App {
    std::vector<float> Argc_app;

    std::string HelpMessage(const char* appname);
    bool Parsing(int argc, const char** argv);
    bool ValidateNumderOfArguments(int argc, const char** argv);

 public:
    Heap_App() = default;
    Heap_App(const Heap_App&) = default;

    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_APP_H_
