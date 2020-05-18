// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

Chezar::Chezar() {
}

Chezar::Chezar(char *str, int key) {
    this->msg = str;
    this->key = key;
}

Chezar::~Chezar() {
}

bool Chezar::SetKey(int key) {
    this->key = key;
    return true;
}

bool Chezar::SetStr(char* str) {
    this->msg = str;
    return true;
}

char* Chezar::GetStr() {
    return msg;
}

bool Chezar::isEncrypt() {
    return is_e;
}

int Chezar::GetKey() {
    return key;
}

bool Chezar::SetCryptStatus(bool status) {
    is_e = status;
    return true;
}

bool Chezar::Encrypt() {
    if (!is_e) {
        for (unsigned int i = 0; msg[i] != '\0'; ++i) {
            char ch = msg[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + (key % 26);
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
                msg[i] = ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + (key % 26);
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                msg[i] = ch;
            }
        }
    }
    is_e = true;
    return true;
}

bool Chezar::Decrypt() {
    if (is_e) {
        for (unsigned int i = 0; msg[i] != '\0'; ++i) {
            char ch = msg[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - (key % 26);
                if (ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
            msg[i] = ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - (key % 26);
                if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
                }
                msg[i] = ch;
            }
        }
    }
    is_e = false;
    return true;
}
