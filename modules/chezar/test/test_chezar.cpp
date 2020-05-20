// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

#include <gtest/gtest.h>

#include <string>

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("fghijklmnopqrstuvwxyzabcde");
    std::string res(Decrypt(a, 5));
    // Act
    EXPECT_EQ("abcdefghijklmnopqrstuvwxyz", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("abcdefghijklmnopqrstuvwxyz");
    std::string res(Encrypt(a, 5));
    // Act
    EXPECT_EQ("fghijklmnopqrstuvwxyzabcde", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("FGHIJKLMNOPQRSTUVWXYZABCDE");
    std::string res(Decrypt(a, 5));
    // Act
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string res(Encrypt(a, 5));
    // Act
    EXPECT_EQ("FGHIJKLMNOPQRSTUVWXYZABCDE", res);
}
