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
//#define PI 3.1415926  //���� ��ֵ
//
//const int a = 10;	//���� const
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


//�������� ���Ὺ���ڴ�ռ�
//int a;
//extern int a;
//�������� �Ὺ���ڴ�ռ�
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
//	size_t var = 10; //typedef unsigned int (%u) size_t����Ϊunsigned int 4�ֽ�
//	printf("%u", var);
//}

//�ַ�
//int main(void) {
//	char ch1 = 'A';
//	printf("ch1 = %c %d\n", ch1, ch1);
//	char ch2 = 'm';
//	printf("ch2 = %c %d\n", ch2, ch2);
//	char ch3 = 97;
//	printf("ch3 = %c %d\n", ch3, ch3);
//
//	char ch4 = '\n';
//	printf(" '\\n' \\n ��ASCIIֵ�� %d", ch4);
//	return 0;
//}


//������
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

//����ת�� 10->2
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

//����ת�� 8->2
//         421     421 (8�������Ϊ7)
//056: 5-> 101 6-> 110   101 110
//05326: 5-> 101 3-> 011 2-> 010 6->110  101 011 010 110

//����ת�� 2->8
//421 421
//101 110 -> 056
//101 011 010 110 -> 05326

//����ת�� 8->10
//056: 5*8^1+6*8^0=46

//����ת�� 16->10   /A 10/B 11/C 12/D 13/E 14/F 15/ 
//0x1A: 1*16^1+10*16^0=26

//����ת�� 16->2
//		8421 8421
//0x1A: 0001 1010 
//       (1) (A)

//����ת�� 2->16
//8421 8421 8421
//0001 0011 1111: 13F

//int main(void) {
//	int a = 0x2c;
//	printf("%d\n", a);
//	printf("%o\n", a);
//	printf("%x\n", a);
//
//}

//Դ��
//���为
// 43: 00101011
//-43: 10101011
//����
// 43: 00101011
//-43: 10101011
//     11010100
//����
// 43: 00101011
//-43: 11010101

// 43-27 == 43 + -27
// 00101011 43
              //10011011 27
              //11100100 -27
// 11100101 +
//-----------
//(1)00010000
//(1)���Ȼ���Ƴ�

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
//10000001 ��Դ��---> 10000001-1 ��ȡ�� 11111111 -> -127



//volatile int flg;   volatile ���Ƿ�ֹ�������Ż�����
//flg = 0;  <----
//....
//flg = 1;
//flg = 0;  û��volatile,�м�ᱻ�Ż�����ȥ��
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
//    char str1[20] = { 'h','e','l','l','o','\0'}; //û'\0', ��������
//    
//    printf("ch = %c\n", ch);
//    printf("str = %s\n", str);
//    printf("str1 = %s\n", str1);

//    printf("%%");  //%�ٷֺ�ת�岻����'\'ת��
//    printf("%5s"); //��ʾ5���ַ��������ÿո��������
//    printf("%-5s"); //��ʾ5���ַ��������ÿո��������
//    printf("%05s"); //��ʾ5���ַ���������0�������
//}

//putchar (char only)
//int main(void) {
//    putchar(97); //'a' == 97
//    putchar('b');
//    putchar('\n')��//����
//}


//scanf()
//int main(void) {
//    int a, b; //���������ռ�
//    char c;
//    char str[10];
//
//    scanf_s("%d %d %c", &a, &b, &c); //'&': ��ʾȡ��������ַ������a�Ŀռ�
//    printf("a = %d \nb = %d \nc = %c", a, b, c);
//
//    scanf_s("%s", str); //�����������ʾ��ַ ���Բ���ȡ��ֵ����&��
//    printf("%s", str); //����洢�ռ�(10)����,hello world you(����10),���������
//                       //�����ܴ洢���ڴ��У�����������
//
//    return 0;
//}


//getchar()
//int main(void) {
//    char ch;
//    ch = getchar(); //�����û����룬���ؽ��յ���ASCII��
//
//    printf("ch = %c", ch);  
//    return 0;
//}


//�����
// + - * / %
//int a=1, b=2;
//c = a + b;
//c = a / b;
//c = a % b;
//c = a * b;
//c = a - b;

//ǰ׺����/�Լ�
//int i = 0;
//++i; // i = 1
//��׺����/�Լ�
//int i = 0;
//i++; // i = 0

//��ֵ�����
// += -= *= /= %=
// a%=2 --> a=a%2
// a+=2 --> a=a+2

//��Ŀ����� ?:
//int a = 1, b = 2;
// a > b ? 1 : 0;
// a > b ? 69 : (a < b ? 3 : 5); -->������

//���������
//int a = 10, b = 20, c = 30;
//int x = (a = 1, b = 2, c = 3);
//x = 3, a = 1, b = 2, c = 3

//��ʽ����ת����
//�ɱ������Զ���ɡ�
//�ɸ�ֵ����������ת���� С--���� û���⡣ �� --�� С �п��ܷ������ݶ�ʧ��
//int r = 3;
//float s = 3.14 * r * r;
//int a = 321:	256|128 64 32 16 8 4 2 1
//               1 |0   1  0  0  0 0 0 1
//char ch = a:   # |0   1  0  0  0 0 0 1
//ch = 65

//scanf 4996 ����
//method 1: #define _CRT_SECURE_NO_WARNINGS 
//method 2: #pragma warning(disable:4996)

//dowhile loop��ˮ�ɻ���  1^3+5^3+3^3 = 153  ֻ��100~999����
//int main(void) {
//   int num = 100;
//   int a, b, c;
//    do
//    {
//        //��λ�� 153 -> 3
//        a = num % 10; 
//        //ʮλ�� 153 -> 15 -> 5
//        b = num / 10 % 10; 
//        //��λ�� 153 -> 1
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

//��������Ϸ
//srand(time(NULL)) + #include<stdlib.h> + #include<time.h>
//int n = rand()%100;  /*0~99*/

//#include<stdlib.h> //ͷ�ļ�
//#include<time.h>
//
//int main(void) {
//    srand(time(NULL));//���һ���������
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

//��ӡ����ʱ��
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
//				system("cls"); //�����Ѹ���ԭ������
//			}
//		}
//
//	}
//}

//99�˷���
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

//����99�˷���
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

