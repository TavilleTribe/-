#include <stdio.h>
#include <string.h>

int main()
{
	
	int find(char * str, char * strFind);
	void replace(char * str, char * strFind, char * strReplace);
	
	char str[101], strFind[101], strReplace[101];
	
	int findPos;
	
	// ����ԭʼ�ַ���
	gets(str);
	
	// ����Ҫ���ҵ��ַ���
	gets(strFind);
	
	// ����Ҫ�滻���ַ���
	gets(strReplace);
	
	findPos = find(str, strFind);
	
	if(findPos != -1)
	{
	    // ������ҵ���λ��
	    printf("%d\n", findPos);
	    // �����滻������ֱ��Ӱ�� str
		replace(str, strFind, strReplace);
		printf("%s", str);
	}
	else {
		printf("-1");
	}
	
	return 0;
}

// str Ϊԭʼ�ַ�����strFindΪҪ���ҵ��ַ���
// ����ֵΪstrFind��str�е���ʼλ�ã���������ڣ��뷵��-1
// ע�⣺ֻ���ҵ�һ�γ��ֵ�λ��
int find(char * str, char * strFind)
{
	// �벹������Ĵ���
	int cmp,temp,strl = strlen(str),strf = strlen(strFind);
	for (int i = 0;i < strl;i++) {
		temp = i,cmp = 1;
		for (int k = 0;k < strf;k++) {
			if (i+strf >= strl) {
				return -1;
			}
			if (str[i+k] != strFind[k]) {
				cmp = 0;
				break;
			}
		}
		if (cmp == 1) {
			return temp;
		}
	}
	return -1;
}

// �滻������ֱ��Ӱ��ԭʼ�ַ��� str
void replace(char * str, char * strFind, char * strReplace)
{
	// �벹������Ĵ���
	int move = strlen(strReplace) - strlen(strFind),
	strl = strlen(str),
	strf = strlen(strFind),f = find(str,strFind),
	strr = strlen(strReplace);
	for (int i = strl;i >= strf+f;i--) {
		str[i+move] = str[i];
	}
	for (int i = 0;i < strr;i++) {
		str[f+i] = strReplace[i];
	}
}
