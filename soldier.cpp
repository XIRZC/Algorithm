#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int x[100001]={0};
int y[100001]={0};
int count;
int Partition(int *array,int low,int high)  //快速排序按枢纽分半函数
{
    int pivotKey=array[low];  //枢纽设置，取最低为的值做枢纽
    while(low<high)
    {
    while(low<high&&array[high]>=pivotKey) high--;  //高位游标确认是否高于枢纽
    array[low]=array[high];   //若小于则给低位游标所在地址赋值
    while(low<high&&array[low]<=pivotKey)  low++;  //低位游标确认是否低于枢纽
    array[high]=array[low];  //若大于则给高为游标所在地址赋值
    }
    array[low]=pivotKey;
    return low;  //返回最后枢纽所在的下标
}
int randomPartition(int *array,int low,int high)
{
    int temp;
    srand(time(NULL));  //设置随机种子来使得伪随机数序列不同，需包含time.h和stdlib.h
    int pivot=rand()%(high-low+1)+low;
    //用随机函数生成随机数，%来限定为0到high-low这个范围，+low来使得为low到high这个范围
    temp=array[pivot];array[pivot]=array[low];array[low]=temp;  //与最低位交换值以便后续划分
    return Partition(array,low,high);
}
int randomSelect(int *array,int low,int high,int k)  //随机选择线性函数
{
    if(low==high)  return array[low];   //递归终止条件
    int pivot=randomPartition(array,low,high);  //随机种子划分
    int num=pivot-low+1;  //找出枢纽所对应的有序序列中的序号
    if(num==k)  return array[pivot];  //若相等则返回
    else if(k<num)  randomSelect(array,low,pivot-1,k);  //在左区段继续选择
    else randomSelect(array,pivot+1,high,k-num);  //在右区段继续选择，但要注意这里应将k改为k-num，因为区间缩小了，要找的序号也就要缩小了
}
void QuickSort(int *array,int low,int high)  //快速排序
{
    int pivot;
    if(low<high)  //递归终止条件，排序完成
    {
	    pivot=Partition(array,low,high);   //分块
	    QuickSort(array,low,pivot-1);  //左半块递归按枢纽划分
	    QuickSort(array,pivot+1,high);  //右半块递归按枢纽划分
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
	for(i=1;i<=count;i++)  //转换x方向上的问题
		x[i]=x[i]-i+1;
	midx=randomSelect(x,1,count,(1+count)/2);
	for(i=1;i<=count;i++)
	{
		ans+=abs(x[i]-midx);  //按公式求和
		ans+=abs(y[i]-midy);
	}
	printf("%d",ans);
	return 0;
}