//����
//int main(void) {
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //Ԫ�ص�ַ����
//    printf("&arr[0] = %p\n", &arr[0]); // []�±� &ȡarr[0]��ַ
//    printf("&arr[1] = %x\n", &arr[1]);
//    printf("�����С: %u\n", sizeof(arr));  //40 4*10
//    printf("����Ԫ�ش�С: %u\n", sizeof(arr[0]); //4
//    printf("����Ԫ�ظ���/����", sizeof(arr) / sizeof(arr[0]));//10
//}

//�����ʼ����
//int arr[12] = { 1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 , 6, 8 };
//int arr[10] = { 1, 2 ,4, 6, 76, 8, 9 };  //ʣ��δ��ʼ����Ԫ�أ�Ĭ�� 0 ֵ��
//int arr[10] = { 0 }; //��ʼ��һ��ȫΪ 0 �����顣
//int arr[] = { 1, 2, 4, 6, 8 }; //�������Զ���ȡԪ�ظ���  
//int arr[] = { 0 };  //ֻ��һ��Ԫ�أ�ֵΪ0
//int arr[10];
//arr[0] = 5;
//arr[1] = 6;
//arr[2] = 7; //����Ԫ��δ����ʼ����Ĭ��Ϊ�����(such as -87877663)��

//����Ԫ������ ����ˮ��
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

//ð������
//int main(void) {
//	int arr[] = { 4,2,8,0,5,7,1,3,9 }; // 9 elements 
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	int temp;
//
//		for (size_t i = 0; i <len-1; i++) //������Ҫ�Ĵ���
//		{
//			for (size_t j = 0 ; j < len-1-i; j++) { //ÿ����Ҫ��len-1-i�� ���ݼ� 
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

//2ά����
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
//    //�����С
//    printf("�����С: %d\n", sizeof(arr)); //24
//    //һ�д�С
//    printf("һ�д�С: %d\n", sizeof(arr[0])); //12
//    //����һ��Ԫ�ش�С
//    printf("����һ��Ԫ�ش�С: %d\n", sizeof(arr[0][0])); //4
//    //����
//    printf("����: %d\n", sizeof(arr) / sizeof(arr[0])); //2 
//    //����
//    printf("����: %d\n", sizeof(arr[0])/sizeof(arr[0][0])); //3
//
//    //��ַ��һ��
//    //printf("%p\n", arr); == printf("%p\n", &arr[0][0]); == printf("%p\n", arr[0]);
//    //������׵�ַ == �������Ԫ�ص�ַ == ��������е�ַ��
//
//    //��ά����ĳ�ʼ����
//    //1�������ʼ����
//    int arr[3][5] = { {2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78} };
//    //2)����ȫ��ʼ����
//    int arr[3][5] = { {2, 3}, {2, 67, 4, }, {1, 4, 16, 78} };  //δ����ʼ������ֵΪ 0
//    int arr[3][5] = { 0 };	//��ʼ��һ�� ��ֵȫΪ0�Ķ�ά����
//    int arr[3][5] = { 2, 3, 2, 67, 4, 1, 4, 16, 78 };  // ���ټ��� ϵͳ�Զ��������С�
//    //3������ȫָ�����г�ʼ����
//    int arr[][] = { 1, 3, 4, 6, 7 }; // ��ά���鶨��*����ָ����ֵ��
//    int arr[][2] = { 1, 3, 4, 6, 7 }; // ����*��ָ����ֵ��{{1,3},{4,6},{7,0}}
//    return 0;
//}

//5��ѧ��3�Ź���
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
//    //ѧ�����˳ɼ�
//    for (int i = 0; i < row; i++)
//    {
//        int sum = 0;
//        for (int j = 0; j < col; j++)
//        {   
//            sum += scores[i][j];
//        }
//        printf("��%d��ѧ���ɼ�: %d", i+1, sum);
//        printf("\n");
//    }
//
//    //��һ�Ź����ܳɼ�
//    for (int i= 0; i< col; i++)
//    {
//        unsigned hw1 = 0;
//        for (int j = 0; j < row; j++)
//        {
//            hw1 += scores[j][i];
//        }
//        printf("��%d�Ź����ܳɼ�: %d", i+1, hw1);
//        printf("\n");
//    }
//
//    return 0;
//}

//��ά����
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
//	//int a[2][3][5] = { 1,2,3,4,5,6,7,8 }; //ϵͳ�Զ�����
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

//�ַ�����
//int main(void)
//{
//	char str1[5] = { 'h', 'e','l','l','o' }; //printf ->hello�������� ���������
//	char str2[6] = { 'h', 'e','l','l','o', '\0' }; //printf -> hello
//	char str3[] = "hello";
//	//ͳ���ַ�����ÿ���ַ����ֵĴ���
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

//��ȡ���пո���ַ���
//int main(void)
//{
//    char str[100];
//    //scanf("%s", str); //helloworld���� ��hello world���У� �����ո��\n
//    scanf("%[^\n]", str); //[^\n] ����\n֮�� -> ������ʽ
//    printf("%s", str);
//
//    return 0;
//}


//gets -> get string
//��ȡһ��string������string�׵�ַ
//char *gets(char *s);
//��������������string�Ŀռ�
//����ֵ�� ����ʵ�ʻ�ȡ����string
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
//arg1:��������string�Ŀռ��ַ
//arg2:�ռ��С
//arg3:��ȡstringλ�� ��׼����:stdin
//����string
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[10];                      //����������
//    printf("%s", fgets(str, sizeof(str), stdin));
//    //��Ԥ��\0�Ŀռ� hello world -> hello wor
//    //���㹻�ռ���\n
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
//    //�������Զ���\n
//    return 0;
//}

//fputs
//int fputs(const char *s, FILE *stream)
//arg1: string
//arg2: �ļ�ָ�룬�����string�������Ļ���̶�дΪstdout
//return: positive int for success, negative for fail
//#include<string.h>
//#include<stdlib.h>
//int main(void)
//{
//    char str[] = "hellow world";
//    //fputs("hello world\n", stdout);
//    fputs(str,stdout);
//    //����� *�����Զ���\n
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
//    //str3[i + j] = '\0'; //��char str3[100]; δ��ֵʱ
//    printf("%s", str3);
//    return 0;
//}


//��������
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

//�����
//srand(time(NULL))
//#include<stdlib.h> <time.h>
//rand()%100

//�β� ʵ��
//add(int a, int b) //int a �β�
//add(1,3)  //1 ʵ��

//exit()
//������������

//header file
//#pragma once ��ֹͷ�ļ��ظ�����  (windows��)
//#include "head.h"

