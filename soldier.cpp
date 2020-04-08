#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int x[100001]={0};
int y[100001]={0};
int count;
int Partition(int *array,int low,int high)  //����������Ŧ�ְ뺯��
{
    int pivotKey=array[low];  //��Ŧ���ã�ȡ���Ϊ��ֵ����Ŧ
    while(low<high)
    {
    while(low<high&&array[high]>=pivotKey) high--;  //��λ�α�ȷ���Ƿ������Ŧ
    array[low]=array[high];   //��С�������λ�α����ڵ�ַ��ֵ
    while(low<high&&array[low]<=pivotKey)  low++;  //��λ�α�ȷ���Ƿ������Ŧ
    array[high]=array[low];  //�����������Ϊ�α����ڵ�ַ��ֵ
    }
    array[low]=pivotKey;
    return low;  //���������Ŧ���ڵ��±�
}
int randomPartition(int *array,int low,int high)
{
    int temp;
    srand(time(NULL));  //�������������ʹ��α��������в�ͬ�������time.h��stdlib.h
    int pivot=rand()%(high-low+1)+low;
    //��������������������%���޶�Ϊ0��high-low�����Χ��+low��ʹ��Ϊlow��high�����Χ
    temp=array[pivot];array[pivot]=array[low];array[low]=temp;  //�����λ����ֵ�Ա��������
    return Partition(array,low,high);
}
int randomSelect(int *array,int low,int high,int k)  //���ѡ�����Ժ���
{
    if(low==high)  return array[low];   //�ݹ���ֹ����
    int pivot=randomPartition(array,low,high);  //������ӻ���
    int num=pivot-low+1;  //�ҳ���Ŧ����Ӧ�����������е����
    if(num==k)  return array[pivot];  //������򷵻�
    else if(k<num)  randomSelect(array,low,pivot-1,k);  //�������μ���ѡ��
    else randomSelect(array,pivot+1,high,k-num);  //�������μ���ѡ�񣬵�Ҫע������Ӧ��k��Ϊk-num����Ϊ������С�ˣ�Ҫ�ҵ����Ҳ��Ҫ��С��
}
void QuickSort(int *array,int low,int high)  //��������
{
    int pivot;
    if(low<high)  //�ݹ���ֹ�������������
    {
	    pivot=Partition(array,low,high);   //�ֿ�
	    QuickSort(array,low,pivot-1);  //����ݹ鰴��Ŧ����
	    QuickSort(array,pivot+1,high);  //�Ұ��ݹ鰴��Ŧ����
	}
}
int main(void)
{
	int i,ans=0,midx,midy;
	scanf("%d",&count);
	for(i=1;i<=count;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	QuickSort(x,1,count);
	midy=randomSelect(y,1,count,(1+count)/2);
	for(i=1;i<=count;i++)  //ת��x�����ϵ�����
		x[i]=x[i]-i+1;
	midx=randomSelect(x,1,count,(1+count)/2);
	for(i=1;i<=count;i++)
	{
		ans+=abs(x[i]-midx);  //����ʽ���
		ans+=abs(y[i]-midy);
	}
	printf("%d",ans);
	return 0;
}
