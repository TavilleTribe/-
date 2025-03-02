#include <stdio.h>

long long fastPower(long long a,long long n,long long mod) {
    long long result = 1;
    //��ס��������һ�㶼���ⲽ��С�������ļ��㣬��Ϊ��������ܴ�
	//�ټ��ϱ���� a��b�η���ģp ������Ҫ�мǣ���ԭ��������ģ���ٴΣ�������ɲ���Ӱ�� 
    a %= mod; 
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % mod;
            //����һ�������������������ѭ��һ��ʼ�Ǵκ����һ��ѭ���ǴΡ��൱�ڽ���ż�������һ��a 
            //��С��ģ 
        }
        a  = (a * a) % mod;
        //��С��ģ 
        n >>= 1;
    }
    return result % mod;
}

int main() {
    int n;
    scanf("%d",&n);
    long long result[n];
    long long a;
    for (int i = 0;i < n;i++) {
        scanf("%lld",&a);
        result[i] = fastPower(2,a,1000000007) - 1;
    }
    for (int i = 0;i < n;i++) {
        printf("%lld\n",result[i]);
    }
}
