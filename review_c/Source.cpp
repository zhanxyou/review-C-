#define _CRT_SECURE_NO_WARNINGS //or #pragma warning(disable:4996)

#include<stdio.h>
//
//int main(void) {
//	printf("hello world\n");
//	return 0;
//
//}
//#include<stdio.h>

//int foo(void) {
//	return 5;
//}
//
//int main(int argc, char* argv[]) {
//	int a = foo();
//	printf("%d", a);
//	return 0;
//
//}

//
//#include<stdio.h>
//
//#define PI 3.1415926  //常量 宏值
//
//const int a = 10;	//常量 const
//
//int main(void) {
//	int r = 3;
//	float s, l;
//
//	s = PI * r * r;
//	l = 2 * PI * r;
//
//	printf("area and length: %f %f", s, l);
//	printf("area and length: %.2f %.2f", s, l);
//
//	return 0;
//}


//变量声明 不会开辟内存空间
//int a;
//extern int a;
//变量定义 会开辟内存空间
//int a = 3;

//int a = 1; // 4 %d 
//short b = 1; // 2 %hd
//long c = 1; // 4 %ld
//long long d = 1;// 8 %lld
//
//unsigned int a = 1; // 4 bytes  %u
//unsigned short b = 1; // 2 bytes  %hu 
//unsigned long c = 1; // 4 bytes  %lu
//unsigned long long d = 1; //8 bytes %llu

//#include<stdio.h>
//int main(void) {
//
//	size_t var = 10; //typedef unsigned int (%u) size_t定义为unsigned int 4字节
//	printf("%u", var);
//}

//字符
//int main(void) {
//	char ch1 = 'A';
//	printf("ch1 = %c %d\n", ch1, ch1);
//	char ch2 = 'm';
//	printf("ch2 = %c %d\n", ch2, ch2);
//	char ch3 = 97;
//	printf("ch3 = %c %d\n", ch3, ch3);
//
//	char ch4 = '\n';
//	printf(" '\\n' \\n 的ASCII值是 %d", ch4);
//	return 0;
//}


//浮点型
//int main(void) {
//	float v1 = 4.345f; //4 bytes 
//	double v2 = 4.345; //8 bytes
//
//	unsigned float v3 = 4.3456f;
//	unsigned double v4 = 4.3456;
//
//	printf("%.2f\n", v1);
//	printf("%8.2f\n", v1);
//	printf("%08.2f\n", v1);
//	printf("%.2lf\n", v2);
//
//	printf("%u\n", v3);
//	printf("%lu\n", v4);
//}

//进制转换 10->2
#include<math.h>

//int main(void) {
//	int a = 56; //111000
//	int b = 173; // 10101101
//	int i =0, result = 0, num=0;
//	do {
//		num = b % 2;
//		if (num != 0) {
//			result += num * pow(10, i);
//		}
//		i += 1;
//		b = b / 2;
//	} while (b != 0);
//	printf("%d", result);
//	return 0;
//}

//进制转换 8->2
//         421     421 (8进制最高为7)
//056: 5-> 101 6-> 110   101 110
//05326: 5-> 101 3-> 011 2-> 010 6->110  101 011 010 110

//进制转换 2->8
//421 421
//101 110 -> 056
//101 011 010 110 -> 05326

//进制转换 8->10
//056: 5*8^1+6*8^0=46

//进制转换 16->10   /A 10/B 11/C 12/D 13/E 14/F 15/ 
//0x1A: 1*16^1+10*16^0=26

//进制转换 16->2
//		8421 8421
//0x1A: 0001 1010 
//       (1) (A)

//进制转换 2->16
//8421 8421 8421
//0001 0011 1111: 13F

//int main(void) {
//	int a = 0x2c;
//	printf("%d\n", a);
//	printf("%o\n", a);
//	printf("%x\n", a);
//
//}

//源码
//正变负
// 43: 00101011
//-43: 10101011
//反码
// 43: 00101011
//-43: 10101011
//     11010100
//补码
// 43: 00101011
//-43: 11010101

// 43-27 == 43 + -27
// 00101011 43
              //10011011 27
              //11100100 -27
// 11100101 +
//-----------
//(1)00010000
//(1)溢出然后移除

//0000000 -> 0
//1111111 ->-128
//
//char: 8bit  -128---127  -2^(8-1) -- 2^(8-1)-1
//unsigned char: 0---255  0 -- 2^8 -1
//int: -2^(32-1) -- 2^(32-1)-1
//unsigned int: 0 -- 2^(32)-1
//.....

