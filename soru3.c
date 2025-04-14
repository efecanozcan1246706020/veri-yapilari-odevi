#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* getNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* p = root;
    while (*key) {
        int index = *key - 'a';
        if (!p->children[index])
            p->children[index] = getNode();
        p = p->children[index];
        key++;
    }
    p->isEndOfWord = 1;
}

int search(TrieNode* root, const char* key) {
    TrieNode* p = root;
    while (*key) {
        int index = *key - 'a';
        if (!p->children[index])
            return 0;
        p = p->children[index];
        key++;
    }
    return p->isEndOfWord;
}

int main() {
    TrieNode* root = getNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "can");

    printf("cat: %d\n", search(root, "cat")); // 1
    printf("cap: %d\n", search(root, "cap")); // 0

    return 0;
}
