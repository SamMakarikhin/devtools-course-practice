// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include "include/chezar.h"

#include <string>

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("fghijklmnopqrstuvwxyzabcde");
    std::string z("abcdefghijklmnopqrstuvwxyz");
    std::string res(Decrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ("abcdefghijklmnopqrstuvwxyz", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("abcdefghijklmnopqrstuvwxyz");
    std::string z("fghijklmnopqrstuvwxyzabcde");
    std::string res(Encrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ("fghijklmnopqrstuvwxyzabcde", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("FGHIJKLMNOPQRSTUVWXYZABCDE");
    std::string z("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string res(Decrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ(z, res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string z("FGHIJKLMNOPQRSTUVWXYZABCDE");
    std::string res(Encrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ(z, res);
}