//01111111 127
//00000001 +1
//10000000 -128
//00000001 +1
//10000001 求源码---> 10000001-1 再取反 11111111 -> -127



//volatile int flg;   volatile 就是防止编译器优化代码
//flg = 0;  <----
//....
//flg = 1;
//flg = 0;  没有volatile,中间会被优化掉，去掉
//flg = 1;
//flg = 0;
//....
//flg = 0;  <----


//string  (%s)
//"abc" ---> ['a','b','c','\0']
//printf("abc") ---> abc without '\0'

//int main(void) {
//    char ch = 'a';
//    char str[] = "hello world";
//    char str1[20] = { 'h','e','l','l','o','\0'}; //没'\0', 会有乱码
//    
//    printf("ch = %c\n", ch);
//    printf("str = %s\n", str);
//    printf("str1 = %s\n", str1);

//    printf("%%");  //%百分号转义不能用'\'转义
//    printf("%5s"); //显示5个字符，不足用空格向左填充
//    printf("%-5s"); //显示5个字符，不足用空格向右填充
//    printf("%05s"); //显示5个字符，不足用0向左填充
//}

//putchar (char only)
//int main(void) {
//    putchar(97); //'a' == 97
//    putchar('b');
//    putchar('\n')；//换行
//}


//scanf()
//int main(void) {
//    int a, b; //创建变量空间
//    char c;
//    char str[10];
//
//    scanf_s("%d %d %c", &a, &b, &c); //'&': 表示取出变量地址，描述a的空间
//    printf("a = %d \nb = %d \nc = %c", a, b, c);
//
//    scanf_s("%s", str); //数组名本身表示地址 所以不用取缔值符‘&’
//    printf("%s", str); //如果存储空间(10)不足,hello world you(超过10),照样会输出
//                       //数据能存储到内存中，但不被保护
//
//    return 0;
//}


//getchar()
//int main(void) {
//    char ch;
//    ch = getchar(); //接收用户输入，返回接收到的ASCII码
//
//    printf("ch = %c", ch);  
//    return 0;
//}


//运算符
// + - * / %
//int a=1, b=2;
//c = a + b;
//c = a / b;
//c = a % b;
//c = a * b;
//c = a - b;

//前缀自增/自减
//int i = 0;
//++i; // i = 1
//后缀自增/自减
//int i = 0;
//i++; // i = 0

//赋值运算符
// += -= *= /= %=
// a%=2 --> a=a%2
// a+=2 --> a=a+2

//三目运算符 ?:
//int a = 1, b = 2;
// a > b ? 1 : 0;
// a > b ? 69 : (a < b ? 3 : 5); -->算后边先

//逗号运算符
//int a = 10, b = 20, c = 30;
//int x = (a = 1, b = 2, c = 3);
//x = 3, a = 1, b = 2, c = 3

//隐式类型转换：
//由编译器自动完成。
//由赋值产生的类型转换。 小--》大 没问题。 大 --》 小 有可能发生数据丢失。
//int r = 3;
//float s = 3.14 * r * r;
//int a = 321:	256|128 64 32 16 8 4 2 1
//               1 |0   1  0  0  0 0 0 1
//char ch = a:   # |0   1  0  0  0 0 0 1
//ch = 65

//scanf 4996 错误
//method 1: #define _CRT_SECURE_NO_WARNINGS 
//method 2: #pragma warning(disable:4996)

//dowhile loop和水仙花数  1^3+5^3+3^3 = 153  只对100~999数字
//int main(void) {
//   int num = 100;
//   int a, b, c;
//    do
//    {
//        //个位数 153 -> 3
//        a = num % 10; 
//        //十位数 153 -> 15 -> 5
//        b = num / 10 % 10; 
//        //百位数 153 -> 1
//        c = num / 100;
//        if ((pow(a, 3) + pow(b, 3) + pow(c, 3)) == num) {
//            printf("%d ", num);
//        }
//        num++;
//    } while (num<1000);
//
//}

//for loop
//int main(void) {
//	int sum =0;
//	for (int  i = 1; i <= 100; i++)
//	{
//		sum += i;
//	}
//	printf("%d", sum);  /*sum = 5050*/
//	return 0;
//}  

//infinite for loop
//int i = 0;
//for (;;)
//{
//    printf("%d", i);
//    i++;
//}

//猜数字游戏
//srand(time(NULL)) + #include<stdlib.h> + #include<time.h>
//int n = rand()%100;  /*0~99*/

