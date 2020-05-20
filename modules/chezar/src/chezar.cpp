// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

Chezar::Chezar() {
    key = 0;
}

Chezar::Chezar(std::string str, unsigned int key) {
    this->msg = str;
    if (key >= 26) {
        this->key = key;
    }
    else {
        this->key = key % 26;
    }
}

Chezar::~Chezar() {
}

void Chezar::SetKey(unsigned int key) {
    if (key >= 26) {
        this->key = key;
    }
    else {
        this->key = key % 26;
    }
}

void Chezar::SetStr(std::string str) {
    this->msg = str;
    
}

std::string Chezar::GetStr() const {
    return msg;
}

unsigned int Chezar::GetKey() const {
    return key;
}

void Chezar::Encrypt() {
    for (unsigned int i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] += key;
            if (msg[i] > 'z') {
                 msg[i] = msg[i] - 'z' + 'a' - 1;
                }
            } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] += key;
            if (msg[i] > 'Z') {
                msg[i] = msg[i] - 'Z' + 'A' - 1;
            }
        }
    }
}

void Chezar::Decrypt() {
    for (unsigned int i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] -= key;
            if (msg[i] < 'a') {
                msg[i] = msg[i] + 'z' - 'a' + 1;
            }
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] -= key;
            if (msg[i] < 'A') {
                msg[i] = msg[i] + 'Z' - 'A' + 1;
            }
        }
    }
}

std::string Chezar::Encrypt(std::string str, unsigned int key) {
    this->msg = str;
    if (key >= 26) {
        this->key = key;
    }
    else {
        this->key = key % 26;
    }
    for (unsigned int i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] += key;
            if (msg[i] > 'z') {
                msg[i] = msg[i] - 'z' + 'a' - 1;
            }
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] += key;
            if (msg[i] > 'Z') {
                msg[i] = msg[i] - 'Z' + 'A' - 1;
            }
        }
    }
    return msg;
}

std::string Chezar::Decrypt(std::string str, unsigned int key) {
    this->msg = str;
    if (key >= 26) {
        this->key = key;
    }
    else {
        this->key = key % 26;
    }
    for (unsigned int i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] -= key;
            if (msg[i] < 'a') {
                msg[i] = msg[i] + 'z' - 'a' + 1;
            }
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] -= key;
            if (msg[i] < 'A') {
                msg[i] = msg[i] + 'Z' - 'A' + 1;
            }
        }
    }
    return msg;
}
