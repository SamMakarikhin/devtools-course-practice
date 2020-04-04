// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Complex) {
  // Arrange
  double re = 3.4;
  double im = 9.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Addition) {
  // Arrange
  ComplexNumber z1(1.5, 6.4);
  ComplexNumber z2(3.0, 2.1);

  // Act
  ComplexNumber z3=z1+z2;

  // Assert
  EXPECT_EQ(4.5, z3.getRe());
  EXPECT_EQ(8.5, z3.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Subtraction) {
  // Arrange
  ComplexNumber z1(5.0, 4.0);
  ComplexNumber z2(2.0, 1.0);

  // Act
  ComplexNumber z3 = z1 - z2;

  // Assert
  EXPECT_EQ(3.0, z3.getRe());
  EXPECT_EQ(3.0, z3.getIm());
}
