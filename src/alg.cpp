// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <vector>
#include  "tree.h"
std::vector<char> getPermq(const Tree& tree, int n) {
  return tree.PermH(n - 1);
}
