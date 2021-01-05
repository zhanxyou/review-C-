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
//arg2: 文件指针，如果把string输出到屏幕，固定写为stdout
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
// (a=10)|00001010|  0133F700	1个字节
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
//#include "Header.h" //#include files....
//int main(void)
//{
//    int a = 345;
//    void* p;   //未指定类型
//    p = &a;
//    printf("%d", *((int*)p)); //把(p地址)强转成int*类型
//
//    char ch = 'a';
//    void* p1;
//    p1 = &ch;
//    printf("%c", *(char*)p1);
//
//	return 0;
//}

//修饰变量
//#include "Header.h"
//int main(void)
//{
//    /*const int a = 20;
//    int* p= &a;
//    *p = 650;
//    printf("%d", a);*/
//
//    //修饰指针
//
//    //const int *p
//    //int a = 10;
//    //int b = 30;
//    //const int* p = &a;
//    //*p = 500;  //不可以修改*p
//    //p = &b;    //可以修改p
//
//    //int const*p
//    //int a = 10;
//    //int b = 30;
//    //int const *p = &a;
//    //*p = 300;   //不可以修改*p
//    //p = &b;     //可以修改p
//
//    //int* const p
//    //int a = 10;
//    //int b = 30;
//    //int* const p = &a;
//    //*p = 300;   //可以修改*p
//    //p = &b;     //不可以修改p
//
//    //const int* const p
//    //int a = 10;
//    //int b = 30;
//    //const int* const p = &a;
//    //*p = 300;    //不可以修改*p
//    //p = &b;     //不可以修改p
//
//    //总结：const向右修饰，被修饰的部分即为只读

//    //取数组元素：
//    //int arr[] = { 1,3, 5, 7, 8 };
//    //int* p = arr;
//
//    //arr[i] == *(arr + 0) == p[0] == *(p + 0)
//
//    //指针和数组区别：
//
//    //1. 指针是变量。数组名为常量。
//    //2. sizeof(指针) ---> 4字节(windows)/8字节(linux)
//    //sizeof(数组) ---> 数组的实际字节数。
//
//	return 0;
//}

//数据类型对指针的作用
//#include "Header.h"
//int main(void)
//{						//16进制数对应(4位二进制数) 因为 (2^4)
//						//8进制数对应(3位二进制数)	因为 (2^3)
//    int a = 0x12345678; //int 4bytes = 32bit | 4bit/per | '12' = 1 bytes
//	/*	----------                 
//		|   12   |	高	1个字节		
//		----------
//		|   34   |		1个字节
//		----------
//		|   56   |		1个字节
//		----------
//		|   78   |  低	1个字节
//		----------
//	*/
//	// 所有p都指向统一地址&a
//    char* p = &a; //0x00000078  == 1 bytes
//    short* p = &a;//0x00005678	== 2 bytes
//    int* p = &a;  //0x12345678  == 4 bytes
//	//作用：决定了指针存储的地址开始，向后读取的字节数 (与指针本身存储空间无关)
//	//short*p p-->0x00ff01 p+1 --> 0x00ff03 (short 2bytes)
//
//	//p++,p+1,p+=1 的不同 p = 0xff01
//	//p++ == p+=1 --> p 变量地址 变了 0xff02
//	//p+1 --> p 变量地址没变 0xff01
//
//	//****************数组名取地址*********************
//	//int a[10] = {1,2,3,4,5,6,7,8,9,0};
//	// a --> 0xff00
//	// &a[0] --> 0xff00
//	// a+1 --> 0xff04
//	// &a --> 0xff00
//	//int*p; p+1
//	// &a+1 --> &a(整个数组) + 1(sizeof(int)*10: 一整个数组大小)
//
//	//指针加减指针
//	//p + q error!!
//	//p - q 偏移的元素个数 
//
//
//	return 0;
//}

////指针数组1
//#include "Header.h"
//int main(void)
//{
//    int a = 10;
//    int b = 20;
//    int c = 30;
//
//    int* p1 = &a;
//    int* p2 = &b;
//    int* p3 = &c;
//
//    int* arr[] = { p1,p2,p3 };
//    printf("%d", *arr[0]);  //*(*(arr+0)) == *(*arr) == **arr
//    printf("%d", **arr);    //二级指针
//
//	return 0;
//}
//
////指针数组2
//#include "Header.h"
//int main(void)
//{
//    int a[] = {10};
//    int b[] = {20};
//    int c[] = {30};
//
//    int* arr[] = { a,b,c };
//    //arr[0][0] == *(*(arr+0)+0) //二维数组也是2级指针
//
//    printf("%d", *arr[0]);  //*(*(arr+0)) == *(*arr) == **arr
//    printf("%d", **arr);    //二级指针
//
//    return 0;
//}

////多级指针
//#include "Header.h"
//int main(void)
//{
//    int a = 10;
//    int* p = &a;    //1级指针是 变量地址
//    int** pp = &p;  //2级指针是 1级指针的地址
//    int*** ppp = &pp; //3级指针是 2级指针的地址
//    //.....etc
//    /*
//        p = 0xff00 = &a
//        *p = 10 = a
//         
//        pp = &p 
//        *pp = p = 0xff00 = &a
//        **pp = 10 = a
//        
//        ppp = &pp
//        *ppp = pp = &p
//        **ppp = *pp = p = 0xff00 = &a
//        ***ppp = **pp = *p = 10 = a
//         
//        *********************************
//        int a[] = {10};
//        int b[] = {20};
//        int c[] = {30};
//
//        int * arr[] = {a,b,c}
//        //arr[0] = a 
//        //arr[0][0] = 10
//        *********************************
//        int a = 10;
//        int b = 20;
//        int c = 30;
//         
//        int *p1 = &a;
//        int *p2 = &b;
//        int *p3 = &c;
//
//        int * arr[] = {p1,p2,p3};
//        arr[0][0] = *(*(arr+0)+0) = *(*arr)
//        ***********************************
//
//     */
//    return 0;
//}

//传值和传址
//#include "Header.h"
//int swap(int a, int b) {
//    int temp = 0;
//    temp = a;
//    a = b; 
//    b = temp;
//    return 0;
//
//}
//int swap2(int* a, int* b) {
//    int temp = 0;
//    temp = *a;
//    *a = *b;
//    *b = temp;
//    return 0;
//}
//
//int main(void)
//{
//    int m = 1;
//    int n = 2;
//    //-----------传值------------//
//    printf("before: %d and %d", m, n);
//    swap(m, n);         //赋值给a,b: a = m, b =n, 但m,n的没变
//    printf("after: %d and %d", m, n);  
//    //-----------传址-----------//
//    printf("before: %d and %d", m, n);
//    swap(&m, &n);       //m,n内部地址变了，值 自然也就变了
//    printf("after: %d and %d", m, n);
//	return 0;
//}

//数组做函数参数
//void BubbleSort(int arr[10]) == void BubbleSort(int arr[]) == void BubbleSort(int* arr)
//sizeof(arr) == 4 because 指针大小为4

