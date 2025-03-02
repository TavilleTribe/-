#include <stdio.h>

void move(char x,char y) {
    printf("Move %c to %c\n",x,y);
}
//�ص㣬�ݹ� 
int hanoit(unsigned int x) {
 
	if (x > 1) {	
		return 2 * hanoit(x - 1) + 1;
	}
	else if(1 == x) {//�ݹ�����һ�㣬Ҳ����1 == x
	
		return 1;
	}
	else {//����0�㣬����Ҫ��׳
		return 0;
	}
 
}

void hanoi(int n,char one,char two,char three) {
    if (n==1) {
        move(one,three);
    }
    else {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",hanoit(n));
    hanoi(n,'A','B','C');
}
