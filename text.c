#include <stdio.h>
#include <stdlib.h>

// ����Ͱ�Ľṹ��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �����������ڶ�ÿ��Ͱ�ڲ���������
void insertionSort(Node** bucket) {
    Node* sorted = NULL;
    Node* current = *bucket;

    while (current != NULL) {
        Node* next = current->next;

        // ��������
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

// Ͱ����
void bucketSort(int arr[], int n) {
    // ѡ��Ͱ������������򵥵�ѡ�������鳤����ȵ�Ͱ����
    const int numBuckets = n;

    // ����Ͱ���飨��̬�ڴ���䣩
    Node** buckets = (Node**)malloc(numBuckets * sizeof(Node*));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    // ��Ԫ�ط��䵽Ͱ��
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * numBuckets / (100 + 1);  // ��Ӧ��������ݷ�Χ
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // ��ÿ��Ͱ�ڲ���������
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(&buckets[i]);
    }

    // �ϲ�Ͱ�е�Ԫ�صõ���������
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

    // �ͷ�Ͱ����Ķ�̬�ڴ�
    free(buckets);
}

// ����Ͱ����
int main() {
    int arr[] = { 29, 10, 14, 37, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("ԭʼ���飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\n��������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