//#include "Header.h"
//void BubbleSort(int arr[]) { //int arr[] == int *arr;
//    printf("%d", sizeof(arr)); //4 
//}
//
//int main(void)
//{
//    int arr[] = { 1,2,3,4 };
//    printf("%d", sizeof(arr)); //16, 不同于 void BubbleSort(int arr[]); sizeof(arr) = 4
//	return 0;
//}  //传递不再是整个数组，而是数组的首地址（一个指针）。


//指针做函数返回值
//#include "Header.h"
//int m = 100; //global variable 全局变量
//int* test(int a, int b) {
//    
//    int p = 1234; //局部变量
//    //return &p; 无法返回，函数执行完后，所属栈帧会被释放。
//    return &m;
//}
//
//int main(void)
//{
//    int* p = NULL;
//    p = test(10, 20);
//    printf("%d", *p);
//	return 0;
//}

//指针和string
//char str1[] = { 'h', 'i', '\0' };	//变量，可读可写
//char str2[] = "hi";				//变量，可读可写
//char* str3 = "hi";				//常量，只读
//str3 变量中，存储的是字符串常量“hi”中首个字符 ‘h’ 的地址值。
//str3[1] = 'H';	// 错误！！
//char* str4 = { 'h', 'i', '\0' };  // 错误！！！

//string 比较
//#include "Header.h"
//
//int stringCmp(char* str1, char* str2) {
//    int i = 0;
//
//    while (str1[i] == str2[i]) {  //*(str1+i) == *(str2+i)
//        if (str1[i] == '\0') {
//            return 0;
//        }
//        i++;
//    }
//    return str1[i] > str2[i] ? 1 : -1;
//
//}
//
//int stringCmp2(char* str1, char* str2) {
//
//    while (*str1 == *str2) {
//        if (*str1 == '\0') {
//            return 0;
//        }
//        str1++;
//        str2++;
//    }
//    return *str1 > *str2 ? 1 : -1;
//
//}
//int main(void)
//{
//    char str1[] = "helloz";
//    char str2[] = "hellow";
//    // int ret = stringCmp(str1, str2);  //不比较长度, 最后比较 'z','w', 'z'>'w' 
//    int ret1 = stringCmp2(str1, str2);  //指针比较
//
//    if (ret1 == 0) {
//        printf("same");
//    }else if(ret1 == 1) {
//        printf("str1 > str2");
//    }
//    else if (ret1 == -1) {
//        printf("str 1 < str2");
//    }
//    else {
//        printf("error");
//    }
//	return 0;
//}


//string copy
//#include "Header.h"
//void myStringCopy(char* src, char* dest) { //数组版本
//    int i = 0;
//    while (src[i]!=0) 
//    {
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0';
//
//}
//void myStringCopy2(char* src, char* dest) { //指针版本
//  
//    while (*src!=0) 
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = '\0';
//
//}
//int main(void)
//{
//    char* src = "helllo";
//    char dest[100] = { 0 };
//
//    myStringCopy2(src, dest);
//    printf("%s", dest);
//	return 0;
//}

//在字符串中查找字符 出现的位置
#include "Header.h"
//char* findChar(char* str, char a) {
//
//    while (*str)
//    {
//        if (*str == a) {
//            return str;
//        }
//        str++;
//    }
//    
//    return NULL;
//
//}
//
//char* findChar2(char* str, char a) {
//    int i = 0;
//    while (str[i])
//    {
//        if (str[i] == a) {
//            
//            return &str[i];
//        }
//        i++;
//    }
//    return NULL;
//
//}
//int main(void)
//{
//    char* src = "hello world";
//    char ch = ' ';
//    char* find = NULL;
//
//    find = findChar2(src, ch);
//    printf("%p", find);
//
//
//	return 0;
//}

//string 去空格
//#include "Header.h"
//void str_no_space(char* src, char* dest) {
//    int i = 0;
//    int j = 0;
//    while (src[i]) {
//        
//        if (src[i] != ' ') {
//            dest[j] = src[i];
//            j++;
//        }
//        i++;
//    }
//    dest[j] = '\0';
//
//}
//void str_no_space2(char* src, char* dest) {
//
//    while (*src) {
//
//        if (*src!= ' ') {
//            *dest = *src;
//            dest++;
//        }
//        src++;
//    }
//    *dest = '\0';
//
//}
//
//int main(void)
//{
//    char src[] = "ni chou sha chou ni za di";
//    char dest[100] = {0};
//    str_no_space2(src, dest);
//    printf("%s", dest);
//	return 0;
//}

//strstr : 在 str中，找substr出现的位置
//char* strstr(char*str,char*substr)
//
//#include "Header.h"
//int main(void)
//{
//    char* ret = strstr("hellollollo", "llo");
//    printf("%s", ret); // llollollo 子串在原串中的位置(地址值), 没有的话返回NULL
//	return 0;
//}

//strstr 子串(substr) 出现的次数
//#include "Header.h"
//int str_times(char* str, char* substr) {
//    int count = 0;
//    char* p = strstr(str, substr); //lloabcllozxyllo
//    while (p) { // ==> p!= NULL
//        count++;                //p += p + sizeof(substr) 有‘\0’ error!!
//        p += strlen(substr);   // p = p + strlen(substr) --> abcllozxyllo
//        p = strstr(p, substr);  //return: llozxyllo
//    }
//    return count;
//}
//int main(void)
//{
//    char str[] = "helloabcllozxyllo";
//    char substr[] = "llo";
//    int ret = str_times(str, substr);
//
//    printf("%d times", ret);
//	return 0;
//}


//求非空字符串元素个数：
//#include "Header.h"
//int count_chars(char* str) {
//    int count = 0;
//    if (!str || strlen(str)==1) {
//        return count;
//    }
//
//    while (*str!=0) {
//        if (*str != ' ') {
//            count++;
//        }
//        str++;
//    }
//    return count;
//}
//int main(void)
//{
//    char* str = "  abcd btb   ";
//    //char* str = " ";
//    //char* str = NULL;
//    int num = count_chars(str);
//    printf("%d", num);
//	return 0;
//}


//字符串逆置： str_inverse
//char* str_inverse(char* str,char* temp) {
//    int i = 0;
//    str += (strlen(str)-1);
//    while (*str) {
//        *(temp+i) = *str;
//
//        str--;
//        i++;
//    }
//
//    return temp;
//
//}
//int inverse(char* str) {  数组版本
//    if (!str)
//        return -1;
//
//    //char* p = str;
//    int start = 0;
//    int end = strlen(str) - 1;
//    char tmp;
//    while (start < end) {
//       tmp = str[start];
//       str[start] = str[end];
//       str[end] = tmp;
//       start++;
//       end--;
//    }
//
//    return 0;
//}
//int inverse2(char* str) {   //指针版本
//    if (!str)
//        return -1;
//
//    //char* p = str;
//    char*start = str;
//    char*end =str+strlen(str) - 1;
//    char tmp;
//    while (start < end) {
//       tmp = *start;
//       *start = *end;
//       *end= tmp;
//       start++;
//       end--;
//    }
//
//    return 0;
//}
//
//#include "Header.h"
//int main(void)
//{
//    char str[] = "hello";
//    //char temp[100] = { 0 };
//    //char* str2 = str_inverse(str,temp);
//    int ret = inverse(str);
//    printf("%s", str);
//
//	return 0;
//}