//#ifndef __HEAD_H__ (Linux��)
/*
  #define __HEAD_H__
  ��������
  #include<>ͷ�ļ�
  #define �궨��
  ���Ͷ���
  ...
*/
//#endif

//ָ��(��ַ)==�ڴ浥Ԫ�ı��(һ���ֽ�) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

//int main(void)
//{
//	int a = 10; // 4���ֽ�
//	printf("%p", &a);
//	/*
//		----------   ���
//		|00000000|	0133F703	1���ֽ�
//		----------
//		|00000000|	0133F702	1���ֽ�
//		----------
//		|00000000|	0133F701	1���ֽ�
//		----------
// (a=10)|00001010|  0133F700	1���ֽ�
//		----------
//	*/
//
//	return 0;
//}

//ָ�붨���ʹ��
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

//Ұָ��
//#include "Header.h"
//int main(void)
//{
//	int* p1;  //1)û��һ����Ч��ַ�ռ��ָ��(ûָ����ַ)
//	*p1 = 1000;
//
//	int* p2 = 10; //2)��ָ��ֵ������ֵû��ַ
//	*p2 = 2000;
//
//	return 0;
//}

//��ָ��
//int* p  = NULL;
//*p, p ����Ӧ�Ĵ洢�ռ���һ�� ��Ч�ķ�������

//����ָ���ָ��
//#include "Header.h" //#include files....
//int main(void)
//{
//    int a = 345;
//    void* p;   //δָ������
//    p = &a;
//    printf("%d", *((int*)p)); //��(p��ַ)ǿת��int*����
//
//    char ch = 'a';
//    void* p1;
//    p1 = &ch;
//    printf("%c", *(char*)p1);
//
//	return 0;
//}

//���α���
//#include "Header.h"
//int main(void)
//{
//    /*const int a = 20;
//    int* p= &a;
//    *p = 650;
//    printf("%d", a);*/
//
//    //����ָ��
//
//    //const int *p
//    //int a = 10;
//    //int b = 30;
//    //const int* p = &a;
//    //*p = 500;  //�������޸�*p
//    //p = &b;    //�����޸�p
//
//    //int const*p
//    //int a = 10;
//    //int b = 30;
//    //int const *p = &a;
//    //*p = 300;   //�������޸�*p
//    //p = &b;     //�����޸�p
//
//    //int* const p
//    //int a = 10;
//    //int b = 30;
//    //int* const p = &a;
//    //*p = 300;   //�����޸�*p
//    //p = &b;     //�������޸�p
//
//    //const int* const p
//    //int a = 10;
//    //int b = 30;
//    //const int* const p = &a;
//    //*p = 300;    //�������޸�*p
//    //p = &b;     //�������޸�p
//
//    //�ܽ᣺const�������Σ������εĲ��ּ�Ϊֻ��

//    //ȡ����Ԫ�أ�
//    //int arr[] = { 1,3, 5, 7, 8 };
//    //int* p = arr;
//
//    //arr[i] == *(arr + 0) == p[0] == *(p + 0)
//
//    //ָ�����������
//
//    //1. ָ���Ǳ�����������Ϊ������
//    //2. sizeof(ָ��) ---> 4�ֽ�(windows)/8�ֽ�(linux)
//    //sizeof(����) ---> �����ʵ���ֽ�����
//
//	return 0;
//}

//�������Ͷ�ָ�������
//#include "Header.h"
//int main(void)
//{						//16��������Ӧ(4λ��������) ��Ϊ (2^4)
//						//8��������Ӧ(3λ��������)	��Ϊ (2^3)
//    int a = 0x12345678; //int 4bytes = 32bit | 4bit/per | '12' = 1 bytes
//	/*	----------                 
//		|   12   |	��	1���ֽ�		
//		----------
//		|   34   |		1���ֽ�
//		----------
//		|   56   |		1���ֽ�
//		----------
//		|   78   |  ��	1���ֽ�
//		----------
//	*/
//	// ����p��ָ��ͳһ��ַ&a
//    char* p = &a; //0x00000078  == 1 bytes
//    short* p = &a;//0x00005678	== 2 bytes
//    int* p = &a;  //0x12345678  == 4 bytes
//	//���ã�������ָ��洢�ĵ�ַ��ʼ������ȡ���ֽ��� (��ָ�뱾��洢�ռ��޹�)
//	//short*p p-->0x00ff01 p+1 --> 0x00ff03 (short 2bytes)
//
//	//p++,p+1,p+=1 �Ĳ�ͬ p = 0xff01
//	//p++ == p+=1 --> p ������ַ ���� 0xff02
//	//p+1 --> p ������ַû�� 0xff01
//
//	//****************������ȡ��ַ*********************
//	//int a[10] = {1,2,3,4,5,6,7,8,9,0};
//	// a --> 0xff00
//	// &a[0] --> 0xff00
//	// a+1 --> 0xff04
//	// &a --> 0xff00
//	//int*p; p+1
//	// &a+1 --> &a(��������) + 1(sizeof(int)*10: һ���������С)
//
//	//ָ��Ӽ�ָ��
//	//p + q error!!
//	//p - q ƫ�Ƶ�Ԫ�ظ��� 
//
//
//	return 0;
//}

////ָ������1
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
//    printf("%d", **arr);    //����ָ��
//
//	return 0;
//}
//
////ָ������2
//#include "Header.h"
//int main(void)
//{
//    int a[] = {10};
//    int b[] = {20};
//    int c[] = {30};
//
//    int* arr[] = { a,b,c };
//    //arr[0][0] == *(*(arr+0)+0) //��ά����Ҳ��2��ָ��
//
//    printf("%d", *arr[0]);  //*(*(arr+0)) == *(*arr) == **arr
//    printf("%d", **arr);    //����ָ��
//
//    return 0;
//}

////�༶ָ��
//#include "Header.h"
//int main(void)
//{
//    int a = 10;
//    int* p = &a;    //1��ָ���� ������ַ
//    int** pp = &p;  //2��ָ���� 1��ָ��ĵ�ַ
//    int*** ppp = &pp; //3��ָ���� 2��ָ��ĵ�ַ
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

//��ֵ�ʹ�ַ
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
//    //-----------��ֵ------------//
//    printf("before: %d and %d", m, n);
//    swap(m, n);         //��ֵ��a,b: a = m, b =n, ��m,n��û��
//    printf("after: %d and %d", m, n);  
//    //-----------��ַ-----------//
//    printf("before: %d and %d", m, n);
//    swap(&m, &n);       //m,n�ڲ���ַ���ˣ�ֵ ��ȻҲ�ͱ���
//    printf("after: %d and %d", m, n);
//	return 0;
//}