//#include<stdlib.h> //头文件
//#include<time.h>
//
//int main(void) {
//    srand(time(NULL));//添加一个随机种子
//
//    int num = rand()%100; 
//    int guess;
//
//    while (true)
//    {
//        scanf("%d", &guess);
//        if (guess == num) {
//            printf("correct!!");
//            break;
//        }
//        else if (guess < num) {
//            printf("too small\n");
//        }
//        else {
//            printf("too large\n");
//        }
//    }
//    
//}

//打印电子时钟
//#include<Windows.h>
//int main(void) {
//	//hour
//	for (int i = 0; i < 24; i++)
//	{	//min
//		for (int j = 0; j < 60; j++) {
//			//second
//			for (int k = 0; k < 60; k++)
//			{
//				printf("%02d:%02d:%02d\n", i, j, k); 
//				Sleep(1000);	//from #include<Windows.h>
//				system("cls"); //清屏已覆盖原有数据
//			}
//		}
//
//	}
//}

//99乘法表
//int main(void) {
//    
//    for (size_t i = 1; i <=9 ; i++) //szie_t == unsigned int
//    {
//        for (size_t j = 1; j <= i; j++) {
//            printf("%d*%d=%d ", i, j, i * j);
//        }
//        printf("\n");
//    }
//
//}

//倒叙99乘法表
//int main(void) {
//	for (size_t i = 9; i>=1; i--)
//	{
//		for (size_t j = 1; j <=i ; j++) {
//		
//			printf("%d*%d=%d\t", j, i, i * j);
//
//		}
//		printf("\n");
//	}
//
//}

//数组
//int main(void) {
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //元素地址连续
//    printf("&arr[0] = %p\n", &arr[0]); // []下标 &取arr[0]地址
//    printf("&arr[1] = %x\n", &arr[1]);
//    printf("数组大小: %u\n", sizeof(arr));  //40 4*10
//    printf("数组元素大小: %u\n", sizeof(arr[0]); //4
//    printf("数组元素个数/长度", sizeof(arr) / sizeof(arr[0]));//10
//}

//数组初始化：
//int arr[12] = { 1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 , 6, 8 };
//int arr[10] = { 1, 2 ,4, 6, 76, 8, 9 };  //剩余未初始化的元素，默认 0 值。
//int arr[10] = { 0 }; //初始化一个全为 0 的数组。
//int arr[] = { 1, 2, 4, 6, 8 }; //编译器自动求取元素个数  
//int arr[] = { 0 };  //只有一个元素，值为0
//int arr[10];
//arr[0] = 5;
//arr[1] = 6;
//arr[2] = 7; //其余元素未被初始化，默认为随机数(such as -87877663)。

//数组元素逆序 三杯水法
//int main(void) {
//
//	int arr[] = { 1,6,8,0,4,3,9,2 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (size_t i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	int i = 0;
//	int j = len - 1;
//	int tmp = 0;
//	while (i<j)
//	{	
//		tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = tmp;
//
//		i++;
//		j--;
//	}
//
//	printf("\n");
//
//	for(size_t i = 0; i <len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//}

//冒泡排序
//int main(void) {
//	int arr[] = { 4,2,8,0,5,7,1,3,9 }; // 9 elements 
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	int temp;
//
//		for (size_t i = 0; i <len-1; i++) //排序需要的次数
//		{
//			for (size_t j = 0 ; j < len-1-i; j++) { //每次需要排len-1-i遍 逐层递减 
//													//1st row: sort 8 times from 0 to 7
//				if (arr[j] > arr[j+1]) {			//2nd row: sort 7 times from 0 to 6
//					temp = arr[j];					//....etc
//					arr[j] = arr[j + 1];
//					arr[j + 1] = temp;
//				}
//			}
//		}
//	
//		for (size_t i = 0; i < len; i++)
//		{
//			printf("%d ", arr[i]);
//		}
//}