//判断字符串是回文：  level levvel  正反读一样
//#include "Header.h"
//int is_palindrome(char* str) {
//    char* tmp = str;
//    int begin = 0;    //char*start = str;
//    int end = strlen(tmp)-1;  //char*end = str+ strlen(str)-1;
//
//    while (begin < end) {
//       if (tmp[begin] != tmp[end]) {  //*start != *end
//                return -1;
//       }
//            begin++;
//            end--;
//    }
//    return 1;
//}
//
//int main(void)
//{
//    char str[] = "levvel";
//    int ret = is_palindrome(str);
//    printf("%d", ret);
//	return 0;
//}


//字符串处理函数 #include<string.h>
//strcopy 和  strncpy
//#include "Header.h"
//int main(void)
//{
//    //char src[] = "hello";
//    //char dest[6];//需要足够大空间
//    //strcpy(dest, src);  //char* strcpy(char* dest, const char* src)
//    //printf("%s", dest);
//
//
//    char src[] = "hello world";
//    char dest[10] = {0};
//
//    char* p = strncpy(dest, src, 10); 
//    //char* strncpy(char* dest, const char* src, size_t n)
//    //n(与dest空间对应)> src: 只拷贝 src 大小
//    //n(与dest空间对应)< src: 只拷贝 n 字节大小， 不添加‘\0’, 会有乱码
//    printf("%s", p);
//
//	return 0;
//}


//strcat
//#include "Header.h"
//int main(void)
//{
//   /* char src[] = "world";
//    char dest[] = "hello";  //dest 空间不够会出错，但结果没错
//    char* p = strcat(dest, src);
//    printf("%s\n", p);
//    printf("%s\n", dest);*/
//    //char* strcat(char* dest, const char* src)
//
//    char src[] = "world";
//    char dest[] = "hello";  //dest 需要空间足够大 dest[11]不会报错
//    char* p = strncat(dest, src, 3);
//    printf("%s\n", p);
//    printf("%s\n", dest);
//    //char* strncat(char* dest, const char* src, size_t n)
//	return 0;
//}

//strcmp and strncmp
//#include "Header.h"
//int main(void)
//{
//    char str1[] = "hello like";
//    char str2[] = "hello mike";

//    //int strcmp(const char* s1, const char*s2);
//    //int num = strcmp(str1, str2); //-1 l<m
//    //printf("%d", num);
//
//    //int strncmp(const char* s1, const char*s2, size_t n);
//    int num2 = strncmp(str1, str2, 5);//0  o=o
//    printf("%d", num2);
//	return 0;
//}

//sprintf == printf --> string 
//#include "Header.h"
//int main(void)
//{
//	char dst[100] = { 0 };
//	int a = 10;
//	char src[] = "hello world";
//	printf("a = %d, src = %s", a, src);
//	printf("\n");
//					//将输出的'"格式化string" 存到缓冲区(buffer) dst
//	int len = sprintf(dst, "a = %d, src = %s", a, src);
//	printf("dst = \"%s\"\n", dst);
//	printf("len = %d\n", len); //实际格式化字符个数
//	return 0;
//}

//sscanf == string --> scanf
//#include "Header.h"
//int main(void)
//{
//	//char src[] = "a=10, b=20";
//	char src1[] = "10+20=30";
//	int a;
//	int b;								//原来scanf需要屏幕输入
//	int c;								//现在直接从src解析写入&a,&b中
//	//sscanf(src, "a=%d, b=%d", &a, &b);
//	sscanf(src1, "%d+%d=%d", &a, &b, &c);
//	printf("a:%d, b:%d, c:%d\n", a, b, c);
//	return 0;
//}

//strchr 找在string中字符，子串的地址  左-->右
//#include "Header.h"
//int main(void)
//{
//	char src[] = "ddda123abcd";
//	char* p = strchr(src, 'a');
//	printf("p = %s\n", p); //a123abcd
//	return 0;
//}
//strrchr 找在string中字符，子串的地址 右-->左
//#include "Header.h"
//int main(void)
//{
//	char src[] = "ddda123abcd";
//	char* p = strrchr(src, 'a');
//	printf("p = %s\n", p); //a123abcd
//	return 0;
//}

//strstr 在str中找子串substring
//#include "Header.h"
//int main(void)
//{
//	char str[] = "hehehehabc123hohoh";
//	printf("%s", strstr(str, "abc"));  //abc123hohoh
//
//	return 0;
//}


//strtok 字符串分割
//return: 字符串拆分后的首地址。分割符用‘\0’替换  www.baidu.com --> www\0baidu.com
//#include "Header.h"
//int main(void)
//{
//	//char *a = "adc*fvcv.ebcy*hghbdfg$casdert";  常量不可用 必须可读可写
//	char a[100] = "adc*fvcv.ebcy*hghbdfg$casdert";
//	char* s = strtok(a, ".*$");//将"*"分割的子串取出     //第一次拆分，参1：原串
//	//printf("%s\n", s);	//adc	// %s 遇到‘\0’就会停止
//	while (s != NULL)	
//	{
//		printf("%s\n", s);
//		s = strtok(NULL, ".*$");  //后面再拆分，参1：NULL(0)，原因是 strtok内部有静态变量 
//								//在第一次拆分后，保存着“剩下的字符串”的地址
//		//printf("%s\n", s);
//	}
//	return 0;
//}

//atoi, atof, atol
//#include "Header.h"
//int main(void)
//{
//	char str1[] = "          -10";  //错误使用--》 123zxy--> 123  abc345-->0
//	int num1 = atoi(str1);    //int atoi(const char* p)
//	printf("num1 = %d\n", num1);
//
//	char str2[] = "0.123";
//	double num2 = atof(str2);
//	printf("num2 = %.2lf\n", num2);
//
//	char str3[] = "123L";
//	long num3 = atol(str3);
//	printf("num3 = %ld\n", num3);
//
//
//	return 0;
//}


//static 全局变量
//#include "Header.h"   //***********************注意读这*********************/
//extern int a;     //声明变量，如果其他.c文件有 (global) int a=10, 则可在这.c文件输出。
//                  //如果是 static int a=10, 则被限制在其.c文件中。 没法在这里输出
//int main(void)
//{
//    printf("%d", a);
//	return 0;
//}


//static 局部变量   
//#include "Header.h"
//void foo() {
//    int b = 10;
//    printf("%d\n", b++);  
//}
//void foo2() {
//    static int b2 = 20;     //只定义一次。相当于在“全局位置”定义一次。。多用于当计数器
//    printf("%d\n", b2++);
//}
//int main(void)
//{
//    for (size_t i = 0; i < 10; i++)
//    {
//        foo();   //b=10,b=10,b=10.....因为 每次调用 函数会重新声明定义b。
//    }
//
//    for (size_t i = 0; i < 10; i++)
//    {
//        foo2();   //b=10,b=11,b=12....
//    }
//
//	return 0;
//}


