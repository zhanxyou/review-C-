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
//arg2: stdout ��׼�������Ļ
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
//  (a=10)|00001010|  0133F700	1���ֽ�
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
#include "Header.h" //#include files....
int main(void)
{
    int a = 345;
    void* p;   //δָ������
    p = &a;
    printf("%d", *((int*)p)); //��(p��ַ)ǿת��int*����

    char ch = 'a';
    void* p1;
    p1 = &ch;
    printf("%c", *(char*)p1);

	return 0;
}



