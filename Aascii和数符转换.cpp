#include <stdio.h>
#include <ctype.h>

char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
	char c = '1';int d = 1;
	int num = c - '0';//ȥ'0'Ϊ�� 
	char ch = d + '0';//��'0'Ϊ��
	printf("ASCII��\n");
	for (int i = 0;i < 26;i++) {
		printf("%c:%d\n",alphabet[i],alphabet[i]);
	}
	for (int i = 0;i < 26;i++) {
		printf("%c:%d\n",toupper(alphabet[i]),toupper(alphabet[i]));
	}
}
