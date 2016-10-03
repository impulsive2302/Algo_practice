#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ALPHABET_SIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
struct trie_node
{
    struct trie_node* children[ALPHABET_SIZE];
    bool is_leaf;
};
struct trie_node* get_trie_node()
{
    struct trie_node* node  = (struct trie_node*)malloc(sizeof(struct trie_node));
    if(node)
    {
        node->is_leaf = false;
        for(int i = 0;i<ALPHABET_SIZE;i++)
            node->children[i] = NULL;
    }
    return node;
}
void insert(struct trie_node* root,const char* str)
{
    int level = 0;
    int length = strlen(str);
    int index;
    trie_node* crawl = root;
    for(level = 0;level<length;level++)
    {
        index = CHAR_TO_INDEX(str[level]);
        if(!crawl->children[index])
            crawl->children[index] = get_trie_node();
        crawl = crawl->children[index];
    }
    crawl->is_leaf = true;
}
int search(struct trie_node* root, char* str)
{
    struct trie_node* crawl = root;
    int level = 0;
    int length = strlen(str);
    for(level = 0;level<length;level++)
    {
        int index = CHAR_TO_INDEX(str[level]);
        if(!crawl->children[index])
            return 0;
        crawl = crawl->children[index];
    }
    return (crawl!=NULL && crawl->is_leaf);
}
int main()
{
    char input[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};


    struct trie_node *root = get_trie_node();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(input); i++)
        insert(root, input[i]);

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );

    return 0;
}