//��������������
//void BubbleSort(int arr[10]) == void BubbleSort(int arr[]) == void BubbleSort(int* arr)
//sizeof(arr) == 4 because ָ���СΪ4

//#include "Header.h"
//void BubbleSort(int arr[]) { //int arr[] == int *arr;
//    printf("%d", sizeof(arr)); //4 
//}
//
//int main(void)
//{
//    int arr[] = { 1,2,3,4 };
//    printf("%d", sizeof(arr)); //16, ��ͬ�� void BubbleSort(int arr[]); sizeof(arr) = 4
//	return 0;
//}  //���ݲ������������飬����������׵�ַ��һ��ָ�룩��


//ָ������������ֵ
//#include "Header.h"
//int m = 100; //global variable ȫ�ֱ���
//int* test(int a, int b) {
//    
//    int p = 1234; //�ֲ�����
//    //return &p; �޷����أ�����ִ���������ջ֡�ᱻ�ͷš�
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

//ָ���string
//char str1[] = { 'h', 'i', '\0' };	//�������ɶ���д
//char str2[] = "hi";				//�������ɶ���д
//char* str3 = "hi";				//������ֻ��
//str3 �����У��洢�����ַ���������hi�����׸��ַ� ��h�� �ĵ�ֵַ��
//str3[1] = 'H';	// ���󣡣�
//char* str4 = { 'h', 'i', '\0' };  // ���󣡣���

//string �Ƚ�
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
//    // int ret = stringCmp(str1, str2);  //���Ƚϳ���, ���Ƚ� 'z','w', 'z'>'w' 
//    int ret1 = stringCmp2(str1, str2);  //ָ��Ƚ�
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
//void myStringCopy(char* src, char* dest) { //����汾
//    int i = 0;
//    while (src[i]!=0) 
//    {
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0';
//
//}
//void myStringCopy2(char* src, char* dest) { //ָ��汾
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

//���ַ����в����ַ� ���ֵ�λ��
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

//string ȥ�ո�
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

//strstr : �� str�У���substr���ֵ�λ��
//char* strstr(char*str,char*substr)
//
//#include "Header.h"
//int main(void)
//{
//    char* ret = strstr("hellollollo", "llo");
//    printf("%s", ret); // llollollo �Ӵ���ԭ���е�λ��(��ֵַ), û�еĻ�����NULL
//	return 0;
//}

//strstr �Ӵ�(substr) ���ֵĴ���
//#include "Header.h"
//int str_times(char* str, char* substr) {
//    int count = 0;
//    char* p = strstr(str, substr); //lloabcllozxyllo
//    while (p) { // ==> p!= NULL
//        count++;                //p += p + sizeof(substr) �С�\0�� error!!
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


//��ǿ��ַ���Ԫ�ظ�����
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


//�ַ������ã� str_inverse
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
//int inverse(char* str) {  ����汾
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
//int inverse2(char* str) {   //ָ��汾
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

//�ж��ַ����ǻ��ģ�  level levvel  ������һ��
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


//�ַ��������� #include<string.h>
//strcopy ��  strncpy
//#include "Header.h"
//int main(void)
//{
//    //char src[] = "hello";
//    //char dest[6];//��Ҫ�㹻��ռ�
//    //strcpy(dest, src);  //char* strcpy(char* dest, const char* src)
//    //printf("%s", dest);
//
//
//    char src[] = "hello world";
//    char dest[10] = {0};
//
//    char* p = strncpy(dest, src, 10); 
//    //char* strncpy(char* dest, const char* src, size_t n)
//    //n(��dest�ռ��Ӧ)> src: ֻ���� src ��С
//    //n(��dest�ռ��Ӧ)< src: ֻ���� n �ֽڴ�С�� ����ӡ�\0��, ��������
//    printf("%s", p);
//
//	return 0;
//}


//strcat
//#include "Header.h"
//int main(void)
//{
//   /* char src[] = "world";
//    char dest[] = "hello";  //dest �ռ䲻������������û��
//    char* p = strcat(dest, src);
//    printf("%s\n", p);
//    printf("%s\n", dest);*/
//    //char* strcat(char* dest, const char* src)
//
//    char src[] = "world";
//    char dest[] = "hello";  //dest ��Ҫ�ռ��㹻�� dest[11]���ᱨ��
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
//					//�������'"��ʽ��string" �浽������(buffer) dst
//	int len = sprintf(dst, "a = %d, src = %s", a, src);
//	printf("dst = \"%s\"\n", dst);
//	printf("len = %d\n", len); //ʵ�ʸ�ʽ���ַ�����
//	return 0;
//}

//sscanf == string --> scanf
//#include "Header.h"
//int main(void)
//{
//	//char src[] = "a=10, b=20";
//	char src1[] = "10+20=30";
//	int a;
//	int b;								//ԭ��scanf��Ҫ��Ļ����
//	int c;								//����ֱ�Ӵ�src����д��&a,&b��
//	//sscanf(src, "a=%d, b=%d", &a, &b);
//	sscanf(src1, "%d+%d=%d", &a, &b, &c);
//	printf("a:%d, b:%d, c:%d\n", a, b, c);
//	return 0;
//}

//strchr ����string���ַ����Ӵ��ĵ�ַ  ��-->��
//#include "Header.h"
//int main(void)
//{
//	char src[] = "ddda123abcd";
//	char* p = strchr(src, 'a');
//	printf("p = %s\n", p); //a123abcd
//	return 0;
//}
//strrchr ����string���ַ����Ӵ��ĵ�ַ ��-->��
//#include "Header.h"
//int main(void)
//{
//	char src[] = "ddda123abcd";
//	char* p = strrchr(src, 'a');
//	printf("p = %s\n", p); //a123abcd
//	return 0;
//}

//strstr ��str�����Ӵ�substring
//#include "Header.h"
//int main(void)
//{
//	char str[] = "hehehehabc123hohoh";
//	printf("%s", strstr(str, "abc"));  //abc123hohoh
//
//	return 0;
//}


