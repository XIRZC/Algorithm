#include<stdio.h>
#include<math.h>
int y[100001]={0};
int count;
int Partition(int *array,int low,int high)
{
    int pivotKey=array[low];
    array[0]=array[low];
    while(low<high)
    {
        while(low<high&&array[high]>=pivotKey) high--;
        array[low]=array[high];
        while(low<high&&array[low]<=pivotKey)  low++;
        array[high]=array[low];
    }
    array[low]=array[0];
    return low;
}
void QSort(int *array,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(array,low,high);
        QSort(array,low,pivot-1);
        QSort(array,pivot+1,high);
    }
}
void QuickSort(int *array)
{
    QSort(array,1,count);
}
int main(void)
{
	int i,x,ans=0,mid;
	scanf("%d",&count);
	for(i=1;i<=count;i++)
	{
		scanf("%d %d",&x,&y[i]);
	}
	QuickSort(y);
	if(count%2==1)  mid=y[count/2+1];
	else mid=(y[count/2]+y[count/2+1])/2;
	for(i=1;i<=count;i++)
	{
		ans+=abs(y[i]-mid);
	}
	printf("%d",ans);
	return 0;
}
