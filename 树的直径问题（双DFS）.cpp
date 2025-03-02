#include<stdio.h>
int n,m,x,y;
int h[100005],vis[100005];
long long ans,z;

long long max(long long x,long long y)
{
	if(x>y)
		return x;
	return y;
}

//�ڽӱ��ͼ
struct Edge{
	int ne,to;
	long long w;
}edge[200005];//����ߣ���������С

int idx;

void add(int x,int y,long long z)
{
	edge[++idx].ne=h[x];
	edge[idx].to=y;
	edge[idx].w=z;
	h[x]=idx;
}

int qd,mx;

void dfs(int x,int f,long long d)//��ǰ���䣬��һ�����䣬��ǰ�ռ��Ľ��
{
	vis[x]=1;//����������ϱ��
	if(d>mx)//�ҵ�һ��·���ռ��Ľ�Ҹ���
	{
		qd=x;//������
		mx=d;//���½��
	}
	for(int i=h[x];i;i=edge[i].ne)
		if(edge[i].to!=f)//��������
			dfs(edge[i].to,x,d+edge[i].w);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
	scanf("%d %d %lld",&x,&y,&z);
	add(x,y,z);
	add(y,x,z);
	}
	for(int i=1;i<=n;i++)
	{
	if(!vis[i])//��û�����������
		{
		mx=0;
		qd=i;//�ȼ��� i Ϊһ��
		dfs(qd,0,0);
		//�����һ�� dfs ��qd ���Ϊֱ����һ��
		dfs(qd,0,0);
		ans=max(ans,mx);
		}
	}
	printf("%lld",ans);
	return 0;
}
