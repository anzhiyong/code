#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  // 线性表中最大元素个数

typedef int KeyType; // 关键字类型
typedef struct {
    KeyType Key; // 关键字域
} LineList; // 线性表元素类型

// 直接插入排序
void InsertSort(LineList r[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        r[0] = r[i]; // 设置监视哨
        j = i - 1;
        while (r[0].Key < r[j].Key) {
            r[j + 1] = r[j];
            j--;
        }
        r[j + 1] = r[0];
    }
}

// 希尔排序
void ShellSort(LineList r[], int n) {
    int i, j, d = n / 2; // 初始步长为表长的一半
    while (d > 0) {
        for (i = d + 1; i <= n; i++) {
            r[0] = r[i]; // 设置监视哨
            j = i - d;
            while (j > 0 && r[0].Key < r[j].Key) {
                r[j + d] = r[j];
                j -= d;
            }
            r[j + d] = r[0];
        }
        d /= 2;
    }
}

// 冒泡排序
void BubbleSort(LineList r[], int n) {
    int i, j, exchange;
    LineList temp;
    for (i = 1; i < n; i++) {
        exchange = 0;
        for (j = 1; j <= n - i; j++) {
            if (r[j].Key > r[j + 1].Key) {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                exchange = 1;
            }
        }
        if (exchange == 0) return; // 提前结束
    }
}

// 快速排序
void QuickSort(LineList r[], int first, int end) {
    if (first >= end) return;
    int i = first, j = end;
    LineList temp = r[i];
    while (i < j) {
        while (i < j && r[j].Key >= temp.Key) j--;
        r[i] = r[j];
        while (i < j && r[i].Key <= temp.Key) i++;
        r[j] = r[i];
    }
    r[i] = temp;
    QuickSort(r, first, i - 1);
    QuickSort(r, i + 1, end);
}

// 直接选择排序
void SelectSort(LineList r[], int n) {
    int i, j, k;
    LineList x;
    for (i = 1; i <= n; i++) {
        k = i;
        for (j = i + 1; j <= n; ++j) {
            if (r[j].Key < r[k].Key) k = j;
        }
        if (k != i) {
            x = r[i];
            r[i] = r[k];
            r[k] = x;
        }
    }
}

// 堆排序辅助筛选函数
void Sift(LineList r[], int low, int high) {
    int i = low, j = 2 * i;
    LineList tmp = r[i];
    while (j <= high) {
        if (j < high && r[j].Key < r[j + 1].Key) j++;
        if (tmp.Key < r[j].Key) {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    r[i] = tmp;
}

// 堆排序
void HeapSort(LineList r[], int n) {
    int i;
    LineList tmp;
    for (i = n / 2; i >= 1; i--) Sift(r, i, n);
    for (i = n; i >= 1; i--) {
        tmp = r[1];
        r[1] = r[i];
        r[i] = tmp;
        Sift(r, 1, i - 1);
    }
}

// 归并排序辅助函数：合并两个相邻有序段
void Merge(LineList r[], int low, int mid, int high) {
    LineList *r1 = (LineList *)malloc((high - low + 1) * sizeof(LineList));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (r[i].Key <= r[j].Key) r1[k++] = r[i++];
        else r1[k++] = r[j++];
    }
    while (i <= mid) r1[k++] = r[i++];
    while (j <= high) r1[k++] = r[j++];
    for (i = low, k = 0; i <= high; i++, k++) r[i] = r1[k];
    free(r1);
}

// 归并排序
void MergeSort(LineList r[], int n) {
    int length, i;
    for (length = 1; length < n; length *= 2) {
        for (i = 1; i + 2 * length - 1 <= n; i += 2 * length) {
            Merge(r, i, i + length - 1, i + 2 * length - 1);
        }
        if (i + length - 1 < n) Merge(r, i, i + length - 1, n);
    }
}

// 输出排序后的记录
void OutList(LineList r[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%5d", r[i].Key);
    }
    printf("\n");
}

// 排序菜单
void MenuSort() {
    printf("\n排序子系统\n");
    printf("========================\n");
    printf("| 1——更新排序数据      |\n");
    printf("| 2——直接插入排序      |\n");
    printf("| 3——希尔排序          |\n");
    printf("| 4——冒泡排序          |\n");
    printf("| 5——快速排序          |\n");
    printf("| 6——直接选择排序      |\n");
    printf("| 7——堆排序            |\n");
    printf("| 8——归并排序          |\n");
    printf("| 0——返回              |\n");
    printf("========================\n");
    printf("请输入菜单号(0-8): ");
}

// 主函数
int Sort() {
    LineList r[MAXSIZE];
    int n, i;
    char ch1 = 'y', ch2;
    while (ch1 == 'y' || ch1 == 'Y') {
        MenuSort();
        scanf(" %c", &ch2);
        getchar();
        switch (ch2) {
            case '1':
                printf("请输入待排序表的长度: ");
                scanf("%d", &n);
                printf("请输入%d个整数: ", n);
                for (i = 1; i <= n; i++) scanf("%d", &r[i].Key);
                OutList(r, n);
                break;
            case '2':
                InsertSort(r, n);
                printf("进行直接插入排序: ");
                OutList(r, n);
                break;
            case '3':
                ShellSort(r, n);
                printf("进行希尔排序: ");
                OutList(r, n);
                break;
            case '4':
                BubbleSort(r, n);
                printf("进行冒泡排序: ");
                OutList(r, n);
                break;
            case '5':
                QuickSort(r, 1, n);
                printf("进行快速排序: ");
                OutList(r, n);
                break;
            case '6':
                SelectSort(r, n);
                printf("进行直接选择排序: ");
                OutList(r, n);
                break;
            case '7':
                HeapSort(r, n);
                printf("进行堆排序: ");
                OutList(r, n);
                break;
            case '8':
                MergeSort(r, n);
                printf("进行归并排序: ");
                OutList(r, n);
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("输入有误，请输入0-8进行选择!\n");
        }
        if (ch2 != '0') {
            printf("\n按回车键继续，按任意键返回主菜单!\n");
            char a = getchar();
            if (a != '\n') ch1 = 'n';
        }
    }
    return 0;
}
