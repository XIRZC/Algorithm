#include<stdio.h>
#include<math.h> 
int quickpow(int base,int index)  
//ͨ����ԭָ��ת��Ϊ2����֮�ͼ�ת��Ϊ�����������Ӷ��γɶ���������˽ṹ��ʹ��ʱ�临�Ӷ�ΪO(log2n) 
{
	int res=1;  // ��һ��������Ϊ2��0�η���Ϊ1 
	while(index)  //indexΪ0��Ϊ���������ĸ�λ����������� 
	{
		if(index&1==1) res*=base;   //����ָ���ĸ�Ϊ��������Ϊ1���۳ˣ����򲻳� 
		base*=base;   //���϶Ե����۳ˣ�����2��ָ���ε��۳ɣ���Ϊ�γ�ÿ��������λ��ָ��
		index>>=1;  //����Ϊָ�����Ƽ������������ж���λ�������� 
	}
	return res;
}
int main(void)
{
	printf("%f %d",pow(2,10),quickpow(2,10));
	return 0;
} 
