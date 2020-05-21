// Copyright 2020 Mityagina Daria

#include "include/interpolation_search_application.h"
#include <vector>
#include <string>
#include <sstream>
#include "include/interpolation_search.h"

int InterpolationSearchApp::ParseValue(const std::string& data) {
	int number = 0;
	try {
		number = std::stoi(data);
	}
	catch (const std::exception& e) {
		throw std::string("Invalid value: " + std::string(data));
	}
	return number;
}

InterpolationSearchApp::InterpolationSearchApp() : InterpolationSearchApp(1, 1, 1) {}

std::string InterpolationSearchApp::operator()(int argc, const char** argv) {
	Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return _sstream.str();
    }
	try {
		int n = ParseValue(argv[1]);
		args.vec = std::vector<int>(n);
		for (int i = 0; i < n; i++) {
			args.vec[i] = ParseValue(argv[i+1]);
		}
		args.toFind = ParseValue(argv[n + 2]);
	}
	catch (std::string& str) {
		return str;
	}

	std::ostringstream stream;

	stream << "Value found at: " <<
		interpolationSearch(&args.vec, args.toFind);

	_sstream.str() = stream.str();

	return _sstream.str();
}

std::string InterpolationSearchApp::help(const char* appname, const char* message) {
    std::cout << message << std::endl;
    return std::string(message) + "This is a Interpolation Search application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + " <size> " + "<el_1>" + "<el_2>" + "..." + "<el_n>" + "<el_to_find>" + "\n\n" +
        "Where <size> is number of elements in vector\n" +
		"<el_1>, <el_2> and so on are vector's elements\n" + 
		"<el_to_find> is the value you are looking for \n\n";
}

bool InterpolationSearchApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        _sstream << help(argv[0]);
        return false;
    } else if (argc != ParseValue(argv[1]) + 2) {
		help(appName, "Wrong number of arguments \n\n");
		return false;
	}
	return true;
}