//strtok �ַ����ָ�
//return: �ַ�����ֺ���׵�ַ���ָ���á�\0���滻  www.baidu.com --> www\0baidu.com
//#include "Header.h"
//int main(void)
//{
//	//char *a = "adc*fvcv.ebcy*hghbdfg$casdert";  ���������� ����ɶ���д
//	char a[100] = "adc*fvcv.ebcy*hghbdfg$casdert";
//	char* s = strtok(a, ".*$");//��"*"�ָ���Ӵ�ȡ��     //��һ�β�֣���1��ԭ��
//	//printf("%s\n", s);	//adc	// %s ������\0���ͻ�ֹͣ
//	while (s != NULL)	
//	{
//		printf("%s\n", s);
//		s = strtok(NULL, ".*$");  //�����ٲ�֣���1��NULL(0)��ԭ���� strtok�ڲ��о�̬���� 
//								//�ڵ�һ�β�ֺ󣬱����š�ʣ�µ��ַ������ĵ�ַ
//		//printf("%s\n", s);
//	}
//	return 0;
//}

//atoi, atof, atol
//#include "Header.h"
//int main(void)
//{
//	char str1[] = "          -10";  //����ʹ��--�� 123zxy--> 123  abc345-->0
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


//static ȫ�ֱ���
//#include "Header.h"   //***********************ע�����*********************/
//extern int a;     //�����������������.c�ļ��� (global) int a=10, �������.c�ļ������
//                  //����� static int a=10, ����������.c�ļ��С� û�����������
//int main(void)
//{
//    printf("%d", a);
//	return 0;
//}


//static �ֲ�����   
//#include "Header.h"
//void foo() {
//    int b = 10;
//    printf("%d\n", b++);  
//}
//void foo2() {
//    static int b2 = 20;     //ֻ����һ�Ρ��൱���ڡ�ȫ��λ�á�����һ�Ρ��������ڵ�������
//    printf("%d\n", b2++);
//}
//int main(void)
//{
//    for (size_t i = 0; i < 10; i++)
//    {
//        foo();   //b=10,b=10,b=10.....��Ϊ ÿ�ε��� ������������������b��
//    }
//
//    for (size_t i = 0; i < 10; i++)
//    {
//        foo2();   //b=10,b=11,b=12....
//    }
//
//	return 0;
//}


//static���� = static + ����ԭ�� + ������
//ֻ���ڱ��ļ��ڲ�ʹ��
//void foo(void);     //static void foo(void) ��str_func.c�ļ�
//
//#include "Header.h"
//int main(void)
//{
//    foo();
//	return 0;
//}

//�ڴ�ռ�window
//����Σ� .text�Ρ�����Դ���������
//���ݶΣ� ֻ�����ݶ� .rodata�Ρ���ʼ�����ݶ�.data�Ρ� ��ʼ�����ݶ�.bss��
//stack�� ջ������֮�Ͽ��� ջ֡�� windows: 1M----10M  linux: 8M---16M
//heap�� �ѡ����û����������ṩ�ռ䡣 Լ1.3G+
/*
    -----------------------
    |  .text   |  ���ݶ�   |      .data��:��ʼ��Ϊ��0��ȫ�ֱ����;�̬����
    |  (binary)|   ------------> .bss��:��ʼ��Ϊ0��δ��ʼ����ȫ�ֱ����;�̬����
    |          |          |             �������ִ��ǰ���Ὣ�ö����帳ֵΪ0
    ----------------------       .rodata:ֻ�����ݶ�,����
    |   stack  |   heap   |
    |     |    |     ----------> �ռ��㹻��
    |     |    |          |      
    ------|----------------
          |
          V
    �Ƚ�С��ϵͳ�Զ�����
    �Զ����䣬�Զ��ͷš�
    �洢���ԣ�FILO
*/


//�ڴ�ռ�linux
/*	    ---------- 4G
		|        |	---> �ں˿ռ�
		---------- 3G
		| stack ||	
        |       V|
		----------
        |   C    |  ---> ��׼����ص�λ��
        ----------
        |       ^|       �û��ռ�
        |  heap ||
        ----------  --------
        | .bss   |
        ----------  ��дȨ��
        | .data  |
        ----------  --------
        |.rodata |
        ----------  ֻ��
		| .text  |  
		---------- 0
*/


//�������ڣ�
//
//�ֲ��������ӱ������忪ʼ������������ɡ�-- - �����ڲ���
//ȫ�ֱ���������������ʼ��������ֹ������-- - ����ִ���ڼ䡣
//static�ֲ�����������������ʼ��������ֹ������-- - ����ִ���ڼ䡣
//staticȫ�ֱ���������������ʼ��������ֹ������-- - ����ִ���ڼ䡣
//ȫ�ֺ���������������ʼ��������ֹ������-- - ����ִ���ڼ䡣
//static����������������ʼ��������ֹ������-- - ����ִ���ڼ䡣

//���� Ĭ���� ջstack��
//������Ҫ���� heap �ռ䣬����Ҫmalloc and free
//void* malloc(size_t size); //����size��С�Ŀռ䣬�����ڴ�ռ��׵�ַ
                             //ͨ��������������
//void free(void* p); //�ͷŷ�����Ŀռ�
           //mallocd���صĵ�ֵַ

//#include "Header.h"
//int main(void)
//{
//    //int arr[1000000] //̫�� �޷�ִ��  1m --- 10m
//    //int arr[10] �ռ��С 4 bytes + 10 = 40  ��������(ջ)stack��
//
//    int * p = (int*)malloc(sizeof(int) * 10); // 40   ��������(��)heap��
//    //int* p = malloc(sizeof(int)*10) ��ʽת�� void*-->int*
//    if (p == NULL) {
//        printf("error");
//        return -1;
//    }
//*******************************************//
//    char*tmp =p;
//*******************************************//
//    //д���ݵ�malloc�Ŀռ�
//    for (size_t i = 0; i < 10; i++)
//    {
//        p[i] = i + 10;
//    }
//
//    //����malloc�ռ������
//    for (size_t i = 0; i < 10; i++)
//    {
//        printf("%d", *(p+i));
//    }

//    //p++; �ռ��ַ���ˣ����޷��ͷţ�error 

//------------------------------------------------------//    
//    for(size_t i = 0; i < 10; i++)
//    {
//          printf("%d", *p);
//          p++; //�ᵼ���ڴ��ַ�仯, ����Ҫһ����ʱ���� char*tmp= p; 
//    }
//    for(size_t i = 0; i < 10; i++)
//    {
//          printf("%d", *tmp);
//          tmp++; 
//    }
//    free(tmp)
//------------------------------------------------------//

//    //�ͷ������ڴ�
//    free(p);  //free ��󲻻�����ʧЧ�������ݱ��ˡ�p��Ϊ��
//    p=NULL;
//    return 0;
//}


