// Copyright 2020 Pauzin Leonid

//#ifndef MODULES_AVL_TREE
//#define MODULES_AVL_TREE

#include "include/AVL_Tree.h"

#include <string>
#include <sstream>
#include <vector>
#include <map>




class AvlApp {
 public:
    AvlApp() = default;
    std::string operator()(int argc, const char** argv);

 private:
   std::string help(const char* appname, const char* message = "");
   bool validateNumberOfArguments(int argc, const char** argv);
   int parseToValue(std::string strval);
   AVL_Tree tree;	
   std::stringstream _sstream;
   //std::string message_;
};



//#endif  // MODULES_AVL_TREE