//2维数组
//int main(void) {
//    int arr[2][3] = { {2,3,4},{4,5,6} }; //2 rows 3 columns
//
//    for (size_t i = 0; i < 2; i++)
//    {
//        for (size_t j = 0; j< 3; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    //数组大小
//    printf("数组大小: %d\n", sizeof(arr)); //24
//    //一行大小
//    printf("一行大小: %d\n", sizeof(arr[0])); //12
//    //数组一个元素大小
//    printf("数组一个元素大小: %d\n", sizeof(arr[0][0])); //4
//    //行数
//    printf("行数: %d\n", sizeof(arr) / sizeof(arr[0])); //2 
//    //列数
//    printf("列数: %d\n", sizeof(arr[0])/sizeof(arr[0][0])); //3
//
//    //地址合一：
//    //printf("%p\n", arr); == printf("%p\n", &arr[0][0]); == printf("%p\n", arr[0]);
//    //数组的首地址 == 数组的首元素地址 == 数组的首行地址。
//
//    //二维数组的初始化：
//    //1）常规初始化：
//    int arr[3][5] = { {2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78} };
//    //2)不完全初始化：
//    int arr[3][5] = { {2, 3}, {2, 67, 4, }, {1, 4, 16, 78} };  //未被初始化的数值为 0
//    int arr[3][5] = { 0 };	//初始化一个 初值全为0的二维数组
//    int arr[3][5] = { 2, 3, 2, 67, 4, 1, 4, 16, 78 };  // 【少见】 系统自动分配行列。
//    //3）不完全指定行列初始化：
//    int arr[][] = { 1, 3, 4, 6, 7 }; // 二维数组定义*必须指定列值。
//    int arr[][2] = { 1, 3, 4, 6, 7 }; // 可以*不指定行值。{{1,3},{4,6},{7,0}}
//    return 0;
//}

//5名学生3门功课
//int main(void) {
//    int scores[5][3];
//
//    int row = sizeof(scores) / sizeof(scores[0]);
//    int col = sizeof(scores[0]) / sizeof(scores[0][0]);
//
//    for (int i = 0; i <row ; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            scanf("%d", &scores[i][j]);
//        }
//    }
//
//    //学生个人成绩
//    for (int i = 0; i < row; i++)
//    {
//        int sum = 0;
//        for (int j = 0; j < col; j++)
//        {   
//            sum += scores[i][j];
//        }
//        printf("第%d个学生成绩: %d", i+1, sum);
//        printf("\n");
//    }
//
//    //第一门功课总成绩
//    for (int i= 0; i< col; i++)
//    {
//        unsigned hw1 = 0;
//        for (int j = 0; j < row; j++)
//        {
//            hw1 += scores[j][i];
//        }
//        printf("第%d门功课总成绩: %d", i+1, hw1);
//        printf("\n");
//    }
//
//    return 0;
//}

//三维数组
//int main(void)
//{
//	int a[3][4][2] = {
//	{	{1,2},
//		{3,4},
//		{5,6},
//		{7,8}  },
//	{   {11,12},
//		{13,14},
//		{15,16},
//		{17,18} },
//	{   {11,12},
//		{13,14},
//		{15,16},
//		{17,18} }
//	};
//	//int a[2][3][5] = { 1,2,3,4,5,6,7,8 }; //系统自动分配
//	//int a[][3][5] = {1,2,3,4,5,6,7,8}; //
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			for (int k = 0; k < 2; k++)
//			{
//				printf("%d ", a[i][j][k]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//
//	}
//
//	return 0;
//}

