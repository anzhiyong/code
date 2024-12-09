#include "SeqList.h"
#include "LinkStack.h"
#include "Queue.h"
#include "String.h"
#include "BTree.h"
#include "Graph.h"
#include "Search.h"
#include "Sort.h"

int main() {
    int choice;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y') {
        printf("\n");
        printf("\n           数据结构实验系统主菜单");
        printf("\n=====================================");
        printf("\n|           1———线性表             |");
        printf("\n|           2———栈                |");
        printf("\n|           3———队列             |");
        printf("\n|           4———串               |");
        printf("\n|           5———二叉树           |");
        printf("\n|           6———图               |");
        printf("\n|           7———查找             |");
        printf("\n|           8———排序             |");
        printf("\n|           0———退出             |");
        printf("\n=====================================");
        printf("\n请选择菜单号(0-8): ");

        scanf("%d", &choice);
        getchar(); // 清理输入缓冲区

        switch (choice) {
            case 1: 
                SeqList(); 
                break;
            case 2: 
                linkstack(); 
                break;
            case 3: 
                Queue(); 
                break;
            case 4: 
                string(); 
                break;
            case 5: 
                BTree(); 
                break;
            case 6: 
                Graph(); 
                break;
            case 7: 
                Search(); 
                break;
            case 8: 
                Sort(); 
                break;
            case 0: 
                ch = 'n'; 
                break;
            default: 
                printf("菜单选择错误! 请重新选择。\n");
        }
    }

    return 0;
}
