#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 0, right = 0;
    long long currentSum = 0;
    int count = 0;

    while (right < n) {
        currentSum += a[right]; // ���󴰿�
        while (currentSum > m && left <= right) {
            currentSum -= a[left]; // ��С����
            left++;
        }
        if (currentSum == m) {
            count++; // �ҵ����������Ĵ���
        }
        right++;
    }

    printf("%d\n", count);

    free(a);
    return 0;
}