//static函数 = static + 函数原型 + 函数体
//只能在本文件内部使用
//void foo(void);     //static void foo(void) 在str_func.c文件
//
//#include "Header.h"
//int main(void)
//{
//    foo();
//	return 0;
//}

//内存空间window
//代码段： .text段。程序源代码二进制
//数据段： 只读数据段 .rodata段。初始化数据段.data段。 初始化数据段.bss段
//stack： 栈。在其之上开辟 栈帧。 windows: 1M----10M  linux: 8M---16M
//heap： 堆。给用户定义数据提供空间。 约1.3G+
/*
    -----------------------
    |  .text   |  数据段   |      .data段:初始化为非0的全局变量和静态变量
    |  (binary)|   ------------> .bss段:初始化为0，未初始化的全局变量和静态变量
    |          |          |             程序加载执行前，会将该段整体赋值为0
    ----------------------       .rodata:只读数据段,常量
    |   stack  |   heap   |
    |     |    |     ----------> 空间足够大
    |     |    |          |      
    ------|----------------
          |
          V
    比较小，系统自动管理，
    自动分配，自动释放。
    存储特性：FILO
*/


//内存空间linux
/*	    ---------- 4G
		|        |	---> 内核空间
		---------- 3G
		| stack ||	
        |       V|
		----------
        |   C    |  ---> 标准库加载的位置
        ----------
        |       ^|       用户空间
        |  heap ||
        ----------  --------
        | .bss   |
        ----------  读写权限
        | .data  |
        ----------  --------
        |.rodata |
        ----------  只读
		| .text  |  
		---------- 0
*/


//生命周期：
//
//局部变量：从变量定义开始，函数调用完成。-- - 函数内部。
//全局变量：程序启动开始，程序终止结束。-- - 程序执行期间。
//static局部变量：程序启动开始，程序终止结束。-- - 程序执行期间。
//static全局变量：程序启动开始，程序终止结束。-- - 程序执行期间。
//全局函数：程序启动开始，程序终止结束。-- - 程序执行期间。
//static函数：程序启动开始，程序终止结束。-- - 程序执行期间。

//数组 默认在 栈stack上
//现在需要申请 heap 空间，则需要malloc and free
//void* malloc(size_t size); //申请size大小的空间，返回内存空间首地址
                             //通常用来当数组用
//void free(void* p); //释放放申请的空间
           //mallocd返回的地址值

//#include "Header.h"
//int main(void)
//{
//    //int arr[1000000] //太大 无法执行  1m --- 10m
//    //int arr[10] 空间大小 4 bytes + 10 = 40  ：这是在(栈)stack上
//
//    int * p = (int*)malloc(sizeof(int) * 10); // 40   ：这是在(堆)heap上
//    //int* p = malloc(sizeof(int)*10) 隐式转换 void*-->int*
//    if (p == NULL) {
//        printf("error");
//        return -1;
//    }
//*******************************************//
//    char*tmp =p;
//*******************************************//
//    //写数据到malloc的空间
//    for (size_t i = 0; i < 10; i++)
//    {
//        p[i] = i + 10;
//    }
//
//    //读出malloc空间的数据
//    for (size_t i = 0; i < 10; i++)
//    {
//        printf("%d", *(p+i));
//    }

//    //p++; 空间地址变了，则无法释放，error 

//------------------------------------------------------//    
//    for(size_t i = 0; i < 10; i++)
//    {
//          printf("%d", *p);
//          p++; //会导致内存地址变化, 则需要一个临时变量 char*tmp= p; 
//    }
//    for(size_t i = 0; i < 10; i++)
//    {
//          printf("%d", *tmp);
//          tmp++; 
//    }
//    free(tmp)
//------------------------------------------------------//

//    //释放申请内存
//    free(p);  //free 完后不会立即失效，但数据变了。p不为空
//    p=NULL;
//    return 0;
//}


//int* p = malloc(200);
//p = realloc(p, 400); //在p基础上， 将内存扩展到400个字节
//p = realloc(p, 200);//在p基础上， 将内存缩小到200个字节
//int* p1 = realloc(NULL, 100); //参1：NULL。作用跟malloc一样


//2级指针heap空间
#include "Header.h"
//int main01(void)
//{                                                                       //10个 4 bytes (int*)
//    int** p = malloc(sizeof(int*) * 3);  //int **p  = int* p[10] --> [int*, int*, int*, ...]
//    /*
//    --------------------------------------
//    |   int*   |    int*    |  int*      |
//    |    |     |      |     |    |       |
//    -----|------------|----------|--------
//         |            |          |
//         V            V          V
//    p[0]----    p[1]----    p[2]----
//        |  |        |  |        |  |
//        ----        ----        ----
//        |  |        |  |        |  |
//        ----        ----        ----
//p[0][2] |5 |        |  |        |  |
//        ----        ----        ----
//        |  |        |  |        |  |
//        ----        ----        ----
//        |  |        |  |        |  |
//        ----        ----        ----
//    */
//    for (size_t i = 0; i < 3; i++)
//    {
//        p[i] = malloc(sizeof(int) * 5);
//    }
//
//    //写
//    for (size_t i = 0; i < 3; i++)
//    {
//        for (size_t j = 0; j < 5; j++)
//        {
//            p[i][j] = i + j;
//        }
//    }
//    //读
//    for (size_t i = 0; i < 3; i++)
//    {
//        for (size_t j = 0; j < 5; j++)
//        {
//            printf("%d ", *(*(p+i)+j) ); //p[i][j]
//        }
//        printf("\n");
//    }
//    //释放内层空间，再释放外层空间
//    for (size_t i = 0; i < 3; i++)
//    {
//            free(*(p + i)); //p[i]
//            p[i] = NULL;
//    }
//   
//    //释放外层空间
//    free(p);
//    p = NULL;
//
//    return 0;
//}

//返回栈区地址
//#include <stdio.h>
//int* fun()
//{
//    int a = 10;
//    return &a;//函数调用完毕，a释放
//}
//
//int main(int argc, char* argv[])
//{
//    int* p = NULL;
//    p = fun();
//    *p = 100; //操作野指针指向的内存,err
//
//    return 0;
//}



//返回data区地址
//#include <stdio.h>
//
//int* fun()
//{
//    static int a = 10;
//    return &a; //函数调用完毕，a不释放
//}
//
//int main(int argc, char* argv[])
//{
//    int* p = NULL;
//    p = fun();
//    *p = 100; //ok
//    printf("*p = %d\n", *p);
//
//    return 0;
//}

//值传递1
//#include <stdio.h>
//#include <stdlib.h>
//
//void fun(int* tmp)
//{
//    tmp = (int*)malloc(sizeof(int));
//    *tmp = 100;
//}
//
//int main(int argc, char* argv[])
//{
//    int* p = NULL;
//    fun(p); //值传递，形参修改不会影响实参
//    printf("*p = %d\n", *p);//err，操作空指针指向的内存
//
//    return 0;
//}


