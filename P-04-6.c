//
// Created by lenovo on 2019/4/6.
//
//完全二叉搜索树的建立
//先层序遍历生成完全二叉树
//然后中序遍历插入数值(二叉排序树中序遍历是递增序列)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
# define Max 1000
typedef struct CBTNode *Position;
typedef Position CBTTree;
int count = 0;
struct CBTNode{
    int Data;
    CBTTree Left;
    CBTTree Right;
};

void Insert(CBTTree T,int number[]);
void SeqTraverse(CBTTree T,int N);//层序遍历，队列
CBTTree InsertTmpTree(CBTTree T, int X);

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main()
{
    CBTTree T = NULL,tempA[Max],tempB;
    int N,X,i=0,k,front = 0, rear = 1,number[Max];
    scanf("%d\n", &N);
    T = (CBTTree)malloc(sizeof(struct CBTNode));
    T->Left = T->Right = NULL;
    T->Data = 0;
    tempA[0] = T;
    for (k = 0; k < N; ++k) {
        scanf("%d", &X);
        number[k] = X;
    }
    qsort(number,N, sizeof(int),cmpfunc);
    while(i < N-1&&front<rear) {
        tempB = tempA[front++];
        if(!tempB->Left){
            i++;
            tempB->Left = InsertTmpTree(tempB->Left, i);
            tempA[rear++] = tempB->Left;

            if (i>=N-1) break;
        }
        if(!tempB->Right){
            i++;
            tempB->Right = InsertTmpTree(tempB->Right, i);
            tempA[rear++] = tempB->Right;

            if(i>=N-1) break;
        }

    }
    Insert(T,number);
    SeqTraverse(T, N);
    return 0;
}

CBTTree InsertTmpTree(CBTTree T, int X)
{
    if (!T){
        T = (CBTTree)malloc(sizeof(struct CBTNode));
        T->Left = T->Right = NULL;
        T->Data = X;
    }
    return T;
}

void Insert(CBTTree T,int number[])
{
    if (T){
        Insert(T->Left, number);
        T->Data = number[count++];
        Insert(T->Right,number);
    }
}

void SeqTraverse(CBTTree T,int N)
{
    CBTTree tmp[Max] ;
    tmp[0] = T;
    int flag = 0,j,k=0;
    for ( j = 0; j < N; ++j) {
        if (tmp[j]->Left){
            tmp[++k] = tmp[j]->Left;
        }
        if(tmp[j]->Right){
            tmp[++k] = tmp[j]->Right;
        }
        if (!flag){
            printf("%d", tmp[j]->Data);
        } else{
            printf(" %d", tmp[j]->Data);
        }
        flag++;

    }
}