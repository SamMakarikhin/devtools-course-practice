// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include "include/chezar.h"

TEST(Suchkov_Makar_ChezarTest, Can_Create) {
    // Arrange
    // Act
    Chezar estr;
    // Assert
    EXPECT_FALSE(estr.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_With_Arguments_Create) {
    // Arrange
    char a[] = "abc";
    int key = 1488;
    // Act
    Chezar estr1(a, key);
    // Assert
    EXPECT_FALSE(estr1.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_Add_Key_Data) {
    // Arrange
    Chezar estr;
    int key;
    // Act
    key = 9999999;
    // Assert
    EXPECT_TRUE(estr.SetKey(key));
}

TEST(Suchkov_Makar_ChezarTest, Can_Add_Str_Data) {
    // Arrange
    Chezar estr;
    char a[] = "abcd";
    // Act

    // Assert
    EXPECT_TRUE(estr.SetStr(a));
}

TEST(Suchkov_Makar_ChezarTest, Can_Get_Str_Data) {
    // Arrange
    Chezar estr;
    char a[] = "abcd";
    // Act
    estr.SetStr(a);
    // Assert
    EXPECT_TRUE(estr.GetStr());
}

TEST(Suchkov_Makar_ChezarTest, Can_Get_Key_Data) {
    // Arrange
    Chezar estr;
    int key = 1488;
    // Act
    estr.SetKey(key);
    // Assert
    EXPECT_TRUE(estr.GetKey());
}

TEST(Suchkov_Makar_ChezarTest, Can_Encrypt_Data) {
    // Arrange
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr(a, 1488);
    // Act
    estr.Encrypt();
    // Assert
    EXPECT_TRUE(estr.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_Decrypt_Data) {
    // Arrange
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr(a, 1488);
    // Act
    estr.Decrypt();
    // Assert
    EXPECT_FALSE(estr.isEncrypt());
}

TEST(Suchkov_Makar_ChezarTest, Can_Crypt_Correct_Data) {
    // Arrange
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    Chezar estr(a, 3);
    // Act
    estr.Encrypt();
    char z[] = "defghijklmnopqrstuvwxyzabc";
    // Assert
    EXPECT_STRCASEEQ(z, estr.GetStr());
}

TEST(Suchkov_Makar_ChezarTest, Can_Decrypt_Correct_Data) {
    // Arrange
    char a[] = "ghijklmnopqrstuvwxyzabcde";
    Chezar estr(a, 1488);
    // Act
    estr.SetCryptStatus(estr.ENCRYPTED);
    estr.Decrypt();
    char z[] = "abcdefghijklmnopqrstuvwxy";
    // Assert
    EXPECT_STRCASEEQ(z, estr.GetStr());
}
