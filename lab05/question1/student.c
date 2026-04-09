#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};  // initialize all to NULL

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        // Check if complement already exists
        if (find(table, complement, &foundIndex)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;

            freeTable(table);
            return result;
        }

        // Otherwise insert current value
        insert(table, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}

static int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];  // insert at head

    table[index] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int index = hash(key);
    Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return 1;
        }
        current = current->next;
    }

    return 0;
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
