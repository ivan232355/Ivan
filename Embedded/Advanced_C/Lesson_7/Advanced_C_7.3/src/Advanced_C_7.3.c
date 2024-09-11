/*
 ============================================================================
В программе описано двоичное дерево:
typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; //ссылка на родителя
} tree;
Требуется реализовать функцию, которая по ключу возвращает адрес соседнего элемента - брата. Если такого ключа нет или у узла
нет брата, то необходимо вернуть 0. Прототип функции: tree * findBrother(tree *root, int key)

Загрузите в качестве ответа только текст функции, строго согласно прототипу: tree * findBrother(tree *root, int key)
Пример №1
Данные на входе:

        10
      /   \
     5     15
    / \   /  \
   3   7 13   18
  /   /
 1   6

Например, для дерева узел с ключом 3
Данные на выходе:	имеет брата 7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла дерева
typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} tree;

// Функция для создания нового узла
tree* createNode(int key, tree* parent)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    if (newNode == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

// Функция для поиска "брата" узла с заданным ключом
tree* findBrother(tree *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Поиск узла с заданным ключом
    if (root->key == key)
    {
        // Если у узла нет родителя, значит он корень и не имеет брата
        if (root->parent == NULL)
        {
            return NULL;
        }

        // Проверка, является ли узел левым или правым ребенком родителя
        if (root->parent->left == root)
        {
            // Если узел является левым ребенком, возвращаем правого ребенка, если он существует
            return root->parent->right;
        } else
        {
            // Если узел является правым ребенком, возвращаем левого ребенка, если он существует
            return root->parent->left;
        }
    }

    // Рекурсивный поиск в левом и правом поддеревьях
    tree *leftResult = findBrother(root->left, key);
    if (leftResult != NULL)
    {
        return leftResult;
    }

    return findBrother(root->right, key);
}

// Пример использования функции
int main(void)
{
    // Создание дерева, соответствующего заданной структуре
    tree *root = createNode(10, NULL);
    root->left = createNode(5, root);
    root->right = createNode(15, root);

    root->left->left = createNode(3, root->left);
    root->left->right = createNode(7, root->left);

    root->right->left = createNode(13, root->right);
    root->right->right = createNode(18, root->right);

    root->left->left->left = createNode(1, root->left->left);
    root->left->right->left = createNode(6, root->left->right);

    int key = 3;  // Измените это значение для поиска брата другого узла
    tree *brother = findBrother(root, key);

    if (brother != NULL)
    {
        printf("Брат узла с ключом %d имеет ключ %d\n", key, brother->key);
    } else
    {
        printf("У узла с ключом %d нет брата\n", key);
    }

    // Освобождение памяти
    free(root->left->left->left);
    free(root->left->right->left);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}

