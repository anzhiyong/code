#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int KeyType;

typedef struct {
    KeyType key;
} SearchL;

int SeqSearch(SearchL r[], int n, KeyType k) {
    int i = n;
    r[0].key = k;
    while (r[i].key != k)
        i--;
    return i;
}

int BinSearch(SearchL r[], int n, KeyType k) {
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (k == r[mid].key)
            return mid;
        else if (k < r[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

typedef struct {
    KeyType key;
    int low, high;
} IdxType;

void CreatIdx(SearchL r[], IdxType idx[], int m, int n) {
    int i, j, k = 0;
    KeyType max;
    for (i = 0; i < m; i += n) {
        max = r[i].key;
        for (j = i + 1; j < i + n && j < m; j++)
            if (r[j].key > max)
                max = r[j].key;
        idx[k].key = max;
        idx[k].low = i;
        if (i + n - 1 <= m - 1)
            idx[k].high = i + n - 1;
        else
            idx[k].high = m - 1;
        k++;
    }
}

int BlkSearch(SearchL r[], IdxType idx[], int m, KeyType k) {
    int low, high, mid, i, j, find = 0;
    i = 0;
    while (idx[i].key < k)
        i++;
    low = idx[i].low;
    high = idx[i].high;
    while (low <= high && !find) {
        mid = (low + high) / 2;
        if (k < idx[mid].key)
            high = mid - 1;
        else if (k > idx[mid].key)
            low = mid + 1;
        else {
            high = mid - 1;
            find = 1;
        }
    }
    if (low < m) {
        i = idx[low].low;
        j = idx[low].high;
    }
    while (i < j && r[i].key != k)
        i++;
    if (i >= j)
        return -1;
    else
        return i;
}

typedef struct treenode {
    KeyType key;
    struct treenode *lchild, *rchild;
} BTNode;

BTNode* BSTInsert(BTNode *bt, KeyType k) {
    BTNode *f, *p = bt;
    while (p != NULL) {
        f = p;
        if (p->key > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    p = (BTNode*)malloc(sizeof(BTNode));
    p->key = k;
    p->lchild = p->rchild = NULL;
    if (bt == NULL)
        bt = p;
    else if (k < f->key)
        f->lchild = p;
    else
        f->rchild = p;
    return bt;
}

BTNode* CreateBST(KeyType str[], int n) {
    int i = 0;
    BTNode *bt = NULL;
    while (i < n) {
        bt = BSTInsert(bt, str[i]);
        i++;
    }
    return bt;
}

void DispBStree(BTNode *bt) {
    if (bt != NULL) {
        printf("%d", bt->key);
        if (bt->lchild != NULL || bt->rchild != NULL) {
            printf(" (");
            DispBStree(bt->lchild);
            if (bt->rchild != NULL)
                printf(",");
            DispBStree(bt->rchild);
            printf(")");
        }
    }
}

BTNode* BSTDelete(BTNode *bt, KeyType k) {
    BTNode *p, *f, *s, *q;
    p = bt;
    f = NULL;
    while (p) {
        if (p->key == k)
            break;
        f = p;
        if (p->key > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (p == NULL)
        return bt;
    if (p->lchild == NULL) {
        if (f == NULL)
            bt = p->rchild;
        else if (f->lchild == p)
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild;
        free(p);
    } else {
        q = p;
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        if (q == p)
            q->lchild = s->lchild;
        else
            q->rchild = s->lchild;
        p->key = s->key;
        free(s);
    }
    return bt;
}

BTNode* BSTSearch(BTNode *bt, KeyType k) {
    if (bt == NULL)
        return NULL;
    if (k == bt->key)
        return bt;
    else if (k < bt->key)
        return BSTSearch(bt->lchild, k);
    else
        return BSTSearch(bt->rchild, k);
}

void MenuBTree() {
    printf("\n　　　　　　二叉排序树　　　");
    printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\n | 　　　1------建立二叉排序树　　　| ");
    printf("\n | 　　　2------插入一个元素　　　　| ");
    printf("\n | 　　　3------删除一个元素　　　　| ");
    printf("\n | 　　　4------查找一个元素　　　　| ");
    printf("\n | 　　　0------返回　　　　　　　　| ");
    printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\n 请输入序号(0-4) 选择要进行的操作:");
}

void BTFun() {
    KeyType str[100];
    BTNode *bt;
    int i, n, x, menux;
    MenuBTree();
    scanf("%d", &menux);
    do {
        switch (menux) {
            case 1:
                printf(" 请输入要生成二叉排序树的关键字的个数:");
                scanf("%d", &n);
                printf(" 请输入二叉排序树的各个关键字:");
                for (i = 0; i < n; i++)
                    scanf("%d", &str[i]);
                bt = CreateBST(str, n);
                printf(" 建立的二叉排序树广义表表示法为:");
                DispBStree(bt);
                break;
            case 2:
                printf(" 请输入要插入的元素值: ");
                scanf("%d", &x);
                bt = BSTInsert(bt, x);
                printf(" 插入后的二叉排序树为: ");
                DispBStree(bt);
                break;
            case 3:
                // 处理删除元素的代码
                break;
            case 4:
                // 处理查找元素的代码
                break;
        }
    } while (menux != 0);
}



#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // 哈希表大小
#define EMPTY -1      // 标记空槽位
#define DELETED -2    // 标记已删除槽位

typedef struct {
    int key; // 存储键值
} HashTable;

// 初始化哈希表
void initializeTable(HashTable table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = EMPTY;
    }
}

// 哈希函数
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 插入键值到哈希表
int insert(HashTable table[], int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (table[index].key != EMPTY && table[index].key != DELETED) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) { // 哈希表已满
            printf("哈希表已满，无法插入 %d\n", key);
            return 0;
        }
    }
    table[index].key = key;
    return 1;
}

// 查找键值
int search(HashTable table[], int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (table[index].key != EMPTY) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) { // 循环一周，未找到
            break;
        }
    }
    return -1; // 未找到
}

// 删除键值
int delete(HashTable table[], int key) {
    int index = search(table, key);
    if (index != -1) {
        table[index].key = DELETED;
        return 1;
    }
    return 0;
}

// 打印哈希表
void displayTable(HashTable table[]) {
    printf("\n哈希表内容:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].key == EMPTY) {
            printf("槽位 %d: EMPTY\n", i);
        } else if (table[i].key == DELETED) {
            printf("槽位 %d: DELETED\n", i);
        } else {
            printf("槽位 %d: %d\n", i, table[i].key);
        }
    }
}

// 哈希表菜单
int HashMenu() {
    HashTable table[TABLE_SIZE];
    initializeTable(table);
    int choice;

    do {
        printf("\n===== 哈希表子系统 =====");
        printf("\n 1. 插入键值");
        printf("\n 2. 查找键值");
        printf("\n 3. 删除键值");
        printf("\n 4. 显示哈希表");
        printf("\n 0. 退出");
        printf("\n请输入选择（0-4）：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key;
                printf("请输入要插入的键值: ");
                scanf("%d", &key);
                if (insert(table, key)) {
                    printf("键值 %d 插入成功！\n", key);
                } else {
                    printf("键值 %d 插入失败！\n", key);
                }
            } break;
            case 2: {
                int key;
                printf("请输入要查找的键值: ");
                scanf("%d", &key);
                int index = search(table, key);
                if (index != -1) {
                    printf("键值 %d 位于槽位 %d\n", key, index);
                } else {
                    printf("键值 %d 不在哈希表中！\n", key);
                }
            } break;
            case 3: {
                int key;
                printf("请输入要删除的键值: ");
                scanf("%d", &key);
                if (delete(table, key)) {
                    printf("键值 %d 删除成功！\n", key);
                } else {
                    printf("键值 %d 删除失败，键值不存在！\n", key);
                }
            } break;
            case 4:
                displayTable(table);
                break;
            case 0:
                printf("程序退出。\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
        }
    } while (choice != 0);

    return 0;
}

int Search() {
    int choice;
    do {
        printf("\n===== 查找子系统 =====");
        printf("\n 1. 顺序查找");
        printf("\n 2. 二分查找");
        printf("\n 3. 分块查找");
        printf("\n 4. 二叉排序树操作");
        printf("\n 5. 哈希表");
        printf("\n 0. 退出");
        printf("\n请输入选择（0-4）：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    SearchL r[MAXSIZE];
                    int n, i;
                    KeyType k;
                    printf("请输入元素个数：");
                    scanf("%d", &n);
                    printf("请输入元素：");
                    for (i = 1; i <= n; i++) {
                        scanf("%d", &r[i].key);
                    }
                    printf("请输入查找的元素：");
                    scanf("%d", &k);
                    int index = SeqSearch(r, n, k);
                    if (index)
                        printf("元素在顺序表中的位置为：%d\n", index);
                    else
                        printf("元素未找到。\n");
                }
                break;
            case 2:
                {
                    SearchL r[MAXSIZE];
                    int n, i;
                    KeyType k;
                    printf("请输入元素个数：");
                    scanf("%d", &n);
                    printf("请输入元素：");
                    for (i = 1; i <= n; i++) {
                        scanf("%d", &r[i].key);
                    }
                    printf("请输入查找的元素：");
                    scanf("%d", &k);
                    int index = BinSearch(r, n, k);
                    if (index)
                        printf("元素在顺序表中的位置为：%d\n", index);
                    else
                        printf("元素未找到。\n");
                }
                break;
            case 3:
                {
                    SearchL r[MAXSIZE];
                    IdxType idx[MAXSIZE];
                    int n, m, i;
                    KeyType k;
                    printf("请输入元素个数：");
                    scanf("%d", &n);
                    printf("请输入元素：");
                    for (i = 1; i <= n; i++) {
                        scanf("%d", &r[i].key);
                    }
                    printf("请输入块大小：");
                    scanf("%d", &m);
                    printf("请输入查找的元素：");
                    scanf("%d", &k);
                    CreatIdx(r, idx, n, m);
                    int index = BlkSearch(r, idx, n, k);
                    if (index != -1)
                        printf("元素在顺序表中的位置为：%d\n", index);
                    else
                        printf("元素未找到。\n");
                }
                break;
            case 4:
                BTFun();
                break;
            case 5:
                HashMenu();
                break;
            case 0:
                printf("程序退出\n");
                break;
            default:
                printf("无效选择，请重新输入。\n");
        }
    } while (choice != 0);

    return 0;
}
