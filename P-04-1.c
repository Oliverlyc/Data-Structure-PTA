//
// Created by lenovo on 2019/4/3.
//

//判断是否为同一个二叉树
//判别方法：在树T中按顺序搜索序列，看位置是否一致
#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode *Tree;

struct TreeNode{
    int value;
    Tree Left,Right;
//    int flag;
};

int compare(Tree A, Tree B)
{
    //1位不相同，0为相同
    int flag = 0;
    if(A){
        if(!B){
            return 1;
        }
        if(A->value != B->value){
            return 1;
        }
        if(compare(A->Left, B->Left)){
            return 1;
        }
        if(compare(A->Right, B->Right)){
            return 1;
        }
    }else if(B){
        return 1;
    }
    return flag;
}

Tree Insert(Tree T, int value)
{
    Tree NewT = (Tree)malloc(sizeof(struct TreeNode));
    NewT->Left = NewT->Right = NULL;
    NewT->value = value;

    Tree Tmp = T;
    while (T){
        if (value < T->value){
            if (T->Left){
                T = T->Left;
            }else{
                T->Left = NewT;
                return Tmp;
            }
        }else if(value > T->value){
            if(T->Right){
                T = T->Right;
            }else{
                T->Right = NewT;
                return Tmp;
            }
        }
    }
    return NewT;
}
int main()
{
    int N,L=0,value,i,j,k;
    Tree A, B;
    scanf("%d",&N);
    while(N){
        scanf("%d", &L);
        A = NULL;
//        printf("%d",L);
        for (i = 0; i < N; ++i) {
            scanf("%d", &value);
            A = Insert(A, value);
        }

        for (j = 0; j < L; ++j) {
            B = NULL;
            for (k = 0; k < N; ++k) {
                scanf("%d", &value);
                B = Insert(B, value);
            }
            if (compare(A, B)){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
            free(B);
        }
        scanf("%d",&N);
    }
    return 0;
}

//第二个测试点会有问题
//Tree NewNode(int v)
//{
//    Tree T = (Tree)malloc(sizeof(struct TreeNode));
//    T->value = v;
//    T->Left = T->Right = NULL;
//    T->flag = 0;
//    return T;
//}
//Tree Insert(Tree T, int v)
//{
//    if(!T)
//        T = NewNode(v);
//    else{
//        if(v > T->value)
//            T->Right = Insert(T->Right, v);
//        else
//            T->Left = Insert(T->Left, v);
//    }
//    return T;
//}
//
//
//
//Tree MakeTree(int N)
//{
//    Tree T;
//    int v;//v结点值
//    scanf("%d",&v);
//    T = NewNode(v);//新建结点树
//    for (int j = 1; j < N; ++j) {
//        scanf("%d", &v);
//        T = Insert(T, v);
//    }
//    return T;
//}
//
//int check(Tree T, int v)
//{
//    if(T->flag){
//        //该结点已查找过
//        if(v < T->value){
//            return check(T->Left, v);
//        }else if(v > T->value){
//            return check(T->Right, v);
//        }else{
//            return 0;
//        }
//    }else{
//        if(v == T->value){
//            T->flag = 1;
//            return 1;
//        }else{
//            return 0;
//        }
//    }
//}
//
//int Judge(Tree T, int N)
//{
//    int v;
//    int flag = 0;
//    scanf("%d", &v);
//    if(v != T->value){
//        flag = 1;
//    }else{
//        T->flag = 1;
//    }
//    for (int i = 1; i < N; ++i) {
//        scanf("%d", &v);
//        if((!flag)&&(!check(T,v)))
//            flag = 1;
//    }
//    if(flag)
//        return 0;
//    else
//        return 1;
//}
//
//void ResetT(Tree T)
//{
//    if(T->Left){
//        ResetT(T->Left);
//    }else if(T->Right){
//        ResetT(T->Right);
//    }
//    T->flag = 0;
//}
//void FreeTree(Tree T)
//{
//    if(T->Left){
//        FreeTree(T->Left);
//    }else if(T->Right){
//        FreeTree(T->Right);
//    }
//    free(T);
//}
//int main()
//{
//    int N,L;
//    //N输入序列结点个数，L序列个数
//    Tree T;
//    scanf("%d", &N);
//    while (N){
//        scanf("%d", &L);//读入序列个数
//        T = MakeTree(N);
//        for (int i = 0; i < L; ++i) {
//            if(Judge(T,N))
//                printf("Yes\n");
//            else
//                printf("No\n");
//            ResetT(T); //清除flag
//        }
//        FreeTree(T);
//        scanf("%d", &N);
//    }
//}