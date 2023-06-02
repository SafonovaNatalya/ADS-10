// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
  private:
  struct node {
    std::vector<node*> vec;
    char value;
  }
  node* root;
  std::vector<std::vector<char>> helper;
  node* Create(node* root, std::vector<char> helper) {
    if (!root) root = new node;
    if (helper.empty()) return root;
    for (int i = 0; i < helper.size(); i++) {
      std::vector<char> vect = helper;
      node* val = new node;
      val->value = helper[i];
      root->vec.push_back(a);
      vect.erase(vect.begin() + i);
      create(root->vec[i], vect);
    }
    return root;
  }
  std::vector<char> Perm(node* root, std::vector<char>* ch) {
    for (int i = 0; i<root->vec.size(); i++) {
      ch->push_back(root->vec[i]->value);
      if (root->vec[i]->vec.empty()) return *ch;
      Perm(root->vec[i], ch);
      if (ch->size() != 1) helper.push_back(*ch);
      for (int j = 0; j< ch->size(); j++) {
        ch->pop_back();
      }
    }
    return *a;
  }
  public:
  explicit Tree(std::vector<char> vec): root(nullptr) {
    root = create(root, vec);
    std::vector<char> ch;
    Perm(root, &ch);
  }
  std::vector<char> PermH(int i) const {
    if (helper.size() < i) return std::vector<char>();
    return helper[i];
  }
}
#endif  // INCLUDE_TREE_H_
