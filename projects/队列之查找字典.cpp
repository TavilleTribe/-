#include<stdio.h>

//���ö��������ȳ������ԣ����ڴ浱�ɶ�������
int queue[100000];
//��������
int begin;
//��β����
int end;

//���
void EnQueue(int elem)
{
	queue[end++] = elem;
}

//����
int DeQueue()
{
	return queue[begin++];
}

//���в�ѯ
int Query(int elem)
{
	for(int i=begin;i<end;i++)
	{
		if(queue[i]==elem) return 1;
	}
	return 0;
}

int main()
{
	
	begin = end = 0;
	
	// m �ڴ�����  n ���³���
	int m,n,num,find_count = 0;
	//scanf("%d%d",&m,&n);
	m = 3,n = 7;
	int arr[n] = {1,2,1,3,1,5,6};
	for(int i=0;i<n;i++)
	{
		num = arr[i];
		//scanf("%d",&num);
		//������ڴ�鲻�������ʵ���Ҵ�����һ����Ԫ�����
		if(!Query(num))
		{
			find_count++;
			EnQueue(num);
			//�����ڴ����������׳���
			if(end-begin==m)
				DeQueue();
		}
	}
	printf("%d",find_count);
	return 0;
}
