// Copyright 2020 Suchkov Makar

#ifndef MODULES_CHEZAR_INCLUDE_CHEZAR_H_
#define MODULES_CHEZAR_INCLUDE_CHEZAR_H_

#include <iostream>

class Chezar {
 public:
    Chezar();
    Chezar(char *str, int key);
    ~Chezar();
    char* GetStr();
    bool SetStr(char* str);
    bool SetKey(int key);
    int GetKey();
    bool isEncrypt();
    bool SetCryptStatus(bool status);
    bool Decrypt();
    bool Encrypt();
    enum Cryptstatus {
       DECRYPTED = false,
       ENCRYPTED = true
    };
 private:
    char* msg = nullptr;
    int key = 0;
    bool is_e = false;
};

#endif  // MODULES_CHEZAR_INCLUDE_CHEZAR_H_
