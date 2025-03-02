#include <stdio.h>
#include <stdlib.h>

// �ڽӱ��еı߽ڵ�
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// �ڽӱ�
struct AdjList {
    struct AdjListNode* head;
};

// ͼ�ṹ
struct Graph {
    int V;
    struct AdjList* array;
};

// �����µı߽ڵ�
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// ����ͼ
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // �����ڽӱ�����
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // ��ʼ��ÿ���ڽӱ�Ϊ��
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// ��ӱ�
void addEdge(struct Graph* graph, int src, int dest) {
    // ��Ӵ�src��dest�ı�
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // ���������ͼ����Ӵ�dest��src�ı�
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// ��ӡͼ
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n ���� %d ���ڽӱ�\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// ������
int main() {
    // ����ͼ
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // ��ӡͼ
    printGraph(graph);

    return 0;
}