//int* p = malloc(200);
//p = realloc(p, 400); //��p�����ϣ� ���ڴ���չ��400���ֽ�
//p = realloc(p, 200);//��p�����ϣ� ���ڴ���С��200���ֽ�
//int* p1 = realloc(NULL, 100); //��1��NULL�����ø�mallocһ��


//2��ָ��heap�ռ�
#include "Header.h"
//int main01(void)
//{                                                                       //10�� 4 bytes (int*)
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
//    //д
//    for (size_t i = 0; i < 3; i++)
//    {
//        for (size_t j = 0; j < 5; j++)
//        {
//            p[i][j] = i + j;
//        }
//    }
//    //��
//    for (size_t i = 0; i < 3; i++)
//    {
//        for (size_t j = 0; j < 5; j++)
//        {
//            printf("%d ", *(*(p+i)+j) ); //p[i][j]
//        }
//        printf("\n");
//    }
//    //�ͷ��ڲ�ռ䣬���ͷ����ռ�
//    for (size_t i = 0; i < 3; i++)
//    {
//            free(*(p + i)); //p[i]
//            p[i] = NULL;
//    }
//   
//    //�ͷ����ռ�
//    free(p);
//    p = NULL;
//
//    return 0;
//}

//����ջ����ַ
//#include <stdio.h>
//int* fun()
//{
//    int a = 10;
//    return &a;//����������ϣ�a�ͷ�
//}
//
//int main(int argc, char* argv[])
//{
//    int* p = NULL;
//    p = fun();
//    *p = 100; //����Ұָ��ָ����ڴ�,err
//
//    return 0;
//}



//����data����ַ
//#include <stdio.h>
//
//int* fun()
//{
//    static int a = 10;
//    return &a; //����������ϣ�a���ͷ�
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

//ֵ����1
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
//    fun(p); //ֵ���ݣ��β��޸Ĳ���Ӱ��ʵ��
//    printf("*p = %d\n", *p);//err��������ָ��ָ����ڴ�
//
//    return 0;
//}


//ֵ����2
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
//    fun(p); //ֵ����
//    printf("*p = %d\n", *p); //ok��*pΪ100
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
//    memset(a, 97, sizeof(a));  //a���� ��a�� 4*10
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

//memmove == memcpy ����ִ��Ч�ʱ�mencpy��

//int memcmp(const void *s1, const void *s2, size_t n);
//�Ƚ�s1��s2��ָ���ڴ������ǰn���ֽ�
#include "Header.h"
//int main(void)
//{
//    int a[10] = { 1, 2, 11, 4, 5, 6, 7, 8, 9, 10};
//    int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//    int flag = memcmp(a, b, sizeof(a));  // =: 0, >: 1, <: -1
//    int flag2 = memcmp(a, b, 8); // 3*int ǰ12���ֽ�
//    printf("flag = %d\n", flag);
//    printf("flag2 = %d\n", flag2);
//    return 0;
//}

//�ṹ��
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

//�ṹ�����˵��
//struct A {
//    int a;
//    int b;   
//};   //struct A a; sizeof(a) = 8 bytes
//
//struct A {
//    char a;     //1 ��3 == 1
//    int b;      //4     == 4 ��int���� 
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
//};   //sizeof(A) = 1 bytes ...��Ϊ������ͬ
//------------------------------------//
//struct A {
//    char a;
//    //ȱʧ��1���ֽ�
//    short b;
//    int c;
//    short d;
//    char e;
//};   //sizeof(a) = 12 bytes
////����ͨ��ָ�������ʣ�����
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
//    unsigned char a : 2; //aֻ��2��bit��С 
//    unsigned char b : 4; //bֻ��4��bit��С
//    char c : 4;
//};
//
//#include "Header.h"
//int main(void)
//{
//    struct A a;
//    a.a = 5;
//    printf("%x", a.a); //1 --> _01  2bit������101
//    a.b = 9;
//    printf("%x", a.b); //9 --> 1001  4bit�ոպ�
//    a.c = 13;
//    printf("%d", a.c); //-3 --> 1101  ��һλ�ǡ�-������λ����Ϊc��signed char
//                                       //��ԭ�� --> 1101ȡ�� -->1010
//                                        //--> +1 --> 1011 --> -3
//    return 0;                         
//}


//struct Student {
//    char name[64];   <---------------------�ɶ���д
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
//    char* name;    <----------------------ֻ��
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


//�ṹ��Ƕ��
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
//    struct { //�����ṹ��
//        int bag;
//        int accessories;
//    }bag;
//};


//�ṹ��ָ��ʹ��
//struct Person {
//    char* name;
//    int age;
//    int salary;
//}p1 = { NULL, 10 ,9999 }, * p2 = NULL; //p2 �ṹ��ָ��(4 bytes)
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


//�ṹ����Ϊ����
//struct Person {
//    char name[64];
//    int age;
//};
//void print_person(struct Person p) {
//    printf("%s %d", p.name, p.age);
//}
////��ַ��ָ�룩���� --���޸ı���
//void print_person_by_pointer(struct Person* p){
//    printf("%s %d", p->name, p->age);
//}
////��ַ��ָ�룩���� --�����޸ı���
//void print_person_by_pointer2(const struct Person* p) {
//    printf("%s %d", p->name, p->age);
//}
//
//void test01() {
//    struct Person person = { "obama", 33 };
//    //person �� p û���κι�ϵ�� p�޸Ĳ��ᵼ��person�ı�
//    //���ṹ��68 �ֽ����ݿ����� p����
//    print_person(person);
//    //����Ч�ʲ���
//    //�����޷��޸��ⲿ����
//    print_person_by_pointer(&person);
//}
//void test02() {
//    //�ṹ��ָ��
//    struct Person* p_person = NULL;
//    //�ṹ�����
//    struct Person person = { "obama", 33 };
//   //ָ�����(ջ��)  ��ͨ����(ջ��)
//        p_person = &person;
//    //ָ�����ָ�� ջ�������ѱ������ַ�������
//    //ջ�� ����Ҫfree
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


//�ṹ������������
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
//    //���� �ṹ������
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
//int main(int argc, char*argv[]) //main�����Ĳ��� �Ƿ��ܹ�ʡ�� ȡ���ڱ�����
//{
//    //printf("%d\n", argc);
//    //for (int i = 0; i < argc; i++)
//    //{
//    //    printf("%s\n", argv[i]); // argv[i] �� char*���� char*������ָ��string
//    //}
//    test();
//
//    return 0;
//}


