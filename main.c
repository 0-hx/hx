#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef struct
{
    KeyType Key;
}LineList;
//��������
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
//���
void OutList(LineList r[],int n)
{
    int i;
    printf("�����ļ�¼Ϊ��");
    for(i=1;i<=n;i++)
    {
        printf("%5d",r[i]);
    }
}
void IntList(LineList r[],int k)
{
    int n,i;
    n=k;
    printf("������%d��������",n);
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
    printf("������������ĳ��ȣ�");
    scanf("%d",&n);
    IntList(r,n);
    QuickSort(r,1,n);
    printf("\n���п�������\n");
    OutList(r,n);
    return 0;
}
