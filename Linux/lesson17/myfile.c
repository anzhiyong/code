#include <stdio.h>

int main()
{
    FILE *fp = fopen("log.txt", "w");
    if(fp < 0)
    {
        perror("fopen");
    }

    const char *str = "hello an\n";

    int i = 0;
    while(i < 10)
    {
        fputs(str, fp);
        i++;
    }


    fclose(fp);
    return 0;
}