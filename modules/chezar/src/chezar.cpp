// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

Chezar::Chezar() {
}

Chezar::Chezar(char *str, int key) {
    try {
        if (str == nullptr)
            throw;
        this->msg = str;
        this->key = key;
    } catch (...) {
        std::cerr << "Error constructor" << std::endl;
    }
}

Chezar::~Chezar() {
}

bool Chezar::SetKey(int key) {
    try {
        this->key = key;
        return true;
    } catch (...) {
        return false;
    }
}

bool Chezar::SetStr(char* str) {
    try {
        if (str == nullptr)
            throw;
        this->msg = str;
    } catch (...) {
        return false;
    }
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
    if (status == true || status == false) {
        is_e = status;
        return true;
    } else {
        return false;
    }
}

bool Chezar::Encrypt() {
    if (!is_e) {
        try {
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
            is_e = true;
            return true;
        } catch (...) {
            return false;
        }
    } else {
        return false;
    }
}

bool Chezar::Decrypt() {
    if (is_e) {
        try {
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
            is_e = false;
            return true;
        } catch (...) {
            return false;
        }
    } else {
        return false;
    }
}
