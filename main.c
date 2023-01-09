#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef struct
{
    KeyType Key;
}LineList;
//快速排序
void QuickSort(LineList r[],int first,int end)
{
    int i,j;
    LineList temp;
    i=first;
    j=end;
    temp=r[i];
    while(i<j)
    {
        while(i<j&&temp.Key<=r[j].Key)
            j--;
        r[i]=r[j];
        while(i<j&&r[i].Key<=temp.Key)
            i++;
        r[j]=r[i];
    }
    r[i]=temp;
    if(first<i-1)       QuickSort(r,first,i-1);
    if(i+1<end)     QuickSort(r,i+1,end);
}
//输出
void OutList(LineList r[],int n)
{
    int i;
    printf("排序后的记录为：");
    for(i=1;i<=n;i++)
    {
        printf("%5d",r[i]);
    }
}
void IntList(LineList r[],int k)
{
    int n,i;
    n=k;
    printf("请输入%d个整数：",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
    }
    OutList(r,n);
}
int main()
{
    int i,n;
    LineList r[MAXSIZE];
    printf("请输入待排序表的长度：");
    scanf("%d",&n);
    IntList(r,n);
    QuickSort(r,1,n);
    printf("\n进行快速排序，\n");
    OutList(r,n);
    return 0;
}
