// ��������ݵ�ģ�� Ӧ���ڽ��쳲��������е�n�����ȡ���Ľ�� 
#include<stdio.h>
#include<string.h>
#define N 2
#define Mod 998244353
typedef long long ll; 
ll temp[N][N];  //�������˽������ʱ���� 
ll ans[N][N];  //���ؾ�������ݽ���Ľ������ 
int matMulti(ll mat1[][N],ll mat2[][N],int n)  //nΪ�÷��������������
{
	int i,j,k;
	memset(temp,0,sizeof temp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				temp[i][j]+=(mat1[i][k]*mat2[k][j])%Mod;
			}
			temp[i][j]%=Mod;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mat1[i][j]=temp[i][j];
		}
	}
 } 
 //������ĳ˷�Ӧ������ͨ���������ݵĺ�����ȥ�Ӷ��γɾ�������� 
void matQuickPow(ll mat[][N],int m,ll n)  //nΪ�÷����������mΪ��������������� 
{
	int i;
	memset(ans,0,sizeof ans);
	for(i=0;i<m;i++)
		ans[i][i]=1;  //�ӵ�λ����ʼ�۳ˣ���һ�γ˵�һλ����������Ӧ�ĵ�λ���� 
	while(n)
	{
		if(n&1)  matMulti(ans,mat,m);
		matMulti(mat,mat,m);
		n>>=1;
	}	
} 
int main(void)  
//��������ݶ�쳲����������е�n���������ȡ�����ļ�����̣��Ӷ�����ݹ����̫��εĹ��̣��Ӷ���ֹջ��� 
{
	ll faboup[2][N]={{1,1},{1,0}};  //����쳲��������е��ƹ�ϵʽ���ݾ���,���þ���˳�ʼ����n-1�μ��õ�fn
	ll init[2][N]={{1},{0}},n;  //��ʼ���� 
	scanf("%lld",&n);
	matQuickPow(faboup,2,n-1);
	matMulti(init,faboup,2);  //��ʼ�������ݾ������ 
	printf("%lld",ans[0][0]);
	return 0;
} 