//union������
//union MyUnion
//{
//    int a;     //union �����ݳ�Ա�����ڴ�
//    char d;  // a,d ��ַһ���ġ��������ֵ����d���ܸ��ǵ�a
//};
//
//void test01() {
//    printf("Union size is: %d", sizeof(union MyUnion)); //4 �����Ϊ׼
//    union MyUnion n;
//    printf("%d %d\n", &n.a, &n.d);//a,b��ַ��ͬ
//
//    n.d = 97;
//    printf("%d\n", n.d); //97
//    n.a = INT_MAX;
//    printf("%d\n", n.d); //-1
//
//}
//void test02() {
//    union MyUnion n1 = {100}; //��ʼ����ֻдһ��ֵ�Ļ�==Ĭ�ϸ���һ����Ա��ֵ
//    printf("n1.a = %d", n1.a);
//
//    //C99���﷨, ��ָ����Ա��ʼ��
//    union MyUnion n2 = { .d = 97};
//    printf("n2.d = %d", n2.d);
//}
////int 4 bytes, �ֱ��ӡ4���ֽڵ�ֵ
//union MyNumber
//{
//    unsigned int number;
//    char byte[4];
//};
//void test03() {
//    union MyNumber number = { UINT_MAX };
//    //4 �ֽ�
//    //11111111 11111111 11111111 11111111
//    //10000000 10000000 10000000 10000000
//    //+1
//    //10000001 10000001 10000001 10000001
//    // -1         -1       -1       -1
//    //������ͨ���ַ��������ʽ����
//    printf("�ֽ���ֵ��%d �ֽڵ�ַ�� %d", number.byte[0], &number.byte[0]);
//    printf("�ֽ���ֵ��%d �ֽڵ�ַ�� %d", number.byte[1], &number.byte[1]);
//    printf("�ֽ���ֵ��%d �ֽڵ�ַ�� %d", number.byte[2], &number.byte[2]);
//    printf("�ֽ���ֵ��%d �ֽڵ�ַ�� %d", number.byte[3], &number.byte[3]);
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


//���������: ��������ʽ���һ�����ʽ
//�����ң���ߵı��ʽִ�����֮���Ҳ�ı��ʽ�Ż�ִ��
//��������� ���һ�����ʽ�Ľ����Ϊ�������ʽ�Ľ��
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
//    //int b = (a++, a++, a++, a++);  ���һ��a++��a��Ϊ�������ʽ������ȷ���a ��++
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


//�ļ����
//���·�� ���̷���ʼ��¼
//����·�� ����ڵ�ǰĿ¼��һ��·��

//�ı��ļ���2�����ļ�����
//���ļ���Ϊ���ַ�ʽ: �ı�ģʽ��������ģʽ��
//
//�ı�ģʽ�����з�
//Mac : \r ��Ϊ���з�
//Windows : \r\n ��Ϊ���з�
//Linux : \n ��Ϊ���з�
//�����л��з� : \n ��Ϊ���з�
//char s[] = "hello\n"; -> "hello\r";
//char s[] = "hello\n"; -> "hello\r\n";
//char s[] = "hello\n"; -> "hello\n";
//ʹ���ı�ģʽ��һ���ļ�ʱ��C���Ի������Ӧ�Ļ��з�ת��
//"hello\r" -> "hello\n"
//"hello\r\n" -> "hello\n"
//"hello\n" -> "hello\n"
//
//2�����ļ���д�����κ�ת��
//"hello\r" -> "hello\r"

#if 0
//�ļ��򿪹ر�
void test01() {
    // ��r�� ģʽ ��ֻ����ʽ��
    //fopen("C:\\Users\\zhanx\\c�ļ�\\review_c\\demo1.txt","r"); //ֻ����windows�µ�д��
    //fopen("C:/Users/zhanx/c�ļ�/review_c/demo1.txt", "r"); //ͨ��д����(�Ƽ�) //����·��
    FILE* fp = fopen("./demo1.txt", "r"); //���·��
    if (fp == NULL) {               //���ص�FILEָ�롣ָ����һ���ڴ档����ڴ�ʹ洢�˵�ǰ���ļ�����Ϣ
        printf("open fail\n");      //FILEָ��ָ��Ŀռ���ϵͳ�����������
        return;     //��ʧ�ܣ�����null
    }

    //�ر��ļ�
    //������ļ�û�йرգ�������رյ�ʱ���ļ�Ҳ�ᱻ�ر�
    //�ļ�ʹ����ϣ�Ҫ��ʱ�ͷ�. �����ڳ������ǰһֱռ���ڴ�
    //1.fp ָ����ڴ�ͻᱻ�ͷ�
    //2. ˢ�»��������Ὣ�������е��ļ�����д�뵽������
    //3. ���ڳ��� �ɴ򿪵��ļ����������޵�
    fclose(fp);
    fp = NULL;
}
#endif

