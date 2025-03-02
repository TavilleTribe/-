#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    for (int i = 2;i <= sqrt(num);i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int getDigit(int num) {
    int t = 0;
    while (num != 0) {
        num /= 10;
        t++;
    }
    return t;
}

int getRev(int num) {
    int digit = getDigit(num),mult,sum = 0;
    int rnum[digit];
    mult = pow(10,digit);
    for (int i = 0;i < digit;i++) {
        rnum[i] = num % 10;
        num /= 10;
    }
    for (int i = 0;i < digit;i++) {
        mult /= 10;
        sum += (rnum[i] * mult);
    }
    return sum;
}

int main() {
	int M,N,flag = 1;
	scanf("%d %d",&M,&N);
	for (int i = M;i<=N;i++) {
		if (isPrime(i) && isPrime(getRev(i))) {
			//ע�����λ�ã�flag���ô���ֹ���������жϣ�Ҳ������Ϊ�жϵ�һ�����������ֵ�ʱ������ʱֻ���%d����������š� 
			if (flag == 1) {
				flag = 0;
				printf("%d",i)
			}
			//����flag����1���Ǿ�Ҫ��������ˣ����� 
			else {
				printf(",%d",i);
			}
		}
	}
	if (flag) {
		printf("No\n");
	}
}


