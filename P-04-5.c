//
// Created by lenovo on 2019/4/5.
//

//给定序列建立平衡二叉树，返回根结点
//要解决的问题主要是要判断树高是否影响平衡
#include <stdio.h>
#include <malloc.h>
typedef struct AVLNode *Position;
typedef Position AVLTree;

struct AVLNode{
    int Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

AVLTree Insert(AVLTree T, int X);
int GetTreeHeight(AVLTree T);
AVLTree SingleLeftRotation(AVLTree T);//左单旋
AVLTree SingleRightRotation(AVLTree T);//右单旋
AVLTree DoubleLeftRightRotation(AVLTree T);//左右双旋
AVLTree DoubleRightLeftRotation(AVLTree T);//右左双旋
int Max(int a, int b);//左右子树最大高度

int main()
{
    AVLTree T = NULL;
    int N, i, X;
//    T = (AVLTree)malloc(sizeof(struct AVLNode));
    scanf("%d\n",&N);//结点个数
    for (i = 0; i < N; ++i) {
        scanf("%d", &X);
        T = Insert(T, X);
    }
    printf("%d\n", T->Data);
    return 0;
}

AVLTree Insert(AVLTree T, int X)
{
    //空树
    if(!T){
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Left = T->Right = NULL;
        T->Data = X;
        T->Height = 1;
    }
    //非空树
    else if(X < T->Data){
        T->Left = Insert(T->Left, X);
        if(GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == 2){
            if(X < T->Left->Data){
                T = SingleLeftRotation(T);//左单旋
            }else{
                T = DoubleLeftRightRotation(T);//左右双旋
            }
        }
    }else if(X > T->Data){
        T->Right = Insert(T->Right, X);
        if(GetTreeHeight(T->Left) - GetTreeHeight(T->Right) == -2) {
            if (X > T->Right->Data) {
                T = SingleRightRotation(T);
            } else {
                T = DoubleRightLeftRotation(T);
            }
        }
    }
    T->Height = Max(GetTreeHeight(T->Left), GetTreeHeight(T->Right)) +1;
    return T;
}
int GetTreeHeight(AVLTree T)
//递归得到树的高度
{
    int HL, HR, H;
    if (!T) return 0;
    else{
        HL = GetTreeHeight(T->Left );
        HR = GetTreeHeight(T->Right );
        H = Max(HL, HR);

        return (H+1);
    }
}
AVLTree SingleLeftRotation(AVLTree T)
//左单旋，A必须有一个左子结点B
//左旋时，A的左子结点B的左子树不动，A的右子树不动
{
    AVLTree B = T->Left ;
    T->Left = B->Right ;
    B->Right = T;
    T->Height = Max(GetTreeHeight(T->Left ),GetTreeHeight(T->Right )) + 1;
    B->Height = Max(GetTreeHeight(B->Left ),T->Height )+ 1;

    return B;
}
AVLTree SingleRightRotation(AVLTree T)
//右单旋，A必须有一个右子结点B
//右旋时，A的右子结点B的右子树不动，A的左子树不动
{
    AVLTree B = T->Right ;
    T->Right = B->Left ;
    B->Left = T;
    T->Height = Max(GetTreeHeight(T->Left ),GetTreeHeight(T->Right )) + 1;
    B->Height = Max(GetTreeHeight(B->Right ),T->Height) + 1;

    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree T)
//左-右双旋，A必须有一个左子结点B，B必须有一个右子结点C
{
    //B与C做一次右单旋，C被返回
    AVLTree B = T->Left ;
    AVLTree C = B->Right ;
    T->Left = SingleRightRotation(B);
    //A与C做一次左单旋，C被返回
    return SingleLeftRotation(T);
}

AVLTree DoubleRightLeftRotation(AVLTree T)
//右-左双旋,A必须有一个右子结点B，B必须有一个左子结点C
{
    //B与C做一次左单旋，C被返回
    AVLTree B = T->Right ;
    AVLTree C = B->Left ;
    T->Right = SingleLeftRotation(B);
    //A与C做一次右单旋，C被返回
    return SingleRightRotation(T);
}

int Max(int a, int b)
//比较大小，返回最大值
{
    return a > b ? a : b;
}