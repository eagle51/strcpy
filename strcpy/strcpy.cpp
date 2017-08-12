#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ʵ����������ڴ��ص��ͻ������mystrcpy(Src+1,Src);'\0'���ڱ����ǵ��³�����ѭ��
char *mystrcpy(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL));

	char * address = strDest;
	while ((*strDest++ = *strSrc++) != '\0')
		;
	return address;
}

//�����ڴ��ص����ַ�����������
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
			*d-- = *s--;//vs2017 win10 ���е��˴������⵫����ʾ����vs2010 win7��ʾ�ڴ�壺ͻ
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