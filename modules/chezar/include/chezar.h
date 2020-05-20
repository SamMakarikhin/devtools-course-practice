// Copyright 2020 Suchkov Makar

#ifndef MODULES_CHEZAR_INCLUDE_CHEZAR_H_
#define MODULES_CHEZAR_INCLUDE_CHEZAR_H_

#include <string>

#define MAXKEYVALUE 5

std::string Decrypt(std::string str, unsigned int key);
std::string Encrypt(std::string str, unsigned int key);

#endif  // MODULES_CHEZAR_INCLUDE_CHEZAR_H_
