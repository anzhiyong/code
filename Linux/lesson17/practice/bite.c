#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// 1.考察open， read, write, lseek， close等函数的使用。同时理解文件描述符

// 2.要求:

// 2.1 使用代码打开当前路径下的“bite”文件（如果文件不存在在创建文件），向文件当中写入“i like linux!”.

// 2.2 在从文件当中读出文件当中的内容， 打印到标准输出当中； 关闭文件描述符

// 3.提交要求：提交代码截图， 提交代码执行之后的截图

int main()
{
    char *message = "i like linux!";
    int fd = open("bite.txt", O_RDWR);
    if (fd == -1)
    {
        perror("打开失败");
        return 1;
    }

    size_t w = write(fd, message, strlen(message));
    if (w == -1)
    {
        perror("写入失败");
        return 2;
    }

    // 移动文件指针到文件开头
    lseek(fd, 0, SEEK_SET);

    char s[100];
    size_t r = read(fd, s, strlen(message));

    s[r] = '\0'; // 确保字符串正确结束
    printf("%s\n", s);

    close(fd);

    return 0;
}

// 1.考察fopen, fread, fwrite, fseek, fclose等函数的使用

// 2.要求：

// 2.1使用代码打开当前路径下的“bite”文件（如果文件不存在在创建文件），向文件当中写入“linux so easy!”.

// 2.2 在从文件当中读出文件当中的内容， 打印到标准输出当中； 关闭文件流指针

// 3.提交要求：提交代码截图， 提交代码执行之后的截图
// int main()
// {
//     FILE *fp = fopen("bite.txt", "w");
//     if (fp == NULL) { // 检查文件打开是否成功
//         perror("打开失败");
//         return 1;
//     }
//     char s[] = "linux so easy!";
//     fwrite(s, sizeof(char), strlen(s), fp);
//     fclose(fp);

//     fp = fopen("bite.txt", "r+");
//     if (fp == NULL) { // 检查文件打开是否成功
//         perror("打开失败");
//         return 1;
//     }

//     // 使用 fseek 将文件指针移动到文件开头
//     fseek(fp, 0, SEEK_SET);  // 将文件指针移到文件开头

//     char ps[100];
//     fread(ps, sizeof(char), strlen(s), fp);
//     printf("%s\n", ps);

//     fclose(fp);

//     return 0;
// }