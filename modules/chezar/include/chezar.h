// Copyright 2020 Suchkov Makar

#ifndef MODULES_CHEZAR_INCLUDE_CHEZAR_H_
#define MODULES_CHEZAR_INCLUDE_CHEZAR_H_

#include <string>

using std::string;

class Chezar {
 public:
  Chezar();
  Chezar(std::string str, unsigned int key);
  ~Chezar();
  std::string GetStr() const;
  void SetStr(std::string str);
  void SetKey(unsigned int key);
  unsigned int GetKey() const;
  void Decrypt();
  void Encrypt();
  std::string Decrypt(std::string str, unsigned int key);
  std::string Encrypt(std::string str, unsigned int key);
 private:
  std::string msg;
  unsigned int key;
};

#endif  // MODULES_CHEZAR_INCLUDE_CHEZAR_H_
