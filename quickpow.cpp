#include<stdio.h>
#include<math.h> 
int quickpow(int base,int index)  
//通过把原指数转换为2的幂之和即转换为二进制数，从而形成二叉树的相乘结构，使得时间复杂度为O(log2n) 
{
	int res=1;  // 第一个底数幂为2的0次方即为1 
	while(index)  //index为0即为二进制数的各位都已运算完毕 
	{
		if(index&1==1) res*=base;   //若该指数的改为二进制数为1则累乘，否则不乘 
		base*=base;   //不断对底数累乘，且是2的指数次的累成，即为形成每个二进制位的指数
		index>>=1;  //不断为指数右移即除二，即算有多少位二进制数 
	}
	return res;
}
int main(void)
{
	printf("%f %d",pow(2,10),quickpow(2,10));
	return 0;
} 