//值传递2
//#include <stdio.h>
//#include <stdlib.h>
//
//void fun(int* tmp)
//{
//    *tmp = 100;
//}
//
//int main(int argc, char* argv[])
//{
//    int* p = NULL;
//    p = (int*)malloc(sizeof(int));
//
//    fun(p); //值传递
//    printf("*p = %d\n", *p); //ok，*p为100
//
//    return 0;
//}

//memset
//#include "Header.h"
//int main(void)
//{
//    int a[10];
//
//    //memset(a, 0, sizeof(a));
//    memset(a, 97, sizeof(a));  //a数组 ‘a’ 4*10
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%c\n", a[i]);
//    }
//    return 0;
//}

//menmcpy()
//#include "Header.h"
//int main(void)
//{
//    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int b[10];
//
//    memcpy(b, a, sizeof(a));  //dest, src, 4*10
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d, ", b[i]);
//
//    return 0;
//}

//memmove == memcpy 不过执行效率比mencpy低

//int memcmp(const void *s1, const void *s2, size_t n);
//比较s1和s2所指向内存区域的前n个字节
#include "Header.h"
//int main(void)
//{
//    int a[10] = { 1, 2, 11, 4, 5, 6, 7, 8, 9, 10};
//    int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//    int flag = memcmp(a, b, sizeof(a));  // =: 0, >: 1, <: -1
//    int flag2 = memcmp(a, b, 8); // 3*int 前12个字节
//    printf("flag = %d\n", flag);
//    printf("flag2 = %d\n", flag2);
//    return 0;
//}

//结构体
//struct Student
//{
//    char name[20];
//    int age;
//};
//#include "Header.h"
//int main00(void)
//{
//    struct Student st;
//    strcpy(st.name, "zhangsan");
//    st.age = 18;
//    struct Student st1 = {0};
//    struct Student st2 = {"lisi"};
//    struct Student st3 = { "wangwu", 40 };
//    struct Student st4 = {.name = "liu", .age = 19};
//
//    return 0;
//}

//结构体对齐说明
//struct A {
//    int a;
//    int b;   
//};   //struct A a; sizeof(a) = 8 bytes
//
//struct A {
//    char a;     //1 空3 == 1
//    int b;      //4     == 4 以int对齐 
//};   //struct A a; sizeof(a) = 8 bytes
//
//struct A {
//    char a;
//    short b;
//    char d;
//    int c;
//};   //sizeof(a) = 12 bytes
//
//struct A {
//    char a;
//    char d;
//    short b;
//    int c;
//};   //sizeof(a) = 8 bytes
//struct A {
//    char a;
//    char d;
//};   //sizeof(A) = 1 bytes ...因为类型相同
//------------------------------------//
//struct A {
//    char a;
//    //缺失的1个字节
//    short b;
//    int c;
//    short d;
//    char e;
//};   //sizeof(a) = 12 bytes
////可以通过指针变相访问，补足
//#include "Header.h"
//int main(void)
//{
//    struct A aa = { 0 };
//  /*  char* s =(char*)&a;
//    s[1] = 10;*/
//    printf("%p", &aa); 
//    return 0;
//}
//-------------------------------------//

//struct A {
//    unsigned char a : 2; //a只有2个bit大小 
//    unsigned char b : 4; //b只有4个bit大小
//    char c : 4;
//};
//
//#include "Header.h"
//int main(void)
//{
//    struct A a;
//    a.a = 5;
//    printf("%x", a.a); //1 --> _01  2bit够不到101
//    a.b = 9;
//    printf("%x", a.b); //9 --> 1001  4bit刚刚好
//    a.c = 13;
//    printf("%d", a.c); //-3 --> 1101  第一位是‘-’符号位，因为c是signed char
//                                       //求原数 --> 1101取反 -->1010
//                                        //--> +1 --> 1011 --> -3
//    return 0;                         
//}


//struct Student {
//    char name[64];   <---------------------可读可写
//    int age;
//    double salary;
//}stu3 = {"trump1", 100, 3333.3};
//
//#include "Header.h"
//int main(void)
//{
//    strcpy(stu3.name, "obama");
//    printf("%s", stu3.name);
//    return 0;
//}


#include "Header.h"
//struct Student {
//    char* name;    <----------------------只读
//    int age;
//    double salary;
//}stu1[3] = { {"trump1", 100, 3333.3} ,{"trump2", 10, 333.3},{"trump3", 1, 33.3} };
//int main(void)
//{
//    /*struct Student a;
//    struct Student b;
//    struct Student c;
//
//    struct Student* stu2[3] = {&a,&b,&c};
//
//    stu2[0]->name = malloc(sizeof(char) * 64);
//    if (stu2[0]->name == NULL)
//        return;
//    strcpy(stu2[0]->name, "jedi");
//
//    printf("%s\n", stu2[0]->name);
//
//    free(stu2[0]->name);
//    stu2[0]->name = NULL;*/
//    //--------------------------------------------------------
//    //int len = sizeof(stu1) / sizeof(stu1[0]);
//    ////printf("%d",len);
//
//    //stu1[0].name = malloc(sizeof(char) * 64);
//    //strcpy(stu1[0].name, "jedi");
//
//   
//    //for (int i = 0; i < len; i++)
//    //{
//    //    printf("%s,%d,%.2lf\n", stu1[i].name, stu1[i].age, stu1[i].salary);
//    //}
//
//    //free(stu1[0].name);
//    //stu1[0].name = NULL;
//    //--------------------------------------------------------
//   /* struct Student stu = {NULL, 20, 9999.9};
//    stu.name = (char*)malloc(sizeof(char) * 64);
//    if (stu.name == NULL) {
//        return;
//    }
//    strcpy(stu.name, "obama");
//    printf("%s,%d,%.2lf", stu.name, stu.age, stu.salary);
//    if (stu.name != NULL) {
//        free(stu.name);
//        stu.name = NULL;
//    }*/
//
//    return 0;
//}


//结构体嵌套
//struct Weapon{
//    int dmg;
//    int defense;
//};
//struct Hero {
//    int dmg;
//    int hp;
//    int mp;
//    struct Weapon dragon;
//
//    struct { //匿名结构体
//        int bag;
//        int accessories;
//    }bag;
//};


//结构体指针使用
//struct Person {
//    char* name;
//    int age;
//    int salary;
//}p1 = { NULL, 10 ,9999 }, * p2 = NULL; //p2 结构体指针(4 bytes)
//#include "Header.h"
//int main(void)
//{
// //------------------------------1----------------------------//
//   /* p2 = &p1;
//    p2->name = "jefi";
//    p2->age = 10;
//    p2->salary = 999;
//    printf("%s %d %d", p2->name, p2->age, p2->salary);*/
// //-------------------------------2--------------------------//
//  /*  p2 = malloc(sizeof(struct Person));
//    p2->name = malloc(sizeof(char) * 64); 
//    strcpy(p2->name, "jedi");
//    p2->age = 10;
//    p2->salary = 999;
//    printf("%s %d %d", p2->name, p2->age, p2->salary);
//    free(p2->name);
//    p2->name = NULL;*/
//    return 0;
//}


