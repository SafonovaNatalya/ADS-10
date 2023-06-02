// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    struct Node {
        char c;
        std::vector<Node*> ptr;
    };
    std::vector<std::vector<char>> vec;
    Node* root;
    Node* create(Node* root, std::vector<char> vec) {
        if (!root)
            root = new Node;
        for (int i = 0; i < vec.size(); ++i) {
            std::vector<char> b = vec;
            Node* a = new Node;
            a->c = vec[i];
            root->ptr.push_back(a);
            b.erase(b.begin() + i);
            create(root->ptr[i], b);
        }
        if (vec.empty())
            return root;
        return root;
    }
    std::vector<char> Perm(Node* root, std::vector<char>* a) {
        for (int i = 0; i < root->ptr.size(); ++i) {
            a->push_back(root->ptr[i]->c);
            if (root->ptr[i]->ptr.empty())
                return *a;
            Perm(root->ptr[i], a);
            if (a->size() != 1)
                vec.push_back(*a);
            for (int g = 0; g < a->size(); ++g)
                a->pop_back();
        }
        return *a;
    }

 public:
        explicit Tree(std::vector<char> vec): root(nullptr) {
        root = create(root, vec);
        std::vector<char> b;
        Perm(root, &b);
    }
    std::vector<char> perm(int n) const {
        if (vec.size() < n)
            return std::vector<char>();
        return vec[n];
    }
};
#endif  // INCLUDE_TREE_H_
