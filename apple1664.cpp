#include<stdio.h>
//����ʽ�õ����㷨��ʵ�֣���ʹ�����������Ƹ������
//place[n][m]����n��ƻ�����ڲ�����m��ƻ�����������
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
/*  �ݹ��㷨 
int place(int n,int m)  //�ú���Ϊ��n��ƻ�����ڲ�����m�������� 
{
	if(n<=1||m<=1) return 1;
	else if(n<m)  return place(n,n);  //��n<m,���ǽ�n��ƻ������n�������� 
	else return place(n,m-1)+place(n-m,m);  //��n>=m����ɷ�Ϊ�����������
	//һ����ȷ���ŵ�m���������ÿ�������ﶼҪ��һ����Ȼ��ʣn-m���������ηŵ�������m��������
	//һ���ǽ�n��ƻ���ŵ�m-1�������� 
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
