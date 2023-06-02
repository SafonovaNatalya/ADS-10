// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector getPerm(const Tree& tree, int n) {
  std::vector<std::vector<char>> ch = tree.getPermutations();
    if (ch.size() >= n) {
        return ch[n];
    } else {
        return {};
    }
}
