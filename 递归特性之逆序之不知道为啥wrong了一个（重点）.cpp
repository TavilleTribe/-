//ʧ�ܵķ��������һ��wrong�ˣ�ͨ��ȫ������ķ�ʽ�洢Ȼ�����򣬲�֪��Ϊʲô���� 
/*
#include <stdio.h>

int arr[100];
int c = 0;

void initArray() {
	for (int i = 0;i < 100;i++) {
		arr[i] = -1;
	}
}

void getScale(int demical,int scale) {
	if (demical / scale != 0) {
		arr[c++] = demical % scale;
		getScale(demical / scale,scale);
	}
	else {
		arr[c] = demical % scale;
	}
}

int len(int a[100]) {
	int l = 0;
	for (int i = 0;a[i] != -1;i++) {
		l++;
	}
	return l;
}

char getHex(int demical) {
	return demical + 55;
}

int main() {
	int d,s;
	initArray(); 
	scanf("%d %d",&d,&s);
	getScale(d,s);
	for (int i = len(arr) - 1;i >= 0;i--) {
		if (arr[i] >= 10 && s == 16) {
			printf("%c",getHex(arr[i]));
		}
		else {
			printf("%d",arr[i]);
		}
	}
}

*/

//�ɹ��ķ�����ͨ������˽�ݹ��ԭ����֪��Ҫ�ڵݹ������򣬾�Ҫ������ŵ���������ͻ���֣�ÿ�εݹ������Ż������һ�εݹ飬��������ͷ�Ļ���������� 
#include <stdio.h>

char getHex(int demical) {
	return demical + 55;
}

//�ݹ��е��������������һ�εݹ����ǰǰһ�ζ�����������һ�����޷��ﵽ����Դ�����������Ŀ�ġ� 
void getScale(int demical,int scale) {
	if (demical / scale != 0) {
		getScale(demical / scale,scale);
	}
	else {
		;
	}
	if (demical % scale >= 10) {
		printf("%c",getHex(demical % scale));
	}
	else {
		printf("%d",demical % scale);
	}	
}

int main() {
	int d,s;
	scanf("%d %d",&d,&s);
	getScale(d,s);
}
