// ˳����У��ǻ��ζ��У����������㷨

#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef int ElemType;

typedef struct 
{	
    ElemType data[MaxSize];
    // ��ͷ�Ͷ�β�ı��λ
    int front, rear;
} SqQueue;

// ��ʼ������
void InitQueue(SqQueue *&q)
{
    // �벹������Ĵ���
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

// ���ٶ���
void DestroyQueue(SqQueue *&q)			
{
    // �벹������Ĵ���
    free(q);
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q)				
{
    // �벹������Ĵ���
	return q->front == q->rear;
}

// ���
bool enQueue(SqQueue *&q, ElemType e)		
{
    // �벹������Ĵ��룬��ע�ⷵ��ֵ
    // ��Ҫ�ж϶����Ƿ�����
    if (q->rear == MaxSize-1) {
    	return false;
	}
	q->rear = q->rear + 1;
	q->data[q->rear] = e;
	return true;
}

// ����
bool deQueue(SqQueue *&q, ElemType &e)	
{
    // �벹������Ĵ��룬��ע�ⷵ��ֵ
    // ��Ҫ�ж϶����Ƿ�Ϊ��
    if (QueueEmpty(q)) {
    	return false;
	}
	q->front = q->front + 1;
	e = q->data[q->front];
	return true;
}

int main()
{
    int n, num, e;
    char op;
	
    SqQueue * q;
	
    // ��ʼ������
    InitQueue(q);
	
    scanf("%d", &n);
    getchar();
	
    // �Ӽ������� n ����������ע���жϲ�������
    // ͬʱ��ע���� getchar() �����س���
    // �뱻���� for ѭ���еĴ���
    // ���������ݣ������ݲ��������Ͳ�ͬ��������������
    // �������ӣ��뽫 num ���
    // ����ǳ��ӣ� ������Ҫ�и��������ô���Ϊ num
    
    for(int i = 0; i < n; i++)
    {
        // �벹������Ĵ���
        scanf("%c %d",&op,&num);
        if (op == 'i') {
        	enQueue(q,num);
		}
		else if (op == 'o') {
			int time = num;
			for (int i = 0;i < time;i++) {
				deQueue(q,num);
			}
		}
        getchar();
    }
	
    // �����У������
    while(!QueueEmpty(q))
    {
        deQueue(q, e);
        // ����� e Ϊ����Ͳ���
        printf("%d ", e);
    }
    return 0;
}
