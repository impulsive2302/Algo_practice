// A C program to print all anagarms together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<algorithm>
struct Word{
    char* str;
    int index;
};

struct dup_array{
    struct Word* array;
    int size;
};
int compcharacter(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}
int compstr(const void* a, const void* b)
{
    struct Word* a1 = (struct Word*)a;
    struct Word* b1 = (struct Word*)b;
    return strcmp(a1->str,b1->str);
}
struct dup_array* create_dup_array(char* wordarr[],int size)
{
    struct dup_array* dup_array = (struct dup_array*) malloc(sizeof(struct dup_array));
    dup_array->size = size;
    dup_array->array = (struct Word*) malloc(size*sizeof(struct Word));
    for(int i =0;i<size;i++)
    {
        dup_array->array[i].index = i;
        dup_array->array[i].str = (char*) malloc(strlen(wordarr[i]) + 1);
        strcpy(dup_array->array[i].str, wordarr[i]);
    }
    return dup_array;
}

void printAnagramsTogether(char* wordarr[],int size)
{
    struct dup_array* duplicate = create_dup_array(wordarr,size);
    for(int i = 0;i<size;i++)
    {
        qsort(duplicate->array[i].str,strlen(duplicate->array[i].str),sizeof(char),compcharacter);
    }
    qsort(duplicate->array,size,sizeof(duplicate->array[0]),compstr);
    for (int i = 0; i < size; ++i)
        printf("%s ", wordarr[duplicate->array[i].index]);
}

// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
