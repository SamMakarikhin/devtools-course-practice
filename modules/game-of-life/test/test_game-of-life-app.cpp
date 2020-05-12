// Copyright 2020 Kriukov Dmitry

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/game-of-life-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class GameOfLifeAppTest : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
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
  GameOfLifeApp app_;
  string output_;
};

TEST_F(GameOfLifeAppTest, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a game of life application\\..*");
}

TEST_F(GameOfLifeAppTest, Invalid_Arguments_Test) {
  vector<string> args = {"a", "b", "c"};

  Act(args);

  Assert("Invalid grid size!");
}

TEST_F(GameOfLifeAppTest, Size_Not_Entered_Test) {
  vector<string> args = { "1" };

  Act(args);

  Assert("Enter width and hight");
}

TEST_F(GameOfLifeAppTest, Too_Few_Arguments_Test) {
  vector<string> args = { "2", "2", "." };

  Act(args);

  Assert("ERROR: You need to fill in the grid completely");
}

TEST_F(GameOfLifeAppTest, Wrong_Grid_Format_Test) {
  vector<string> args = { "2", "2", "r", "e", "a", "d", "4" };

  Act(args);

  Assert("Wrong grid elements format*");
}

TEST_F(GameOfLifeAppTest, Invalid_Steps_count) {
  vector<string> args = { "2", "2", "*", ".", "*", ".", "a" };

  Act(args);

  Assert("Invalid steps count!*");
}

TEST_F(GameOfLifeAppTest, Can_Calculate_Next_Grid) {
  vector<string> args = { "3", "3",  ".", "*", ".",
    ".", "*", ".", ".", "*", ".", "1" };

  Act(args);

  Assert("...\n\\*\\*\\*\n...\n");
}
