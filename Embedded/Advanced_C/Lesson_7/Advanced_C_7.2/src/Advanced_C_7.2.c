/*
 ============================================================================
Задача 7-2-Вид сверху
В программе описана структура для хранения двоичного дерева:
typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:
void btUpView(tree *root)
В качестве ответа загрузите только одну функцию void btUpView(tree *root)
Пример №1
Данные на входе:

       10
      /   \
     5     15
    / \   /  \
   3   7 13   18
  /   /
 1   6

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Определение структуры узла дерева
typedef int datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
} tree;

// Узел для очереди
typedef struct QueueNode
{
    tree *node;
    int horizontalDistance;
    struct QueueNode *next;
} QueueNode;

// Очередь для обхода дерева в ширину
typedef struct Queue
{
    QueueNode *front, *rear;
} Queue;

// Создание нового узла очереди
QueueNode* newQueueNode(tree *node, int hd)
{
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->horizontalDistance = hd;
    temp->next = NULL;
    return temp;
}

// Инициализация очереди
Queue* createQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Добавление узла в очередь
void enqueue(Queue *q, tree *node, int hd)
{
    QueueNode *temp = newQueueNode(node, hd);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Удаление узла из очереди
QueueNode* dequeue(Queue *q)
{
    if (q->front == NULL)
        return NULL;

    QueueNode *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

// Структура для хранения минимального и максимального горизонтального расстояния
typedef struct
{
    int min, max;
} MinMax;

// Обновление минимального и максимального горизонтального расстояния
void updateMinMax(MinMax *mm, int hd)
{
    if (hd < mm->min) mm->min = hd;
    if (hd > mm->max) mm->max = hd;
}

// Печать вида дерева сверху
void btUpView(tree *root)
{
    if (root == NULL)
        return;

    // Инициализация структуры для хранения минимального и максимального горизонтального расстояния
    MinMax mm = {INT_MAX, INT_MIN};

    // Очередь для обхода дерева в ширину
    Queue *q = createQueue();

    // Хэш-таблица для хранения первого узла на каждом горизонтальном уровне
    int hashTable[1000] = {0};

    // Флаг для проверки, был ли уже добавлен узел на данном уровне
    int isSet[1000] = {0};

    // Начало обхода с корневого узла
    enqueue(q, root, 0);

    while (q->front != NULL)
    {
        QueueNode *temp = dequeue(q);

        int hd = temp->horizontalDistance;
        tree *node = temp->node;

        // Если на данном уровне еще не добавлен узел, добавляем его
        if (!isSet[hd + 500]) // Смещение на 500 для работы с отрицательными индексами
        {
            hashTable[hd + 500] = node->key;
            isSet[hd + 500] = 1;
        }

        // Обновление минимального и максимального горизонтального расстояния
        updateMinMax(&mm, hd);

        // Добавление левого и правого потомков в очередь с обновленным горизонтальным расстоянием
        if (node->left != NULL)
            enqueue(q, node->left, hd - 1);
        if (node->right != NULL)
            enqueue(q, node->right, hd + 1);

        free(temp);
    }

    // Печать узлов в порядке от минимального до максимального горизонтального расстояния
    for (int i = mm.min; i <= mm.max; i++)
    {
        printf("%d ", hashTable[i + 500]);
    }
}

// Функция для создания нового узла дерева
tree* newTreeNode(datatype key)
{
    tree* node = (tree*)malloc(sizeof(tree));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Пример использования функции
int main()
{
    // Создаем дерево согласно заданной структуре
    tree* root = newTreeNode(10);
    root->left = newTreeNode(5);
    root->right = newTreeNode(15);

    root->left->left = newTreeNode(3);
    root->left->right = newTreeNode(7);

    root->right->left = newTreeNode(13);
    root->right->right = newTreeNode(18);

    root->left->left->left = newTreeNode(1);
    root->left->right->left = newTreeNode(6);

    printf("Вид сверху: ");
    btUpView(root);

    return 0;
}


