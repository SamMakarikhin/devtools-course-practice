// Copyright 2020 Andreev Sergey

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_

#include <string>

class pq_app {
 public:
    pq_app();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int key1;
        int data1;
        int key2;
        int data2;
        int key3;
        int data3;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
