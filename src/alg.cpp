// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  if (n > 0) {
    std::vector<char> temp = tree.PermH(n-1);
    return temp;
  } else
    return {};
}
