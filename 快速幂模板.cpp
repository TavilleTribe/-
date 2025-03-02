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
    long long a,n,mod;
    scanf("%lld %lld %lld",&a,&n,&mod);
    printf("%lld",fastPower(a,n,mod));
}