//结构体作为参数
//struct Person {
//    char name[64];
//    int age;
//};
//void print_person(struct Person p) {
//    printf("%s %d", p.name, p.age);
//}
////地址（指针）传递 --可修改变量
//void print_person_by_pointer(struct Person* p){
//    printf("%s %d", p->name, p->age);
//}
////地址（指针）传递 --不可修改变量
//void print_person_by_pointer2(const struct Person* p) {
//    printf("%s %d", p->name, p->age);
//}
//
//void test01() {
//    struct Person person = { "obama", 33 };
//    //person 和 p 没有任何关系， p修改不会导致person改变
//    //将结构体68 字节数据拷贝给 p变量
//    print_person(person);
//    //传递效率不高
//    //函数无法修改外部变量
//    print_person_by_pointer(&person);
//}
//void test02() {
//    //结构体指针
//    struct Person* p_person = NULL;
//    //结构体变量
//    struct Person person = { "obama", 33 };
//   //指针变量(栈区)  普通变量(栈区)
//        p_person = &person;
//    //指针可以指向 栈变量，堆变量，字符串常量
//    //栈区 不需要free
//}
//void create_person(struct Person**p) { //**p = p_person //*p = &p_person
//    struct Person* person = malloc(sizeof(struct Person)); //*person = [] //person = &[]
//    strcpy(person->name, "obama");
//    person->age = 100;
//    *p = person; //*p = &p_person = person = &[]
//
//}
//
//void test03() {
//    struct Person* p_person = NULL;  //*person = null //person = &null
//    create_person(&p_person);     
//    printf("%s %d", p_person->name, p_person->age);
//}
//#include "Header.h"
//int main(void)
//{
//    test03();
//    return 0;
//}


//结构体数组作参数
//struct Person {
//    char name[64];
//    int age;
//};
//void print_person_array(struct Person ps[], int len) { //*ps
//    for (int i = 0; i < len; i++)
//    {
//        printf("%s %d\n", ps[i].name, ps[i].age);
//    }
//}
//
//void test() {
//    //定义 结构体数组
//    struct Person persons[] = {
//        {"obama",45},
//        {"trump",70},
//        {"polly",65}
//    };
//    print_person_array(persons, 3);
//}
//
//#include "Header.h"
////char** p; sizeof 4
////char* p[3]; sizeof 12
//int main(int argc, char*argv[]) //main函数的参数 是否能够省略 取决于编译器
//{
//    //printf("%d\n", argc);
//    //for (int i = 0; i < argc; i++)
//    //{
//    //    printf("%s\n", argv[i]); // argv[i] 是 char*类型 char*类型是指向string
//    //}
//    test();
//
//    return 0;
//}


//union联合体
//union MyUnion
//{
//    int a;     //union 的数据成员共享内存
//    char d;  // a,d 地址一样的。如果都赋值，则d可能覆盖掉a
//};
//
//void test01() {
//    printf("Union size is: %d", sizeof(union MyUnion)); //4 以最大为准
//    union MyUnion n;
//    printf("%d %d\n", &n.a, &n.d);//a,b地址相同
//
//    n.d = 97;
//    printf("%d\n", n.d); //97
//    n.a = INT_MAX;
//    printf("%d\n", n.d); //-1
//
//}
//void test02() {
//    union MyUnion n1 = {100}; //初始化，只写一个值的话==默认给第一个成员赋值
//    printf("n1.a = %d", n1.a);
//
//    //C99的语法, 给指定成员初始化
//    union MyUnion n2 = { .d = 97};
//    printf("n2.d = %d", n2.d);
//}
////int 4 bytes, 分别打印4个字节的值
//union MyNumber
//{
//    unsigned int number;
//    char byte[4];
//};
//void test03() {
//    union MyNumber number = { UINT_MAX };
//    //4 字节
//    //11111111 11111111 11111111 11111111
//    //10000000 10000000 10000000 10000000
//    //+1
//    //10000001 10000001 10000001 10000001
//    // -1         -1       -1       -1
//    //将数据通过字符数组的形式访问
//    printf("字节数值：%d 字节地址： %d", number.byte[0], &number.byte[0]);
//    printf("字节数值：%d 字节地址： %d", number.byte[1], &number.byte[1]);
//    printf("字节数值：%d 字节地址： %d", number.byte[2], &number.byte[2]);
//    printf("字节数值：%d 字节地址： %d", number.byte[3], &number.byte[3]);
//
//}
//#include "Header.h"
//int main(void)
//{
//    test01();
//    return 0;
//}


//typedef
//typedef int my_int_type;
//typedef double my_double_type;
//void test01() {
//    int a = 10;
//    my_int_type b = 10;
//    my_double_type c = 3.14;
//}
//#if 0
//struct Person {
//    char name[64];
//    int age;
//};
//typedef struct Person Myperson;
//#else
//typedef struct Person {
//    char name[64];
//    int age;
//}MyPerson;
//#endif
//void test02() {
//    MyPerson person = { "obama", 56 };
//}
//typedef long long LL;
//void test03() {
//    LL a = 10;
//    LL b = 20;
//}
//#include "Header.h"
//int main(void)
//{
//    
//    return 0;
//}


//逗号运算符: 将多个表达式变成一个表达式
//从左到右，左边的表达式执行完毕之后，右侧的表达式才会执行
//逗号运算符 最后一个表达式的结果作为整个表达式的结果
//void test01() {
//    int a = (10, 20, 30);
//    printf("%d", a);  //30
//}
//void test02() {
//    int a = 10;
//    int b = 20;
//    int c = 30;
//
//    c = (a = b + 10, b = a + 10);
//    printf("%d,%d,%d", a, b, c); //30 40 40
//
//}
//void test03() {
//    int a = 10;
//    int b = 20;
//    int c = 30;
//    c = b + 10, b = a + 10;
//    printf("%d,%d,%d", a, b, c); //10 20 30
//
//    c = (b + 10, b = a + 10);
//    printf("%d,%d,%d", a, b, c); //10 20 20
//
//}
//void test04() {
//    int a = 10;
//    //int b = (a++, a++, a++, a++);  最后一个a++，a作为整个表达式结果，先返回a 再++
//    //printf("%d,%d", a, b); //14 13  
//    int b = (++a, ++a, ++a, ++a);
//    printf("%d,%d", a, b); //14 14
//}
//void test05() {
//    for (int i = 0, j = 0; i < 10 && j<50; ++i, j += 10) {
//        printf("i = %d, j = %d\n", i, j);
//    }
//}
//#include "Header.h"
//int main(void)
//{
//    test01();
//    test02();
//    return 0;
//}


//文件理解
//相对路径 从盘符开始记录
//绝对路径 相对于当前目录的一个路径

