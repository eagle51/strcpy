#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//这种实现如果遇到内存重叠就会出错，如mystrcpy(Src+1,Src);'\0'由于被覆盖导致出现死循环
char *mystrcpy(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL));

	char * address = strDest;
	while ((*strDest++ = *strSrc++) != '\0')
		;
	return address;
}

//考虑内存重叠的字符串拷贝函数
char *mystrcpy2(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL));

	char *ret = strDest;
	char *d, *s;
	int size = 0;
	d = (char *)strDest;
	s = (char *)strSrc;

	size = strlen(strSrc) + 1;
	printf("size = %d\n", size);
	if (strDest >= strSrc && strDest <= strSrc + size) {
		d += size - 1;
		s += size - 1;
		while (size--){
			*d-- = *s--;//vs2017 win10 运行到此处有问题但不提示错误，vs2010 win7提示内存冲：突
		}
	}
	else {
		while (size--)
			*strDest++ = *strSrc++;
	}

	return ret;
}

int main(void)
{
	char *Src = "abcde";
	char Dest[1024] = { 0 };
	char *Dest2 = Src + 2;
	printf("%s\n", Src);
	mystrcpy2(Dest2, Src);
	printf("%s\n", Dest2);
	system("pause");
	return 0;
}