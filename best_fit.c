#include<stdio.h>
#include<stdlib.h>

struct pro
{
	int s,m,v;
};
void FF(int ps,struct pro p[],int bs,struct pro b[])
{
	int i,j,min,m;
	for(i=1;i<=ps;i++)
	{
		min=9999,m=-1;
		for(j=1;j<=bs;j++)
		{
			if(p[i].m<=b[j].m && b[j].m<min && b[j].v==-1)
			{
				m=j;
				min=b[j].m;

			}
		}
		if(m!=-1)
		{
			b[m].s = p[i].s;
			b[m].v = p[i].v = 0;
		}
		
	}
}

void main()
{
	int ps,bs,i,j;
	printf("Enter the no of process=");
	scanf("%d",&ps);
	struct pro *p;
    	p=(struct pro*)malloc(ps*sizeof(struct pro));
	printf("Enter process memory\n");
	for(i=1;i<=ps;i++)
	{
		p[i].s=i;
		scanf("%d",&p[i].m);
		p[i].v=-1;
	}
	printf("Enter the no of blocks=");
	scanf("%d",&bs);
	struct pro *b;
    	b=(struct pro*)malloc(bs*sizeof(struct pro));
	printf("Enter block memory\n");
	for(j=1;j<=bs;j++)
	{
		b[j].s=0;
		scanf("%d",&b[j].m);
		b[j].v=-1;
	}
	FF(ps,p,bs,b);
	printf("Process order\n");
	for(i=1;i<=bs;i++)
	{
		printf("%d\t",b[i].s);
	}
	printf("\nWaiting process\n");
	for(j=1;j<=ps;j++)
	{
		if(p[j].v==-1)
		{
			printf("%d\t",p[j].s);
		}
	}
}		
