# bucketSort
用C语言实现的桶排序算法



现在，我们将逐行解释上述代码的含义：

Node* sorted = NULL;: 创建一个指向已排序序列的头部的指针，初始为空。

Node* current = *bucket;: 从桶的头部开始遍历未排序的元素，current指针指向当前未排序元素。

while (current != NULL) {: 开始一个循环，遍历桶中的每个未排序元素。

Node* next = current->next;: 保存下一个未排序元素的指针，以便在插入元素后继续遍历。

if (sorted == NULL || sorted->data >= current->data) {: 如果已排序序列为空或者当前元素的值小于等于已排序序列的第一个元素，将当前元素插入到已排序序列的头部。

current->next = sorted;: 将当前元素的下一个指针指向已排序序列。
sorted = current;: 更新已排序序列的头指针。
} else {: 如果当前元素应该插入到已排序序列的中间或末尾。

Node* temp = sorted;: 创建一个指针temp指向已排序序列的头部。

while (temp->next != NULL && temp->next->data < current->data) {: 在已排序序列中找到合适的位置，使得当前元素的值大于或等于前一个元素的值，小于或等于后一个元素的值。

temp = temp->next;: 移动temp指针到已排序序列的下一个元素。
current->next = temp->next;: 将当前元素的下一个指针指向已排序序列中找到的位置的下一个元素。

temp->next = current;: 更新已排序序列中找到的位置的下一个指针，使其指向当前元素。

}: 结束else块。

current = next;: 将current指针移动到下一个未排序元素，继续循环。

}: 结束while循环。

*bucket = sorted;: 将已排序的序列头部的指针赋值给桶的头部指针，完成插入排序。





