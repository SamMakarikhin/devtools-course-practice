// Copyright 2020 Andreev Sergey

#include "include/priority_queue.h"
#include "include/priority_queue_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

pq_app::pq_app() : message_("") {}

void pq_app::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a priority queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <key1> <data1> <key2> <data2> "
        + "<key3> <data3> <operation>\n\n" +

        "Where <key> is priority of <data> value, " +
        "and <operation> is one of 'extractMax', 'extractMin'.\n";
}

bool pq_app::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 0);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std:: string operation;
    if (strcmp(arg, "extractMin") == 0) {
        operation = "extractMin";
    }
    else if (strcmp(arg, "extractMax") == 0) {
        operation = "extractMax";
    }
    else {
        throw std::string("Wrong format!");
    }
    return operation;
}

std::string pq_app::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.key1 = parseInt(argv[1]);
        args.data1 = parseInt(argv[2]);
        args.key2 = parseInt(argv[3]);
        args.data2 = parseInt(argv[4]);
        args.key3 = parseInt(argv[5]);
        args.data3 = parseInt(argv[6]);
        args.operation = parseOperation(argv[7]);
    }
    catch (std::string & str) {
        return str;
    }

    priority_queue pq;
    node n1(args.key1, args.data1);
    node n2(args.key2, args.data2);
    node n3(args.key3, args.data3);
    pq.insert(n1);
    pq.insert(n2);
    pq.insert(n3);

    int output = 0;

    std::ostringstream stream;
    if (args.operation == "extractMin") {
        output = *(pq.extract_minimum());
        stream << "Min value = " << output;
    } else  if (args.operation == "extractMax") {
        output = *(pq.extract_maximum());
        stream << "Max value = " << output;
    }

    message_ = stream.str();

    return message_;
}
