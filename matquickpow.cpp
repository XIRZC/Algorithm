// 矩阵快速幂的模板 应用于解决斐波那契数列第n项过大取余后的结果 
#include<stdio.h>
#include<string.h>
#define N 2
#define Mod 998244353
typedef long long ll; 
ll temp[N][N];  //存矩阵相乘结果的临时矩阵 
ll ans[N][N];  //返回矩阵快速幂结果的结果矩阵 
int matMulti(ll mat1[][N],ll mat2[][N],int n)  //n为该方阵的行数或列数
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
 //将矩阵的乘法应用于普通整数快速幂的函数中去从而形成矩阵快速幂 
void matQuickPow(ll mat[][N],int m,ll n)  //n为该方阵的幂数，m为矩阵的行数或列数 
{
	int i;
	memset(ans,0,sizeof ans);
	for(i=0;i<m;i++)
		ans[i][i]=1;  //从单位矩阵开始累乘，第一次乘第一位二进制数对应的单位矩阵 
	while(n)
	{
		if(n&1)  matMulti(ans,mat,m);
		matMulti(mat,mat,m);
		n>>=1;
	}	
} 
int main(void)  
//矩阵快速幂对斐波那契额数列第n项过大整数取余结果的计算过程，从而避免递归调用太多次的过程，从而防止栈溢出 
{
	ll faboup[2][N]={{1,1},{1,0}};  //生成斐波那契数列递推关系式的幂矩阵,即该矩阵乘初始矩阵n-1次即得到fn
	ll init[2][N]={{1},{0}},n;  //初始矩阵 
	scanf("%lld",&n);
	matQuickPow(faboup,2,n-1);
	matMulti(init,faboup,2);  //初始矩阵与幂矩阵相乘 
	printf("%lld",ans[0][0]);
	return 0;
} 

