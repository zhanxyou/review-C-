#include "Header.h"

#include "Header.h"
int is_palindrome(char* str) {
	if (!str)
		return -1;

	char* start = str;
	char* end = str + strlen(str) - 1;
	while (start<end)
	{
		if (*start != *end)
			return -1;
		start++;
		end--;
	}
	return 1;
}
void inverse(char* str) {
	if (!str)
		return;

	char* start = str;
	char* end = str + strlen(str) - 1;
	char temp;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
int str_cmp(const char* s1, const char* s2) {

	while (*s1 == *s2) {
		if (*s1== '\0')
			return 0;
		s1++;
		s2++;
	}

	return *s1 > *s2 ? 1 : -1;
	
}
int str_n_cmp(const char* s1, const char* s2, size_t n) {
	int i = 0;
	while (*s1 == *s2) {
		if (i==n || *s1 == '\0')
			return 0;
		i++;
		s1++;
		s2++;
	}

	return *s1 > *s2 ? 1 : -1;

}
char* str_copy(char* dest, const char* src) {
	if (!dest || !src)
		return NULL;

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	return dest;
}

char* str_n_copy(char* dest, const char* src, size_t n) {
	if (!dest || !src)
		return NULL;

	for (size_t i = 0; i < n; i++)
	{
		*(dest+i) = *(src+i);
	}

	return dest;
}
char* str_cat(char* dest, const char* src) {
	char* temp = dest+ strlen(dest);
	while (*src != '\0') {
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';
	return temp;

}
char* str_n_cat(char* dest, const char* src, size_t n) {
	char* temp = dest + strlen(dest);
	size_t i = 0;
	while (*src != '\0') {
		if (i == n)
			break;
		*temp = *src;
		i++;
		temp++;
		src++;
	}
	*temp = '\0';
	return temp;

}
char* str_char(char* str, char ch) {

	while (*str) {
		if (*str == ch)
			return str;
		str++;
	}
	return NULL;
}

char* str_substr(char* str, char* substr) {
	char* p = str;	
	char* q = substr;	
	char* tmp = str;	//用于回滚

	while (*p) {
		tmp = p;
		while (*p == *q && *p != '\0') {
			p++;
			q++;
		}
		if (*q == '\0') {
			return tmp;
		}
		p = tmp;	//回滚
		q = substr;
		p++;		
	}
	return NULL;
}
int main01(void)
{
	//回文函数实现
	/*char str[] = "level";
	int p = is_palindrome(str);
	printf("%d", p);*/

	//string逆置
	/*char str[] = "abcd";
	inverse(str);
	printf("%s", str);*/

	//strcmp
	/*char str1[] = "hello like";
	char str2[] = "hello mike";
	int p = str_cmp(str1, str2);
	printf("%d", p);*/

	//strncmp
	/*char str1[] = "hello like";
	char str2[] = "hello mike";
	int p = str_n_cmp(str1, str2, 7);
	printf("%d", p);*/

	//strcpy
	/*char src[] = "hello world";
	char dest[100] = { 0 };
	str_copy(dest, src);
	printf("%s", dest);*/

	//strncpy
	//char src[] = "hello world";
	//char dest[100] = { 0 };
	//str_n_copy(dest, src, 4);
	//printf("%s", dest);

	//strcat
	/*char src[] = "world";
	char dest[] = "hello";
	str_cat(dest, src);
	printf("%s", dest);*/

	//strncat
	/*char src[] = "world";
	char dest[] = "hello";
	str_n_cat(dest, src, 3);
	printf("%s", dest);*/

	//strchr
	/*char str[] = "hello world";
	char ch = 'o';
	char* p = str_char(str, ch);
	printf("%s", p);*/

	//strstr
	/*char str[] = "helhelllolo world";
	char substr[] = "llo";
	char* p = str_substr(str, substr);
	printf("%s", p);*/

	return 0;
}
//---------------------------用于source.c-------------------//
//static int a = 100;
//static void foo(void) {
//	printf("%d", 10);
//}