//文本文件和2进制文件区别
//打开文件分为两种方式: 文本模式，二进制模式打开
//
//文本模式：换行符
//Mac : \r 作为换行符
//Windows : \r\n 作为换行符
//Linux : \n 作为换行符
//程序中换行符 : \n 作为换行符
//char s[] = "hello\n"; -> "hello\r";
//char s[] = "hello\n"; -> "hello\r\n";
//char s[] = "hello\n"; -> "hello\n";
//使用文本模式打开一个文件时，C语言会进行相应的换行符转换
//"hello\r" -> "hello\n"
//"hello\r\n" -> "hello\n"
//"hello\n" -> "hello\n"
//
//2进制文件读写不做任何转换
//"hello\r" -> "hello\r"

#if 0
//文件打开关闭
void test01() {
    // “r” 模式 以只读方式打开
    //fopen("C:\\Users\\zhanx\\c文件\\review_c\\demo1.txt","r"); //只是在windows下的写法
    //fopen("C:/Users/zhanx/c文件/review_c/demo1.txt", "r"); //通用写法，(推荐) //绝对路径
    FILE* fp = fopen("./demo1.txt", "r"); //相对路径
    if (fp == NULL) {               //返回的FILE指针。指向了一块内存。这块内存就存储了当前打开文件的信息
        printf("open fail\n");      //FILE指针指向的空间是系统帮我们申请的
        return;     //打开失败，返回null
    }

    //关闭文件
    //如果打开文件没有关闭，当程序关闭的时候，文件也会被关闭
    //文件使用完毕，要及时释放. 否则在程序结束前一直占用内存
    //1.fp 指向的内存就会被释放
    //2. 刷新缓冲区。会将缓冲区中的文件内容写入到磁盘中
    //3. 对于程序， 可打开的文件数量佑上限的
    fclose(fp);
    fp = NULL;
}
#endif

#if 0
//字符文件读写 fputc fgetc
void test01(){
    FILE* fp = fopen("./demo2.txt", "r");
    if (fp == NULL) {             
        printf("fail to open file\n");     
        return;     
    }
#if 0
    char c = fgetc(fp); //char c = 104
    printf("%c %d", c, c);  // 'h' = 104 
    //文本文件的结束符号就是-1
#endif

    /*char ch = fgetc(fp);
    while (ch != -1) {
        printf("%c", ch);
        ch = fgetc(fp);
    }*/
    
#if 0
    char ch = 0;
     //先执行fgetc --> ch --> 在判断
    while ((ch = fgetc(fp)) != EOF) { // -1 == EOF == end of file
        printf("%c", ch);
    }
#endif

#if 0
    char contents[128] = { 0 };
    int index = 0;
    while ((contents[index]= fgetc(fp)) != EOF) { // -1 == EOF == end of file
        index++;
    }
    printf("%s\n", contents);
#endif
   
    fclose(fp);
    fp = NULL;


}
void test02() {
    FILE* fp = fopen("./demo3.txt", "w");
    if (fp == NULL) {
        printf("fail to open!\n");
        return;
    }

    char* s= "hello world";

    for (int i = 0; i < strlen(s); ++i) {
        fputc(s[i], fp);
    }

    fclose(fp);
    fp = NULL;
    printf("success to write!");
}

#include "Header.h"
int main(void)
{
    test02();
    return 0;
}

#endif
//EOF and feof
//feof 适用于文本文件，2进制文件 (先读在判断)
//eof 适用于文本文件
#if 0
int main(){
    FILE* fp = fopen("./demo2.txt", "r");
    if (fp == NULL) {
        printf("fail to open file\n");
        return;
    }
#if 0
    char ch = 0;
    //"abc[-1]"
    while (!feof(fp)) {  //feof: (false)返回0：未到结尾 ，(true)返回非0： 已经到结尾
        //int f = feof(fp);
        //printf("%d", f);
        ch = fgetc(fp);
        printf("%c %d\n", ch, ch);
    }
#endif

#if 0
    char ch = 0;
    //"abc"
    while (1) {
        ch = fgetc(fp);
        //int f = feof(fp);
        //printf("%d", f);
        if (feof(fp)) {
            break;
        }
        printf("%c %d\n", ch, ch);
    }
#endif
    return 0;
}
#endif


//文件拷贝
#if 0
  //待拷贝文件：以读的方式打开
  //目的地文件：以写的方式打开

void test() {
    char file_src[128] = { 0 };
    char file_dst[128] = { 0 };
    printf("input src_directory: "); // ./demo3.txt
    scanf("%s", file_src);
    printf("input dst_directory: "); // ./demo4.txt
    scanf("%s", file_dst);

    FILE* fp_read = fopen(file_src, "r");
    if (fp_read == NULL) {
        printf("%s error! \n", file_src);
        return;
    }
    FILE* fp_write = fopen(file_dst, "w");
    if (fp_write == NULL) {
        fclose(fp_read);
        fp_read = NULL;

        printf("%s error!\n", file_dst);
        return;
    }

    //copy
    char ch = 0;
    while ((ch = fgetc(fp_read))!= EOF)
    {
        fputc(ch, fp_write);
    }
    //close file
    fclose(fp_read);
    fp_read = NULL;

    fclose(fp_write);
    fp_write = NULL;

    printf("%s copy fom %s: success \n", file_dst, file_src);
    
}
#include "Header.h"
int main(void)
{
    test();
    return 0;
}

#endif


//行文件读写
//fgets
//内容写入文件
#if 0 
void test01() {
    FILE* fp = fopen("./demo5.txt", "w");
    if (fp == NULL) {
        return;
    }
#if 0
    char* s = "hello world";
    //从s字符第一个字符开始到 \0 之前的内容写入到文件中
    fputs(s, fp);
#endif
    char* name[] = { "obama\n","trump\n","cliton\n", "bush\n", "polly\n", "smith\n" };
    for (int i = 0; i < sizeof(name)/sizeof(name[0]); i++)
    {
        fputs(name[i], fp);
    }
   
    fclose(fp);
    fp = NULL;
}
#endif
//文件读取
#if 0 
void test02() {
    FILE* fp = fopen("./demo5.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (1) {
        //申请空间，用于存储文件
        char line[128] = { 0 };
        //从文件中一次读取一行
        fgets(line, 128, fp);
        //判断文件是否结束
        
        if (feof(fp)) {
            break;
        }
        printf("%s", line);
    
    }
    fclose(fp);
    fp = NULL;
}
#endif

