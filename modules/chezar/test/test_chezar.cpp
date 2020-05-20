// Copyright 2020 Suchkov Makar

#include <string>
#include <gtest/gtest.h>

#include "include/chezar.h"

using std::string;

class ChezarTest : public ::testing::Test {
};

TEST(Suchkov_Makar_ChezarTest, Can_Create) {
    // Arrange & Act
    Chezar estr;
    int z = estr.GetKey();
    // Assert
    EXPECT_EQ(0, z);
}

TEST(Suchkov_Makar_ChezarTest, Can_With_Arguments_Create) {
    // Arrange
    std::string a("abcdefghijklmnopqrstuvwxyz");
    int key = 1488;
    // Act
    Chezar estr(a, key);
    int res = estr.GetKey();
    // Assert
    EXPECT_EQ(6, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Add_Key_Data) {
    // Arrange
    Chezar estr;
    int key;
    // Act
    key = 9999999;
    estr.SetKey(key);
    int res = estr.GetKey();
    // Assert
    EXPECT_EQ(9, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Add_Str_Data) {
    // Arrange
    Chezar estr;
    std::string a("abcdefghijklmnopqrstuvwxyz");
    estr.SetStr(a);
    std::string res(estr.GetStr());
    // Act & Assert
    EXPECT_STRCASEEQ(a, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data) {
    // Arrange
    std::string a("abcdefghijklmnopqrstuvwxyz");
    Chezar estr(a, 5);
    // Act
    estr.Encrypt();
    std::string z("fghijklmnopqrstuvwxyzabcde");
    std::string res(estr.GetStr());
    // Assert
    EXPECT_STRCASEEQ(z, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Decrypt_Correct_Data) {
    // Arrange
    std::string a("fghijklmnopqrstuvwxyzabcde");
    Chezar estr(a, 5);
    // Act
    estr.Decrypt();
    std::string z("abcdefghijklmnopqrstuvwxyz");
    std::string res(estr.GetStr());
    // Assert
    EXPECT_STRCASEEQ(z, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data) {
    // Arrange
    std::string a("abcdefghijklmnopqrstuvwxyz");
    Chezar estr(a, 5);
    // Act
    estr.Encrypt();
    std::string z("fghijklmnopqrstuvwxyzabcde");
    std::string res(estr.GetStr());
    // Assert
    EXPECT_STRCASEEQ(z, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Decrypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("fghijklmnopqrstuvwxyzabcde");
    Chezar estr;
    std::string z("abcdefghijklmnopqrstuvwxyz");
    std::string res(estr.Decrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ(z, res);
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("abcdefghijklmnopqrstuvwxyz");
    Chezar estr;
    std::string z("fghijklmnopqrstuvwxyzabcde");
    std::string res(estr.Encrypt(a, 5));
    // Act
    EXPECT_STRCASEEQ(z, res);
}
