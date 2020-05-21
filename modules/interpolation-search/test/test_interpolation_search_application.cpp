// Copyright 2020 Mityagina Daria

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/interpolation_search_application.h"

using ::testing::internal::RE;

class InterpolationSearchAppTest : public ::testing::Test {
 protected:
     void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;
         options.push_back("InterpolationSearchAppTest");

         for (size_t i = 0; i < args_.size(); ++i) {
              options.push_back(args_[i].c_str());
         }
         const char** argv = &options.front();
         int argc = static_cast<int>(args_.size()) + 1;

         output_ = app_(argc, argv);
     }

     void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }
 private:
     std::string output_;
	 InterpolationSearchApp app_;
};

TEST_F(InterpolationSearchAppTest, Print_Help_Without_Args) {
	// Arrange
    std::vector<std::string> args = {};

	// Act
    Act(args);

	// Assert
    Assert("This is a Interpolation Search application\\..*");
}

TEST_F(InterpolationSearchAppTest, Detects_Wrong_Args) {
	// Arrange
    std::vector<std::string> args = {"1"};

	// Act
    Act(args);

	// Assert
    Assert("Wrong arguments");
}

TEST_F(InterpolationSearchAppTest, Add_Wrong_Elem) {
	// Arrange
    std::vector<std::string> args = {"2", "l", "2"};

	// Act
    Act(args);

	// Assert
    Assert("Wrong arguments");
}

TEST_F(InterpolationSearchAppTest, Get_Result) {
	// Arrange
    std::vector<std::string> args = { "2", "9", "12", "12" };

	// Act
    Act(args);

	// Assert
    Assert("");
}
