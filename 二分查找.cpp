#include <stdio.h>

int binary_search(int *arr, int length, int key) {
	int start = 0;
	int end = length - 1;
	int ret = -1;  // δ���������ݷ���-1�±�
	int mid;
	while (start <= end) {
		mid = start + ((end - start) >> 1);  // ֱ��ƽ�����ܻ����������������㷨
		if (arr[mid] < key)
	    	start = mid + 1;
		else if (arr[mid] > key)
	    	end = mid - 1;
		else {  // ������������Ϊ��������������Ǵ��ھ���С��
	    	ret = mid;
	    	break;
		}
	}
	return ret;  // ��һ����
}

int main() {
	int nums[10] = {1,3,5,7,9,11,13,15,17,19};
	printf("%d",binary_search(nums,10,9));
}

