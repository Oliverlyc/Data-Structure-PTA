#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxTree 30
typedef struct TNode *BinTree;
struct TNode
{
    int Data;
    BinTree Left;
    BinTree Right;
};
int top = -1;
int count = 0;
BinTree stack[MaxTree];
void push(BinTree T)
{
    stack[++top] = T;
}
BinTree pop()
{
    return stack[top--];
}
BinTree stackCreateTree()
{
    int poped = 0, N, i, data, isRoot = 0;
    char methord[5];
    BinTree T, father, root;

    // printf("请输入节点个数：\n");
    scanf(" %d", &N);
    for (i = 0; i < 2 * N; i++)
    {
        // printf("第%d个操作\n", i);
        scanf(" %s", methord);
        if (strcmp(methord, "Push") == 0)
        {
            printf("输入数据:\n");
            scanf("%d", &data);
            T = (BinTree)malloc(sizeof(struct TNode));
            T->Data = data;
            T->Left = NULL;
            T->Right = NULL;
            if (isRoot == 0)
            {
                father = T;
                root = father;
                push(father);
                isRoot = 1;
            }
            else
            {
                if (poped != 1)
                {
                    father = stack[top];
                }
                if (father->Left == NULL)
                {
                    father->Left = T;
                    push(T);
                }
                else
                {
                    father->Right = T;
                    push(T);
                }
            }
            poped = 0;
        }
        else
        {
            father = pop();
            poped = 1;
        }
    }
    return root;
}
void PostOrderTraval(BinTree T)
{
    if (T)
    {
        PostOrderTraval(T->Left);
        PostOrderTraval(T->Right);
        if (count == 0)
        {
            printf("%d", T->Data);
            count = 1;
        }
        else
        {
            printf(" %d", T->Data);
        }
    }
}
int main()
{
    BinTree root;
    int a;
    root = stackCreateTree();
    PostOrderTraval(root);
    scanf("%d", &a);
    return 0;
}