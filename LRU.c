#include<stdio.h>
int main()
{
	int n,no,p=0;
	printf("enter no of pages ");
	scanf("%d",&n);
	int a[n];
	int flag[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		flag[i]=0;
	}
	printf("enter the no of frames ");
	scanf("%d",&no);
	int frame[no];
	int count[no];
	for(int i=0;i<no;i++)
	{	
		count[i]=0;
		frame[i]=-1;
	}
	int j=0,next=1,min;
	for(int i=0;i<n;i++)
	{
		for(j=0;j<no;j++)
		{
			if(frame[j]==a[i])
			{
				flag[i]=1;
				count[j]=next;
				next++;
			}
		}
		if(flag[i]==0)
		{	
			if(i<no)
			{
				frame[i]=a[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(j=1;j<no;j++)
				{
					if(count[min]>count[j])
						min=j;
				}
					frame[min]=a[i];
					count[min]=next;
					next++;
			}
		p++;
		}
	}
	printf(" no of page faults %d",p);
} 