#if 0
//�ַ��ļ���д fputc fgetc
void test01(){
    FILE* fp = fopen("./demo2.txt", "r");
    if (fp == NULL) {             
        printf("fail to open file\n");     
        return;     
    }
#if 0
    char c = fgetc(fp); //char c = 104
    printf("%c %d", c, c);  // 'h' = 104 
    //�ı��ļ��Ľ������ž���-1
#endif

    /*char ch = fgetc(fp);
    while (ch != -1) {
        printf("%c", ch);
        ch = fgetc(fp);
    }*/
    
#if 0
    char ch = 0;
     //��ִ��fgetc --> ch --> ���ж�
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
//feof �������ı��ļ���2�����ļ� (�ȶ����ж�)
//eof �������ı��ļ�
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
    while (!feof(fp)) {  //feof: (false)����0��δ����β ��(true)���ط�0�� �Ѿ�����β
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


//�ļ�����
#if 0
  //�������ļ����Զ��ķ�ʽ��
  //Ŀ�ĵ��ļ�����д�ķ�ʽ��

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


//���ļ���д
//fgets
//����д���ļ�
#if 0 
void test01() {
    FILE* fp = fopen("./demo5.txt", "w");
    if (fp == NULL) {
        return;
    }
#if 0
    char* s = "hello world";
    //��s�ַ���һ���ַ���ʼ�� \0 ֮ǰ������д�뵽�ļ���
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
//�ļ���ȡ
#if 0 
void test02() {
    FILE* fp = fopen("./demo5.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (1) {
        //����ռ䣬���ڴ洢�ļ�
        char line[128] = { 0 };
        //���ļ���һ�ζ�ȡһ��
        fgets(line, 128, fp);
        //�ж��ļ��Ƿ����
        
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
//����ͳ�ƶ�����
int file_count() {
    FILE* fp = fopen("./demo5.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    
    int count = 0;

    while (1)
    {
        char line[128] = { 0 };
        //��ȡÿһ������
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
    //��ȡ�ļ�����
    int line_cnt = file_count();
    printf("line count = %d\n", line_cnt);
    //�����ļ���������stringָ������

    char** lines = malloc(sizeof(char*) * line_cnt);
    //�ڴ�ͷ���ж�ȡ�ļ����ݣ� �������ݳ��ȿ��ٿռ䣬���洢�ռ�
    FILE* fp = fopen("./demo5.txt", "r");
    if (fp == NULL) {
        return;
    }
    int idx = 0;
    while (1) {
        char content[128] = { 0 };
        //��ȡÿһ������
        fgets(content, 128, fp);

        if (feof(fp)) {
            break;
        }
        //���㵱ǰ�ַ����ĳ���
        int len = strlen(content) + 1; // +1 == +'\0'
        //���ַ���ָ�뿪�ٿռ�
        lines[idx] = malloc(len);
        //��������
        strcpy(lines[idx], content);
        //�ۼ��±�
        ++idx;
    
    }

    fclose(fp);
    fp = NULL;
    //��ӡ�ļ�����
    for (int i = 0; i < line_cnt; i++)
    {
        printf("%s", lines[i]);
    }
    //�ͷŶ��ڴ�ռ�

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

    //���ж����� 10+20
    while (1)
    {
        char line[64] = { 0 };
        fgets(line, 64, fp);

        if (feof(fp)) {
            break;
        }
        char* p= strchr(line, '+');  //��+��

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


//���д
#if 0
struct Person {
    char name[32];
    int age;
};
void test01() {
    //�����ṹ�����
    struct Person person = { "Obama", 50 };
    //����д�뵽�ļ��У�����2���Ƶ�
    //�������ڴ��ж�����2���Ƶķ�ʽ�洢��
    //�����������ڴ��е��ֽڣ�һ��һ����д���ļ���
    FILE* fp = fopen("./demo7.txt", "wb");
    if (fp == NULL) {
        return;
    }
                                      //��fp����д
    fwrite(&person,sizeof(struct Person), 1, fp);


    fclose(fp);
    fp = NULL;
}
void test02() {
    FILE* fp = fopen("./demo7.txt", "rb");
    if (fp == NULL) {
        return;
    }
    //����person��С�Ŀռ�
    struct Person p = {0};
                                    //��fp�����
    fread(&p, sizeof(struct Person),1, fp);


    fclose(fp);
    fp = NULL;

}

void test03() {
    //����person���飬���ҽ�����洢���ļ���
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

//����ļ���д
#if 0
struct Person {
    char name[32];
    int age;
};
void test01() {
    //����person���飬���ҽ�����洢���ļ���
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
    //�ƶ�ָ�뵽�ڶ���Person�����׵�ַ
    long pos = ftell(fp);
    fseek(fp, sizeof(struct Person), SEEK_SET);//ָ��trump
    //����������������
    struct Person ps= { 0 };
                //ƫ��һ���ṹ������ֽ�(36)         
    fread(&ps, sizeof(struct Person), 1, fp);
    printf("%s %d\n", ps.name, ps.age); //�����ָ��clinton
    
    fread(&ps, sizeof(struct Person), 1, fp); //��clinton
    printf("%s %d\n", ps.name, ps.age);

    int offset = sizeof(struct Person);//�������޷��ű�������ת��
    fseek(fp, -offset, SEEK_CUR); //����trump
    fread(&ps, sizeof(struct Person), 1, fp); //��trump
    printf("%s %d\n", ps.name, ps.age);

    //fseek(fp, 0, SEEK_SET);//�ص���ʼλ��1
    //frewind(fp);//�ص���ʼλ��2


    fclose(fp);
    fp = NULL;

}
void test03() {
    //��ȡ�ļ���С
    FILE* fp = fopen("./demo8.txt", "rb");
    if (fp == NULL) {
        return;
    }
    //���ļ�ָ���Ƶ��ļ�ĩβ���Ϳ���
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp); //�ļ���С108�ֽ�
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
 //1.����ָ�벻��ָ��Ƕ������ڴ�
 //2.��ָ�����ͷ�֮ǰ�������¸�ֵ
 //3.���ڴ��ͷ�֮����Ȼʹ�ö�ָ��
 //4.��ָ���ַ�޸ĺ��޷���free
 //5.malloc(0)ʱ��������ʹ�øÿռ�

 //1.����ָ�벻��ָ��Ƕ������ڴ�
void test01() {
    //1.ջ����
    int a = 10;
    int* p = &a;
    //free(p);//�����ͷ�

    //�ַ�������
    char* s = "hello world";
    //free(s);//�����ͷ�

    //ȫ�ֱ���
    int* gp = &g_a;
   //free(gp); ////�����ͷ�
}
//2.��ָ�����ͷ�֮ǰ�������¸����¿ռ�
void test02() {
    int* p = (int*)malloc(sizeof(int));//���¸�ֵ ����ڴ����ʧ
    *p = 100;
    p = (int*)malloc(sizeof(int));
}
//3.���ڴ��ͷ�֮����Ȼʹ�ö�ָ��
void test03() {
    int* p = (int*)malloc(sizeof(int));
    *p = 100;
    free(p);
    //�ڴ���գ�ʹ��Ȩ�Ѿ�����������
    //��Ȼû�б���ԭ������ʹ����
    *p = 200;
    printf("*p = %d\n", *p);
}
//4.��ָ���ַ�޸ĺ��޷���free
void test04() {
    int* p = (int*)malloc(sizeof(int)*10);
    p = p + 1;
    free(p); //free��ʱ��һ��Ҫ�õ��ռ��׵�ַ
             //������Ȼ������40���ֽڣ���ʵ���ϣ�������ڴ����40��������44
             //�������4���ֽ����ڴ洢�ѿռ��С
}
//5.malloc(0)ʱ��������ʹ�øÿռ�
void test05() {
    int* p = malloc(0); //���ǿ�ָ��
    printf("%p", p);
}
#include "Header.h"
int main(void)
{

    return 0;
}
#endif 
