#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cuckoo_entry
{
    char* key;
    int value;
};

struct cuckoo
{
    int size;
    struct cuckoo_entry* left_entries;
    struct cuckoo_entry* right_entries;
};

void cuckoo_create(struct cuckoo* cuckoo)
{
    int i;

    cuckoo->size = 11;
    cuckoo->left_entries = (struct cuckoo_entry*)malloc(cuckoo->size * sizeof(struct cuckoo_entry));
    cuckoo->right_entries = (struct cuckoo_entry*)malloc(cuckoo->size * sizeof(struct cuckoo_entry));
    for (i = 0; i < cuckoo->size; i++)
    {
        cuckoo->left_entries[i].key = NULL;
        cuckoo->right_entries[i].key = NULL;
    }
}

void cuckoo_delete(struct cuckoo* cuckoo)
{
    int i;

    for (i = 0; i < cuckoo->size; i++)
    {
        if (cuckoo->left_entries[i].key != NULL)
        {
            free(cuckoo->left_entries[i].key);
        }
        if (cuckoo->right_entries[i].key != NULL)
        {
            free(cuckoo->right_entries[i].key);
        }
    }
    free(cuckoo->left_entries);
    free(cuckoo->right_entries);
}

void cuckoo_insert(struct cuckoo* cuckoo, char* key, int value)
{
    char* p;
    char* k;
    int v;
    char* tk;
    int tv;
    int hash1;
    int hash2;

    k = malloc(strlen(key) + 1);
    strcpy(k, key);
    v = value;

    while (1)
    {
        hash1 = 0;
        p = k;        
        while (*p != '\0')
        {
            hash1 = hash1 * 37;
            hash1 = hash1 + *p;
            p++;
        }
        hash1 = hash1 % cuckoo->size;
        if (cuckoo->left_entries[hash1].key == NULL)
        {
            cuckoo->left_entries[hash1].key = k;
            cuckoo->left_entries[hash1].value = v;
            return;
        }
        else
        {
            tk = cuckoo->left_entries[hash1].key;
            tv = cuckoo->left_entries[hash1].value;
            cuckoo->left_entries[hash1].key = k;
            cuckoo->left_entries[hash1].value = v;
            k = tk;
            v = tv;
        }
        hash2 = 0;
        p = k;
        while (*p != '\0')
        {
            hash2 = hash2 * 41;
            hash2 = hash2 + *p;
            p++;
        }
        hash2 = hash2 % cuckoo->size;

        if (cuckoo->right_entries[hash2].key == NULL)
        {
            cuckoo->right_entries[hash2].key = k;
            cuckoo->right_entries[hash2].value = v;
            return;
        }
        else
        {
            tk = cuckoo->right_entries[hash2].key;
            tv = cuckoo->right_entries[hash2].value;
            cuckoo->right_entries[hash2].key = k;
            cuckoo->right_entries[hash2].value = v;
            k = tk;
            v = tv;
        }
    }
}

int cuckoo_access(struct cuckoo* cuckoo, char* key, int* result)
{
    char* p;
    int hash1;
    int hash2;

    hash1 = 0;
    hash2 = 0;
    p = key;
    while (*p != '\0')
    {
        hash1 = hash1 * 37;
        hash1 = hash1 + *p;
        hash2 = hash2 * 41;
        hash2 = hash2 + *p;
        p++;
    }
    hash1 = hash1 % cuckoo->size;
    hash2 = hash2 % cuckoo->size;
    if (cuckoo->left_entries[hash1].key != NULL)
    {
        if (strcmp(key, cuckoo->left_entries[hash1].key) == 0)
        {
            *result = cuckoo->left_entries[hash1].value;
            return 1;
        }
    }
    if (cuckoo->right_entries[hash2].key != NULL)
    {
        if (strcmp(key, cuckoo->right_entries[hash2].key) == 0)
        {
            *result = cuckoo->right_entries[hash2].value;
            return 1;
        }
    }
    return 0;
}

int cuckoo_remove(struct cuckoo* cuckoo, char* key)
{
    char* p;
    int hash1;
    int hash2;

    hash1 = 0;
    hash2 = 0;
    p = key;
    while (*p != '\0')
    {
        hash1 = hash1 * 37;
        hash1 = hash1 + *p;
        hash2 = hash2 * 41;
        hash2 = hash2 + *p;
        p++;
    }
    hash1 = hash1 % cuckoo->size;
    hash2 = hash2 % cuckoo->size;
    if (cuckoo->left_entries[hash1].key != NULL)
    {
        if (strcmp(key, cuckoo->left_entries[hash1].key) == 0)
        {
            free(cuckoo->left_entries[hash1].key);
            cuckoo->left_entries[hash1].key = NULL;
            return 1;
        }
    }
    if (cuckoo->right_entries[hash2].key != NULL)
    {
        if (strcmp(key, cuckoo->right_entries[hash2].key) == 0)
        {
            free(cuckoo->right_entries[hash2].key);
            cuckoo->right_entries[hash2].key = NULL;
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct cuckoo hash;
    int result;

    cuckoo_create(&hash);
    cuckoo_insert(&hash, "Hello", 1);
    cuckoo_insert(&hash, "World", 2);
    cuckoo_remove(&hash, "World");
    if (cuckoo_access(&hash, "Hello", &result))
    {
        printf("%d \n", result);
    }
    if (cuckoo_access(&hash, "World", &result))
    {
        printf("%d \n", result);
    }
    cuckoo_delete(&hash);
    return 0;
}