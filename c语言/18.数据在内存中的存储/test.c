#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//
//int main()
//{
//    char a = -1;
//    //10000000000000000000000000000001
//    //11111111111111111111111111111110
//    //11111111111111111111111111111111
//    //�洢��a��Ҫ�����ض�
//    //11111111 - a
//    //11111111111111111111111111111111
//    //10000000000000000000000000000000
//    //10000000000000000000000000000001
//    //
//    signed char b = -1;
//    //11111111 - b
//    //
//    unsigned char c = -1;
//    //11111111 - c
//    //00000000000000000000000011111111
//    //
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    //-1 -1 255
//    //%d - ʮ���Ƶ���ʽ��ӡ�з��ŵ�����
//    //
//    return 0;
//}
//


//#include <stdio.h>
//
//int main()
//{
//    char a = -128;
//    //10000000000000000000000010000000
//    //11111111111111111111111101111111
//    //11111111111111111111111110000000
//    //10000000 - a
//    //��ӡʱ������������
//    //11111111111111111111111110000000
//    //
//    printf("%u\n", a);//4,294,967,168
//    //%u ��ʮ���Ƶ���ʽ��ӡ�޷��ŵ�����
//    //
//    return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//    char a = 128;
//    //00000000000000000000000010000000
//    //10000000 - a
//    //
//    printf("%u\n", a);
//    return 0;
//}
//

#include <stdio.h>

//int main()
//{
//    char a[1000];
//    //-128~127
//    //-1 -2 -3 ... -128 127 126 125 ... 5 4 3 2 1 0 -1 -2 ... -128 127 126 ... 5 4 3 2 1 
//    //128+127 = 255
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));//���ַ��������ҵ���\0��\0��ASCII��ֵ��0����ʵ�ҵľ���0
//    //255
//    return 0;
//}
//


//#include <stdio.h>
//
//unsigned char i = 0;
////0~255
//
//int main()
//{
//    for (i = 0; i <= 255; i++)
//    {
//        printf("hello world\n");
//    }
//    return 0;
//}


#include <stdio.h>
#include <windows.h>
//
//int main()
//{
//    unsigned int i;
//    //��ѭ��
//    for (i = 9; i >= 0; i--)
//    {
//        printf("%u\n", i);
//        Sleep(1000);//˯��1��
//    }
//
//    return 0;
//}
//


#include <stdio.h>
//
//int main()
//{
//    int a[4] = { 1, 2, 3, 4 };
//    int* ptr1 = (int*)(&a + 1);
//    int* ptr2 = (int*)((int)a + 1);
//    printf("%x,%x", ptr1[-1], *ptr2);
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 9;
//    float* pFloat = (float*)&n;//int*
//
//    printf("n��ֵΪ��%d\n", n);
//    printf("*pFloat��ֵΪ��%f\n", *pFloat);
//
//    *pFloat = 9.0;
//    printf("num��ֵΪ��%d\n", n);
//    printf("*pFloat��ֵΪ��%f\n", *pFloat);
//    return 0;
//}




//10:       5.5
//2:        101.1
//��ѧ��������1.011 * 2^2
//          (-1)^0 *1.011 *2^2
//S = 0
//E = 2
//M = 1.011


//int main()
//{
//	float f = 99.7f;
//	printf("%f\n", f);
//	//
//	//0 10000001 01100000000000000000000
//	//0x40 B0 00 00
//	//1.01100000000000000000000 *2^2
//	//
//	return 0;
//}


//
//struct Stu
//{
//    char name[20];//����
//    int age;//����
//    char sex[5];//�Ա�
//    char id[20];//ѧ��
//};
//
//int main()
//{
//    struct Stu s1 = {"zhangsan", 20, "��", "2023010204"};//����Ĭ��˳���ʼ��
//    struct Stu s2 = {.age=30, .name="lisi",.sex="nv", .id="2023020405"};//ָ��˳���ʼ��
//    printf("%s %d %s %s\n", s1.name, s1.age, s1.sex, s1.id);
//    printf("%s %d %s %s\n", s2.name, s2.age, s2.sex, s2.id);
//
//    return 0;
//}
//

//�����ṹ������
//ֻ��ʹ��һ��
//struct
//{
//    int a;
//    char b;
//    float c;
//} x;
//
//struct
//{
//    int a;
//    char b;
//    float c;
//}* p;
//
//int main()
//{
//    p = &x;//?
//    return 0;
//}





//typedef struct
//{
//    int a;
//    char b;
//    float c;
//} S;
//
//int main()
//{
//    S s1 = { 0 }, s2 = {0};
//
//    return 0;
//}
//


//struct Node
//{
//	int data;//�������
//	struct Node* next;//���дһ���ڵ�ĵ�ַ
//};

//typedef struct Node
//{
//	int data;//�������
//	struct Node* next;//���дһ���ڵ�ĵ�ַ
//}Node;
//
//int main()
//{
//
//	return 0;
//}
//

struct S1
{
	char c1;
	char c2;
	int i;
};

struct S2
{
	char c1;
	int i;
	char c2;
};


int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));

	return 0;
}


















