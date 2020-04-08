#include<stdio.h>
#define Max 730
#include<math.h>
char mat[Max][Max]={' '};
void toDraw(int x,int y,int n)
{
	int m=(int)pow(3,n-2);  //�ò����һ�Ӳ�ĺз��ε�size 
	if(n==1) mat[x][y]='X';
	else
	{
		toDraw(x,y,n-1);  //�������Ͻǵĺз���
		toDraw(x,y+2*m,n-1);  //�������Ͻǵĺз���
		toDraw(x+m,y+m,n-1);  //�������ĺз���
		toDraw(x+2*m,y,n-1);  //�������½Ǻз���
		toDraw(x+2*m,y+2*m,n-1);  //�������½Ǻз��� 
	}
}
int main(void)
{
	int n,size,i,j;
    while(scanf("%d",&n))
    {
		if(n==-1)
			break;
		size=(int)pow(3,n-1);
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				mat[i][j]=' ';
		}
		toDraw(0,0,n);  
		for(i=0;i<size;i++)
			mat[i][size]='\0';    
		for(i=0;i<size;i++)
			puts(mat[i]);    
		printf("-\n");
	}
	return 0;
} 
