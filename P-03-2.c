// 这道题题意是第一行输入结点数，然后每一行对应当前结点指向的子结点，没有出现的便是根结点，最后层序输出，可以用数组实现
#include <stdio.h>
#include <malloc.h>
#define null -1
typedef struct QNode *PtrToQNode;
struct TNode
{
    int Element;
    int Left;
    int Right;
}T[15];
struct QNode
{
    int *Data;
    int Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;
int createTree(int N)
{
    int root = null;
    int i;
    char cl,cr;
    int check[N];
    if (N) {
        for(i = 0 ;i<N;i++){
            check[i] = 0;
        }
        for(i = 0;i<N;i++){
            printf("请输入第%d个结点数据：\n", i);
            scanf(" %c %c", &cl, &cr);
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = null;
            }
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = null;
            }
        }
        
        for(i = 0;i<N;i++){
            if(!check[i]){
                root = i;
                break;
            }
        }
    }else{
        return 0;
    }
    return root;
}
Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (int *)malloc(MaxSize * sizeof(int));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
int QueueIsFull(Queue Q)
{
    return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}
int AddQ(Queue Q, int X)
{
    if (QueueIsFull(Q))
    {
        printf("队列满");
        return 0;
    }
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return 1;
    }
}
int QueueIsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}
int DeleteQ(Queue Q)
{
    if (QueueIsEmpty(Q))
    {
        return 0;
    }
    else
    {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}
void printLeaves(int root,int N)
{
    
    if (N ==1) {
        printf("0");
        return ;
    }
    
    Queue Q;
    int count=0;
    Q = CreateQueue(N);
    AddQ(Q,root);
    while(!QueueIsEmpty(Q)){
        root = DeleteQ(Q);
        if (T[root].Left == -1 && T[root].Right == -1)
        {
            if(count == 0){
                printf("%d", root);
                count = 1;
            }else{
                printf(" %d",root);
            }
        }
        if(T[root].Left != -1){
            AddQ(Q,T[root].Left);
        }
        
        if (T[root].Right != -1) {
            AddQ(Q,T[root].Right);
        }
    }
}
int main()
{
    int root,i,N;
    printf("请输入结点个数：\n");
    scanf(" %d",&N);
    root = createTree(N);
    printLeaves(root,N);
    scanf("%d", &i);
    return 0;
}