#include <stdio.h>
#include <stdlib.h>

typedef int DataType;  /* 定义DataType 为int 类型 */

/* 链队列存储类型 */
typedef struct qnode {
    DataType data;  /* 定义结点的数据域 */
    struct qnode *next;  /* 定义结点的指针域 */
} LinkListQ;

typedef struct {
    LinkListQ *front, *rear;  /* 定义队列的队头指针和队尾指针 */
} LinkQueue;  /* 链队列的头指针类型 */

/* 初始化链队列函数 */
LinkQueue* InitQueue() {
    LinkQueue *Q;
    LinkListQ *p;

    Q = (LinkQueue *) malloc(sizeof(LinkQueue));  /* 建立链队列头指针所指结点 */
    p = (LinkListQ *) malloc(sizeof(LinkListQ));  /* 建立链队列的头结点 */
    Q->front = p;  /* Q 指针所指的front 指针指向p */
    Q->rear = p;   /* Q 指针所指的rear 指针指向p */
    return Q;
}

/* 判断队空函数 */
int EmptyQueue(LinkQueue *Q) {
    if (Q->front == Q->rear) {  /* 链队为空 */
        return 1;
    } else {
        return 0;
    }
}

/* 入队函数 */
void InQueue(LinkQueue *Q, DataType x) {
    LinkListQ *p;
    p = (LinkListQ *) malloc(sizeof(LinkListQ));  /* 生成新结点 */
    p->data = x;  /* 将x 存入新结点的数据域 */
    p->next = NULL;
    Q->rear->next = p;  /* 将新结点插入链队之后 */
    Q->rear = p;  /* 队尾指针指向队尾元素 */
}

/* 出队函数 */
int DeQueue(LinkQueue *Q, DataType *x) {
    LinkListQ *p;
    if (EmptyQueue(Q)) {  /* 调用判空函数 */
        printf("队空，不能出队元素!\n");
        return 0;
    } else {
        p = Q->front->next;  /* p 指向队头元素 */
        *x = p->data;  /* 队头元素取出赋给x */
        Q->front->next = p->next;  /* 队头指针的指针域存放新队头元素的地址 */
        if (p->next == NULL) {  /* 队列中只含有一个元素出队 */
            Q->rear = Q->front;  /* 出队后队尾指针指向队头指针 */
        }
        free(p);  /* 释放原队头结点空间 */
        return 1;
    }
}

/* 获取队头元素函数 */
int GetFront(LinkQueue *Q, DataType *x) {
    if (EmptyQueue(Q)) {
        printf("队空，无队头元素!\n");
        return 0;
    } else {
        *x = Q->front->next->data;  /* 队头元素赋给变量x */
        return 1;
    }
}

/* 显示队中元素函数 */
void ShowQueue(LinkQueue *Q) {
    LinkListQ *p = Q->front->next;
    if (p == NULL) {
        printf("队列为空，无元素!\n");
    } else {
        printf("队列中的元素为:");
        while (p != NULL) {
            printf("%5d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

/* 显示菜单子函数 */
void MenuQueue() {
    printf("\n队列子系统");
    printf("\n===============================");
    printf("\n|       1———初始化队列       |");
    printf("\n|       2———入队操作         |");
    printf("\n|       3———出队操作         |");
    printf("\n|       4———求队头元素       |");
    printf("\n|       5———显示队中所有元素 |");
    printf("\n|       0———返回             |");
    printf("\n===============================");
    printf("\n请输入菜单号(0-5):");
}

/* 主函数 */
int Queue() {
    int i, n, flag;
    LinkQueue *Q;
    DataType x;
    char ch1 = 'y', ch2, a;

    while (ch1 == 'y' || ch1 == 'Y') {
        MenuQueue();
        scanf("%c", &ch2);
        getchar();

        switch (ch2) {
            case '1':
                Q = InitQueue();
                printf("队列的初始化完成!\n");
                break;
            case '2':
                printf("请输入要入队的元素个数: ");
                scanf("%d", &n);
                printf("请输入%d个整数进行入队:", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &x);
                    InQueue(Q, x);
                }
                printf("入队操作完成\n");
                break;
            case '3':
                printf("请输入要出队的元素个数: ");
                scanf("%d", &n);
                printf("出队的元素顺序依次为:");
                for (i = 0; i < n; i++) {
                    flag = DeQueue(Q, &x);
                    printf("%5d", x);
                }
                if (flag == 1)
                    printf("\n出队操作成功!\n");
                else
                    printf("\n出队操作失败!\n");
                break;
            case '4':
                if (GetFront(Q, &x))
                    printf("当前的队头元素值为: %d\n", x);
                break;
            case '5':
                ShowQueue(Q);
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("输入有误，请输入0~5进行选择!\n");
        }

        if (ch2 != '0') {
            printf("\n按回车键继续，按任意键返回主菜单!\n");
            a = getchar();
            if (a != '\n') {
                getchar();
                ch1 = 'n';
            }
        }
    }
    return 0;
}

