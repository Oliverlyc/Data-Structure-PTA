/*
    树的同构
    通过链表的思想来解决问题，实际通过数组来存储数据结构
*/
#include<stdio.h>
#define MaxTree 15
#define Null -1
typedef char ElementType;
typedef int Tree;
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[])
{
    int N, Root = -1, i; 
    ElementType cl,cr;
    // printf("请输入结点个数:\n");
    scanf(" %d", &N);//读入结点个数
    int check[MaxTree];
    if(N){
        for(i = 0; i < N; i++){
            /* 
            这里用来判断根结点，初始值为0，被指向的结点为1
            */
            check[i] = 0;
        }
        for(i = 0; i < N; i++){
            // printf("请输入第%d个加点数据\n", i);
            scanf(" %c %c %c",&T[i].Element, &cl, &cr);
            // printf("你输入的数据为 %c %c %c \n",T[i].Element, cl, cr);
            if (cl != '-') {
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }else{
                T[i].Left = Null;
            }
            if (cr != '-') {
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }else{
                T[i].Right = Null;
            }
        }
        for(i = 0; i < N; i++){
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}
int Ismorphic(Tree R1, Tree R2)
{
    //判断空树
    if((R1 == Null)&& (R2 == Null)){
        return 1;
    }
    if(((R1 == Null)&&(R2 != Null)) || ((R1 != Null)&&(R2 == Null))){
        return 0;
    }
    //判断根结点数据
    if(T1[R1].Element != T2[R2].Element){
        return 0;
    }
    if((T1[R1].Left == Null)&&(T2[R2].Left == Null)){
        return Ismorphic(T1[R1].Right, T2[R2].Right);
    }
    if(((T1[R1].Left != Null)&&(T2[R2].Left != Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element))){
        return (Ismorphic(T1[R1].Left, T2[R2].Left)&&Ismorphic(T1[R1].Right, T2[R2].Right));
    }else{
        return (Ismorphic(T1[R1].Left, T2[R2].Right) && Ismorphic(T1[R1].Right, T2[R2].Left));
    }
}
int main()
{
    Tree R1, R2;//结点
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Ismorphic(R1, R2)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    getchar();
    return 0;
}