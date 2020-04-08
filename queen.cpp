//递归调用回溯法解决八皇后问题 
#include<stdio.h>    
int queue[8]={-1};  //每行的皇后放的列数，-1代表还未放 
int count=0;  //全局变量用来计算有多少中情况 
int available(int row,int col)  //判断改行该列的皇后放置的位置是否不可取
{
	for(int i=0;i<8;i++)  //这里注意row和col均从1开始的 
	{
		if(col==queue[i])  //代表该列与其他行有冲突
			return 0;
		if(col-row==queue[i]-(i+1)) //代表主对角线有冲突
			return 0;
		if(col-row+queue[i]-(i+1)==0)  //代表副对角线有冲突
			return 0; 
	}
	return 1;
}
void placequeue(int row)
{
	for(int col=1;col<=8;col++)  //对该行的每一列测试 
	{
		if(available(row,col))
		{
			queue[row-1]=col;
			if(row==8)
			{
				count++;  //一种完整情况遍历完则种数加1
				return;  //返回到上一级调用在循环中测试上一行的下一列 
			}
			else  //若一种情况还未结束，则开始调用放置下一行 
			{
				placequeue(row+1);
			}
		}
	}  
	//若改行每列都行不通，则要回溯到上一级，并抹去上一级的放置列数，重回上一级的列数循环开始下一行的测试 
	queue[row-1-1]=-1;  //抹去上一级的列数
	return;   //返回上一级试下一列 
	
} 
int main(void)
{
	placequeue(1);  //从第一行开始测试 
	printf("%d",count);
	return 0;
} 