#if 0
//用于统计多少行
int file_count() {
    FILE* fp = fopen("./demo5.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    
    int count = 0;

    while (1)
    {
        char line[128] = { 0 };
        //读取每一行数据
        fgets(line, 128, fp);

        if (feof(fp)) {
            break;
        }
        ++count;
    }

    fclose(fp);
    fp = NULL;
    
    return count;
}
void test03() {
    //获取文件行数
    int line_cnt = file_count();
    printf("line count = %d\n", line_cnt);
    //根据文件行数开辟string指针数组

    char** lines = malloc(sizeof(char*) * line_cnt);
    //在从头按行读取文件内容， 根据内容长度开辟空间，并存储空间
    FILE* fp = fopen("./demo5.txt", "r");
    if (fp == NULL) {
        return;
    }
    int idx = 0;
    while (1) {
        char content[128] = { 0 };
        //读取每一行数据
        fgets(content, 128, fp);

        if (feof(fp)) {
            break;
        }
        //计算当前字符串的长度
        int len = strlen(content) + 1; // +1 == +'\0'
        //给字符串指针开辟空间
        lines[idx] = malloc(len);
        //拷贝内容
        strcpy(lines[idx], content);
        //累加下标
        ++idx;
    
    }

    fclose(fp);
    fp = NULL;
    //打印文件内容
    for (int i = 0; i < line_cnt; i++)
    {
        printf("%s", lines[i]);
    }
    //释放堆内存空间

    for (int i = 0; i < line_cnt; i++)
    {
        free(lines[i]);
        lines[i] = NULL;
    }

    free(lines);
    lines = NULL;
}


#include "Header.h"
int main(void)
{
    test03();
    return 0;
}

#endif

#if 0
void test04() {
    FILE* fp = fopen("./demo6.txt", "r");
    if (fp == NULL) {
        return;
    }

    //按行都内容 10+20
    while (1)
    {
        char line[64] = { 0 };
        fgets(line, 64, fp);

        if (feof(fp)) {
            break;
        }
        char* p= strchr(line, '+');  //找+号

        char left[32] = { 0 };
        strncpy(left, line, p - line); 
        char right[32] = { 0 };
        strcpy(right, p+1);

        right[strlen(right) - 1] = '\0';
        int l = atoi(left);
        int r = atoi(right);

        printf("%d+%d=%d\n", l, r, l + r);

    }
    

    fclose(fp);
    fp = NULL;
}
#include "Header.h"
int main(void)
{
    test04();
    return 0;
}
#endif


//块读写
#if 0
struct Person {
    char name[32];
    int age;
};
void test01() {
    //创建结构体变量
    struct Person person = { "Obama", 50 };
    //数据写入到文件中，都是2进制的
    //变量在内存中都是以2进制的方式存储的
    //将变量的在内存中的字节，一个一个的写到文件中
    FILE* fp = fopen("./demo7.txt", "wb");
    if (fp == NULL) {
        return;
    }
                                      //往fp里面写
    fwrite(&person,sizeof(struct Person), 1, fp);


    fclose(fp);
    fp = NULL;
}
void test02() {
    FILE* fp = fopen("./demo7.txt", "rb");
    if (fp == NULL) {
        return;
    }
    //申请person大小的空间
    struct Person p = {0};
                                    //从fp里面读
    fread(&p, sizeof(struct Person),1, fp);


    fclose(fp);
    fp = NULL;

}

void test03() {
    //创建person数组，并且将数组存储到文件中
    struct Person ps[] = {
        {"obama", 99},
        {"trump", 89},
        {"clinton", 100}
    };
    FILE* fp = fopen("./demo8.txt", "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(ps, sizeof(struct Person), 3, fp);


    fclose(fp);
    fp = NULL;

}

void test04() {
    FILE* fp = fopen("./demo8.txt", "rb");
    if (fp == NULL) {
        return;
    }

    struct Person ps[3] = { 0 };
    fread(ps, sizeof(struct Person), 3, fp);
    for (int i = 0; i < 3; i++)
    {
        printf("%s %d\n", ps[i].name, ps[i].age);
    }

    fclose(fp);
    fp = NULL;

}
#include "Header.h"
int main(void)
{
    test04();
    return 0;
}

#endif

//随机文件读写
#if 0
struct Person {
    char name[32];
    int age;
};
void test01() {
    //创建person数组，并且将数组存储到文件中
    struct Person ps[] = {
        {"obama", 99},
        {"trump", 89},
        {"clinton", 100}
    };
    FILE* fp = fopen("./demo9.txt", "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(ps, sizeof(struct Person), 3, fp);


    fclose(fp);
    fp = NULL;

}
void test02() {
    FILE* fp = fopen("./demo8.txt", "rb");
    if (fp == NULL) {
        return;
    }
    //移动指针到第二个Person数据首地址
    long pos = ftell(fp);
    fseek(fp, sizeof(struct Person), SEEK_SET);//指向trump
    //创建变量保存数据
    struct Person ps= { 0 };
                //偏移一个结构体变量字节(36)         
    fread(&ps, sizeof(struct Person), 1, fp);
    printf("%s %d\n", ps.name, ps.age); //读完后指向clinton
    
    fread(&ps, sizeof(struct Person), 1, fp); //读clinton
    printf("%s %d\n", ps.name, ps.age);

    int offset = sizeof(struct Person);//由于是无符号变量，需转换
    fseek(fp, -offset, SEEK_CUR); //返回trump
    fread(&ps, sizeof(struct Person), 1, fp); //读trump
    printf("%s %d\n", ps.name, ps.age);

    //fseek(fp, 0, SEEK_SET);//回到开始位置1
    //frewind(fp);//回到开始位置2


    fclose(fp);
    fp = NULL;

}
void test03() {
    //获取文件大小
    FILE* fp = fopen("./demo8.txt", "rb");
    if (fp == NULL) {
        return;
    }
    //将文件指针移到文件末尾，就可以
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp); //文件大小108字节
    printf("%ld %u", file_size, sizeof(struct Person)); //108 36

    fclose(fp);
    fp = NULL;
}
#include "Header.h"
int main(void)
{
    test02();
    return 0;
}

#endif 

#if 1
int g_a = 100;
 //1.堆区指针不能指向非堆区的内存
 //2.堆指针在释放之前进制重新赋值
 //3.堆内存释放之后仍然使用堆指针
 //4.堆指针地址修改后无法在free
 //5.malloc(0)时，不建议使用该空间

 //1.堆区指针不能指向非堆区的内存
void test01() {
    //1.栈变量
    int a = 10;
    int* p = &a;
    //free(p);//不能释放

    //字符串常量
    char* s = "hello world";
    //free(s);//不能释放

    //全局变量
    int* gp = &g_a;
   //free(gp); ////不能释放
}
//2.堆指针在释放之前进制重新赋于新空间
void test02() {
    int* p = (int*)malloc(sizeof(int));//重新赋值 这块内存会消失
    *p = 100;
    p = (int*)malloc(sizeof(int));
}
//3.堆内存释放之后仍然使用堆指针
void test03() {
    int* p = (int*)malloc(sizeof(int));
    *p = 100;
    free(p);
    //内存回收，使用权已经不归我们了
    //虽然没有报错，原则不能在使用了
    *p = 200;
    printf("*p = %d\n", *p);
}
//4.堆指针地址修改后无法在free
void test04() {
    int* p = (int*)malloc(sizeof(int)*10);
    p = p + 1;
    free(p); //free的时候一定要拿到空间首地址
             //我们虽然申请了40个字节，但实际上，申请的内存大于40，可能是44
             //多出来的4个字节用于存储堆空间大小
}
//5.malloc(0)时，不建议使用该空间
void test05() {
    int* p = malloc(0); //不是空指针
    printf("%p", p);
}
#include "Header.h"
int main(void)
{

    return 0;
}
#endif 
