#include <stdio.h>

int main() {
    char s[100010];
    int arr[123];
    int flag = -1;
    scanf("%s",s);
    for(int i = 0;i <= sizeof(s)/sizeof(char) && s[i] != '\0';i++) {
		arr[s[i]] += 1;
	}
	for (int i = 97;i<=122;i++) {
		if (arr[i] == 1) {
			flag = i;
			break;
		}
	}
	if (flag != -1) {
		printf("%c",flag);
	}
	else {
		printf("no");
	}
}

#include<stdio.h>
#define N 100010
char a[N];
int main()
{
	gets(a);
	int i,j;
	int flag=0;
	for(i=0;a[i];++i){
		for(j=0;a[j];++j){
			if(a[i]==a[j]&&i!=j){
				flag=1;
				break;//������ͬ���ַ���������ǰѭ�������ؽ���֮��ıȽ� 
			}
		}
		if(flag==0){//��flagΪ0ʱ�����a[i]������������ǰѭ�� 
			printf("%c",a[i]);
			break;
		}
		else if(flag==1&&a[i+1]==0)//��flagΪ1��Ϊ���һ��ѭ��ʱ�����"no" 
		{
			printf("no");
		}
		flag=0;//ÿ�αȽ�ǰ�轫flag����Ϊ0 
	}
	return 0;
}
