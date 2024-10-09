#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

//strcpy
//char* my_strcpy(char* dest,const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	//����srcָ����ַ�����destָ��Ŀռ䣬������\0��
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//����Ŀ�ĵؿռ��ַ
//	return ret;
//	/*while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;*/
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bde";
//	my_strcpy(arr1,arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//strcat
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "abcde\0xxxxxxx";
//
//	char arr2[] = "zxc";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//strcmp
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "abc";
//	int ret = my_strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}

//strncpy
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	char* ret = dest;
//	while (count && (*dest++ = *src++))
//		count--;
//	if (count)
//		while (--count)
//			*dest++ = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[15] = "abcd";
//	char arr2[] = "q";
//	//����ĸ�����\0����
//	my_strncpy(arr1, arr2,3);
//	printf("%s\n", arr1);
//	return 0;
//}

//strncat������ĸ������ò��룬\0�ͽ�ֹ
//char* my_strncat(char* dest, char* src, size_t count)
//{
//	char* ret = dest;
//	while (*dest++)
//		;
//	dest--;
//	while (count--)
//		//ÿ��ѭ������ִ��if������\0�����if�������,ֱ�ӷ���
//		if (!(*dest++ = *src++))
//			return ret;
//	//δ�ҵ�\0���Զ���\0
//	*dest = '\0';
//	return ret;
//
//}
//
//int main()
//{
//	char arr1[15] = "abcd\0xxxxxxxxx";
//	char arr2[8] = "zxc";
//	my_strncat(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}

//strstr
//KMP�㷨
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1 && str2);
	//����str1��str2ָ�룬��s1��s2ȥ�Ƚ�
	char* s1 = (char*)str1;
	char* s2 = (char*)str2;
	char* cur = (char*)str1;
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)str2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;

}
int main()
{
	char* p1 = "abbbbcdefzxc";
	char* p2 = "bbc";
	char* ret = my_strstr(p1, p2);
	//char* ret = strstr(p1, p2);
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);
	return 0;
}