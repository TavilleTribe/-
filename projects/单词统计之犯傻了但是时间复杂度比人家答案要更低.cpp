#include <stdio.h>
#include <string.h>

int st = -1;

char toLowerCase(char o) {
    if (o >= 'A' && o <= 'Z') {
        return o + 32;
    }
    else {
        return o;
    }
}

int matches(char w[45],char str[10000]) {
    int wl = strlen(w);
    int sl = strlen(str);
    int cl = 0;
    int m = 0;
    for (int i = 0;i < sl;i++) {
        if (toLowerCase(str[i]) == toLowerCase(w[cl])) {
            cl++;
            if (cl == wl) {
            	//���ﷸɵ�ˣ�cl==wl��ʱ����������"totototo To"������������������ʱ��һ����λ�þ���0��,����Ӧ�ð�if�ŵ���������жϵ�����Ŷ�QWQ 
                if ((i - wl == -1 && str[i + 1] == ' ') || (str[i - wl] == ' ' && str[i + 1] == ' ') || (str[i - wl] == ' ' && i+1 == sl)) {
                	if (st == -1) {
            			st = i - wl + 1;
					}
                	m++;
                	cl = 0;
				}
                else {
                	cl = 0;
				}
            }
        }
        else {
            cl = 0;
        }
    }
    if (m == 0) {
    	return -1;
	}
    return m;
}

int main() {
    char words[45];
    char sent[10000];
    gets(words);
    gets(sent);
    int p = matches(words,sent);
    if (p == -1) {
    	printf("-1");
	}
	else {
		printf("%d %d",p,st);
	}
}
