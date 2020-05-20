// Copyright 2020 Suchkov Makar

#include <cstring>
#include <gtest/gtest.h>

#include "include/chezar.h"

class ChezarTest : public ::testing::Test {
};

TEST_F(Suchkov_Makar_ChezarTest, Can_Create) {
    // Arrange & Act
    Chezar estr;
    // Assert
    EXPECT_EQ(0, estr.GetKey());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_With_Arguments_Create) {
    // Arrange
    std::string a;
    a = "abcdefghijklmnopqrstuvwxyz";
    int key = 1488;
    // Act
    Chezar estr1(a, key);
    // Assert
    EXPECT_EQ(6, estr.GetKey());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Add_Key_Data) {
    // Arrange
    Chezar estr;
    int key;
    // Act
    key = 9999999;
    estr.SetKey(key)
    // Assert
    EXPECT_EQ(9, estr.GetKey());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Add_Str_Data) {
    // Arrange
    Chezar estr;
    std::string a;
    a = "abcdefghijklmnopqrstuvwxyz";
    estr.SetStr(a)
    // Act & Assert
    EXPECT_STRCASEEQ(a, estr.GetStr());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data) {
    // Arrange
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr(a, 5);
    // Act
    estr.Encrypt();
    std::string z = "fghijklmnopqrstuvwxyzabcde";
    // Assert
    EXPECT_STRCASEEQ(z, estr.GetStr());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Decrypt_Correct_Data) {
    // Arrange
    std::string a = "fghijklmnopqrstuvwxyzabcde";
    Chezar estr(a, 5);
    // Act
    estr.Decrypt();
    std::string z = "abcdefghijklmnopqrstuvwxyz";
    // Assert
    EXPECT_STRCASEEQ(z, estr.GetStr());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data) {
    // Arrange
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr(a, 5);
    // Act
    estr.Encrypt();
    std::string z = "fghijklmnopqrstuvwxyzabcde";
    // Assert
    EXPECT_STRCASEEQ(z, estr.GetStr());
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Decrypt_Correct_Data_Arguments) {
    // Arrange
    std::string a = "fghijklmnopqrstuvwxyzabcde";
    Chezar estr;
    std::string z = "abcdefghijklmnopqrstuvwxyz";
    // Assert & Act
    EXPECT_STRCASEEQ(z, estr.Decrypt(a, 5));
}

TEST_F(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data_Arguments) {
    // Arrange
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr;
    std::string z = "fghijklmnopqrstuvwxyzabcde";
    // Assert & Act
    EXPECT_STRCASEEQ(z, estr.Encrypt(a, 5));
}
