#include <stdio.h>
#include <stdlib.h>

// 定义桶的结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 插入排序，用于对每个桶内部进行排序
void insertionSort(Node** bucket) {
    Node* sorted = NULL;
    Node* current = *bucket;

    while (current != NULL) {
        Node* next = current->next;

        // 插入排序
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *bucket = sorted;
}

// 桶排序
void bucketSort(int arr[], int n) {
    // 选择桶的数量，这里简单地选择与数组长度相等的桶数量
    const int numBuckets = n;

    // 创建桶数组（动态内存分配）
    Node** buckets = (Node**)malloc(numBuckets * sizeof(Node*));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    // 将元素分配到桶中
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * numBuckets / (100 + 1);  // 适应具体的数据范围
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 对每个桶内部进行排序
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(&buckets[i]);
    }

    // 合并桶中的元素得到有序数组
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    // 释放桶数组的动态内存
    free(buckets);
}

// 测试桶排序
int main() {
    int arr[] = { 29, 10, 14, 37, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n排序后数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

