//�ݹ���û��ݷ�����˻ʺ����� 
#include<stdio.h>    
int queue[8]={-1};  //ÿ�еĻʺ�ŵ�������-1����δ�� 
int count=0;  //ȫ�ֱ������������ж�������� 
int available(int row,int col)  //�жϸ��и��еĻʺ���õ�λ���Ƿ񲻿�ȡ
{
	for(int i=0;i<8;i++)  //����ע��row��col����1��ʼ�� 
	{
		if(col==queue[i])  //����������������г�ͻ
			return 0;
		if(col-row==queue[i]-(i+1)) //�������Խ����г�ͻ
			return 0;
		if(col-row+queue[i]-(i+1)==0)  //�����Խ����г�ͻ
			return 0; 
	}
	return 1;
}
void placequeue(int row)
{
	for(int col=1;col<=8;col++)  //�Ը��е�ÿһ�в��� 
	{
		if(available(row,col))
		{
			queue[row-1]=col;
			if(row==8)
			{
				count++;  //һ�����������������������1
				return;  //���ص���һ��������ѭ���в�����һ�е���һ�� 
			}
			else  //��һ�������δ��������ʼ���÷�����һ�� 
			{
				placequeue(row+1);
			}
		}
	}  
	//������ÿ�ж��в�ͨ����Ҫ���ݵ���һ������Ĩȥ��һ���ķ����������ػ���һ��������ѭ����ʼ��һ�еĲ��� 
	queue[row-1-1]=-1;  //Ĩȥ��һ��������
	return;   //������һ������һ�� 
	
} 
int main(void)
{
	placequeue(1);  //�ӵ�һ�п�ʼ���� 
	printf("%d",count);
	return 0;
} 
