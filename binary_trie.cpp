#include "template.h"


// >---------------- Binary-Trie [Begin] ---------------->

// URL : https://ei1333.github.io/library/structure/trie/binary-trie.hpp.html

template <typename T, int MAX_LOG, typename D = int>
struct BinaryTrie {
public:
    struct Node {
        Node* nxt[2];
        D exist;
        vector<int> accept;

        Node() : nxt{nullptr, nullptr}, exist(0) {}
    };

    Node* root;

    BinaryTrie() : root(new Node()) {}
    BinaryTrie(Node* root) : root(root) {}

    void add(const T& bit, int idx = -1, D delta = 1, T xor_val = 0) {
        root = add(root, bit, idx, MAX_LOG, delta, xor_val);
    }

    void erase(const T& bit, T xor_val = 0) {
        add(bit, -1, -1, xor_val);
    }

    Node* find(const T& bit, T xor_val = 0) {
        return find(root, bit, MAX_LOG, xor_val);
    }

    D count(const T& bit, T xor_val = 0) {
        Node* t = find(bit, xor_val);
        return t ? t->exist : 0;
    }

    pair<T, Node*> min_element(T xor_val = 0) {
        assert(root->exist > 0);
        return kth_element(0, xor_val);
    }

    pair<T, Node*> max_element(T xor_val = 0) {
        assert(root->exist > 0);
        return kth_element(root->exist - 1, xor_val);
    }

    pair<T, Node*> kth_element(D k, T xor_val = 0) {
        assert(0 <= k && k < root->exist);
        return kth_element(root, k, MAX_LOG, xor_val);
    }

    D count_less(const T& bit, T xor_val = 0) {
        return count_less(root, bit, MAX_LOG, xor_val);
    }

private:
    virtual Node* clone(Node* t) { return t; }

    Node* add(Node* t, T bit, int idx, int depth, D delta, T xor_val,
            bool need = true) {
        if (need) t = clone(t);

        if (depth == -1) {
            t->exist += delta;
            if (idx >= 0) t->accept.emplace_back(idx);
            return t;
        }

        bool f = (xor_val >> depth) & 1;
        int b = (bit >> depth) & 1;

        Node*& to = t->nxt[f ^ b];
        if (!to) {
            to = new Node();
            need = false;
        }

        to = add(to, bit, idx, depth - 1, delta, xor_val, need);
        t->exist += delta;

        return t;
    }

    Node* find(Node* t, T bit, int depth, T xor_val) {
        if (depth == -1) return t;

        bool f = (xor_val >> depth) & 1;
        int b = (bit >> depth) & 1;

        Node* to = t->nxt[f ^ b];
        return to ? find(to, bit, depth - 1, xor_val) : nullptr;
    }

    pair<T, Node*> kth_element(Node* t, D k, int bit_index, T xor_val) {
        if (bit_index == -1) return {0, t};

        bool f = (xor_val >> bit_index) & 1;

        D left = (t->nxt[f] ? t->nxt[f]->exist : 0);

        if (left <= k) {
            auto ret = kth_element(t->nxt[f ^ 1], k - left, bit_index - 1, xor_val);
            ret.first |= (T(1) << bit_index);
            return ret;
        } else {
            return kth_element(t->nxt[f], k, bit_index - 1, xor_val);
        }
    }

    D count_less(Node* t, const T& bit, int bit_index, T xor_val) {
        if (bit_index == -1) return 0;

        bool f = (xor_val >> bit_index) & 1;
        int b = (bit >> bit_index) & 1;

        D ret = 0;

        if (b && t->nxt[f]) ret += t->nxt[f]->exist;

        Node* to = t->nxt[f ^ b];
        if (to) {
            ret += count_less(to, bit, bit_index - 1, xor_val);
        }

        return ret;
    }
};
// <---------------- Binary-Trie [ End ] ----------------<
