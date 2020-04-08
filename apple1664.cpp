#include<stdio.h>
//将公式用递推算法来实现，即使用数组来递推各个情况
//place[n][m]代表将n个苹果放在不多于m个苹果的情况个数
int place[11][11]; 
int main(void)
{
	int t,m,n,i,j;
	scanf("%d",&t); 
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			if(i<=1||j<=1) place[i][j]=1;
			else if(i<j)  place[i][j]=place[i][i];
			else place[i][j]=place[i-j][j]+place[i][j-1];
		}
	}
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",place[n][m]);
	}
	return 0;
}
/*  递归算法 
int place(int n,int m)  //该函数为将n个苹果放在不大于m个盘子里 
{
	if(n<=1||m<=1) return 1;
	else if(n<m)  return place(n,n);  //若n<m,则还是将n个苹果放在n个盘子里 
	else return place(n,m-1)+place(n-m,m);  //若n>=m，则可分为这两种情况，
	//一种是确定放到m个盘子里，则每个盘子里都要放一个，然后还剩n-m个，再依次放到不大于m个盘子里
	//一种是将n个苹果放到m-1个盘子里 
}
int main(void)
{
	int i,t,m,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",place(n,m));
	}
	return 0;
}  */
