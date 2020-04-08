
#include<stdio.h>
#include <limits.h>
#define Maxn 100005
#define Epsilon 1e-6
#define Maxv INT_MAX
int n,L;   //��������Ҫ�����ٵ�����
int a[Maxn]; //ԭʼ��������
double sum[Maxn];  //ǰ׺������
inline int bin_judge(double mid)
{
	int i;
	double minv=Maxv;
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i]-mid;
		if(i>=L) minv=(minv>sum[i-L]?sum[i-L]:minv);
		if(sum[i]-minv>=0) return 1;
	}
	return 0;
}
int main(void)
{
	int i;
	double left=0,right=2000,mid;
	scanf("%d %d",&n,&L);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(left+Epsilon<right)
	{
		mid=(right+left)/2;
		if(bin_judge(mid))
			left=mid;
		else
			right=mid;
	}
	printf("%d",(int)(right*1000));
	return 0;
}

