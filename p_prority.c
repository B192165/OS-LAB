#include<stdio.h>
#include<stdlib.h>

struct process{
	int pri,at,bt,ct,tat,wt,c;
};

int findp(struct process* p,int n,int t)
{
	int min=9999,i,index=-1;
      	for(i=0;i<n;i++)
      	{
      		if(p[i].at<=t && p[i].c==0)
      		{
      			if(p[i].pri<min)
      			{
      				min=p[i].pri;
      				index=i;
			 }
		 }
	 }
		  return index;
}
int main()
{
	int n,i,k=0,t=0,index,ct=0;
	
	printf("enter no of processes");
	scanf("%d",&n);
	int b[n];
	struct process* p;
   p=(struct process *)malloc(n*sizeof(struct process));
   printf("enter the prority,Arival time,burst time");
   for(i=0;i<n;i++)
   {
   	scanf("%d%d%d",&p[i].pri,&p[i].at,&p[i].bt);
   	p[i].c=0;
   }
   for(i=0;i<n;i++)
     b[i]=p[i].bt;
   while(k<n)
   {
   	index=findp(p,n,t);
   	if(index!=-1)
   	{
   		p[index].ct=ct+1;
   		p[index].bt=p[index].bt-1;
   		t=p[index].ct;
   		if(p[index].bt==0)
   		{
   		p[index].c=1;
   		p[index].ct=t;
   		p[index].tat=p[index].ct-p[index].at;
   	            p[index].wt=p[index].tat-b[index];
 
   		k=k+1;
   	     }
   	    ct=t;
   		
	   }
	   else
	   {
	   	t=t+1;
	   	ct=ct+1;
	   }
   }
  
   printf("at\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",p[i].at,b[i],p[i].ct,p[i].tat,p[i].wt);
	}
	int sum=0,sum2=0;
	for(i=0;i<n;i++)
	{
		sum=sum+p[i].tat;
		sum2=sum2+p[i].wt;
	}
	printf("%d is the avg of tat\n",sum/n);
	printf("%d is the avg of wt",sum2/n);
	
   
   
}