//字符数组
//int main(void)
//{
//	char str1[5] = { 'h', 'e','l','l','o' }; //printf ->hello麒麟妮妮 会出现乱码
//	char str2[6] = { 'h', 'e','l','l','o', '\0' }; //printf -> hello
//	char str3[] = "hello";
//	//统计字符串中每个字符出现的次数
//	char str[11] = { 0 };
//	// scanf("%s", str); 
//	// a: 97
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%c", &str[i]);
//	}
//	int count[26] = { 0 };
//	
//	for (int i = 0; i < 11; i++)
//	{								
//		int index = str[i] - 'a';   //'h'-'a' = 7
//		count[index]++;				//count[7]=1
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		if (count[i] != 0) {
//			printf("%c:%d\n", i + 'a', count[i]);
//		}
//	}
//	for (int i = 0; i < sizeof(count)/sizeof(count[0]); i++)
//	{
//		printf("%c:%d ",i+'a', count[i]);
//	}
//	return 0;
//}

//获取带有空格的字符串
//int main(void)
//{
//    char str[100];
//    //scanf("%s", str); //helloworld可以 但hello world不行， 遇到空格或\n
//    scanf("%[^\n]", str); //[^\n] ：除\n之外 -> 正则表达式
//    printf("%s", str);
//
//    return 0;
//}


//gets -> get string
//获取一个string，返回string首地址
//char *gets(char *s);
//参数：用来储存string的空间
//返回值： 返回实际获取到的string
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[100];
//    printf("%s", gets_s(str));
//    return 0;
//}

//fgets
//char *fgets(char *s, int size, FILE * stream)
//arg1:用来储存string的空间地址
//arg2:空间大小
//arg3:读取string位置 标准输入:stdin
//返回string
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[10];                      //缓冲区名字
//    printf("%s", fgets(str, sizeof(str), stdin));
//    //会预留\0的空间 hello world -> hello wor
//    //有足够空间会读\n
//    return 0;
//}

//puts
//int puts(const char *s)
//arg: string
//return: positive int for success, negative for fail
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[] = "hellow world";  
//    puts(str);
//    //输出后会自动加\n
//    return 0;
//}

//fputs
//int fputs(const char *s, FILE *stream)
//arg1: string
//arg2: stdout 标准输出，屏幕
//return: positive int for success, negative for fail
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[] = "hellow world";
//    //fputs("hello world\n", stdout);
//    fputs(str,stdout);
//    //输出后 *不会自动加\n
//    return 0;
//}

//strlen()
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//    char str[] = "hello world";
//    printf("%u",sizeof(str)); //12 include \0
//    printf("%u",strlen(str)); //11 exclude \0
//    return 0;
//}

//string
//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//    char str1[] = "hello";
//    char str2[] = "world";
//    char str3[100] = { 0 };
//    int i = 0;
//    while (str1[i]!='\0') // '\0'== 0
//    {
//        str3[i] = str1[i];
//        i++;
//    }
//    int j = 0;
//    while (str2[j] != '\0')
//    {
//        str3[i+j] = str2[j];
//        j++;
//    }
//    //str3[i + j] = '\0'; //当char str3[100]; 未赋值时
//    printf("%s", str3);
//    return 0;
//}


//函数入门
//#include <stdio.h>
//#include <string.h>
//void BubbleSort(int arr[], int len)
//{
//    for (int i = 0; i < len - 1; i++)
//    {
//        for (int j = 0; j < len - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//void print_arr(int arr[], int len) {
//   
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}
//int main(void)
//{
//    int arr[] = { 54,5,16,34,6,9,34,1,7,93 };
//    int len = sizeof(arr) / sizeof(arr[0]);
//    BubbleSort(arr, len);
//    print_arr(arr, len);
//    return 0;
//}

//随机数
//srand(time(NULL))
//#include<stdlib.h> <time.h>
//rand()%100

//形参 实参
//add(int a, int b) //int a 形参
//add(1,3)  //1 实参

//exit()
//结束整个程序

//header file
//#pragma once 防止头文件重复包含  (windows中)
//#include "head.h"

//#ifndef __HEAD_H__ (Linux中)
/*
  #define __HEAD_H__
  函数声明
  #include<>头文件
  #define 宏定义
  类型定义
  ...
*/
//#endif

//指针(地址)==内存单元的编号(一个字节) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

//int main(void)
//{
//	int a = 10; // 4个字节
//	printf("%p", &a);
//	/*
//		----------   编号
//		|00000000|	0133F703	1个字节
//		----------
//		|00000000|	0133F702	1个字节
//		----------
//		|00000000|	0133F701	1个字节
//		----------
//  (a=10)|00001010|  0133F700	1个字节
//		----------
//	*/
//
//	return 0;
//}

//指针定义和使用
//#include "Header.h"
//int main(void)
//{
//	int a = 10;
//	int* p = &a;
//	*p = 250;
//
//	/*
//		----------      ----------
//		|  10    | a    |00xff00a| p
//		----------      ----------
//		 00xff00a	
//	*/
//	printf("%d", a);//250
//	a = 350;
//	printf("%d", *p);//350
//	return 0;
//}

//野指针
//#include "Header.h"
//int main(void)
//{
//	int* p1;  //1)没有一个有效地址空间的指针(没指定地址)
//	*p1 = 1000;
//
//	int* p2 = 10; //2)有指定值，但此值没地址
//	*p2 = 2000;
//
//	return 0;
//}

//空指针
//int* p  = NULL;
//*p, p 所对应的存储空间是一个 无效的访问区域

//万能指针或泛指针
#include "Header.h" //#include files....
int main(void)
{
    int a = 345;
    void* p;   //未指定类型
    p = &a;
    printf("%d", *((int*)p)); //把(p地址)强转成int*类型

    char ch = 'a';
    void* p1;
    p1 = &ch;
    printf("%c", *(char*)p1);

	return 0;
}



