#include <stdio.h>
int main()
{
   
int i,n,count=0,time_quantum,t=0,at[10],bt[10],rem_bt[10],wt[10],tat[10],flag=0;
float total_wt=0 , total_tat=0;
printf("Enter Total Processes:\t ");
scanf("%d",&n);
for(i=0;i<n;i++)
{ 
printf("Enter Burst Time for Process %d :",i+1);
scanf("%d",&bt[i]); 
}
printf("Enter Time Quantum:\t");
scanf("%d",&time_quantum);
for (i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
t = 0; 
while (1) 
{ 
flag=1; 
for (i = 0 ; i < n; i++) 
{   
if (rem_bt[i] > 0) 
{  
flag=0;
  if (rem_bt[i] > time_quantum)  
  { 
 t += time_quantum; 
  rem_bt[i] = rem_bt[i]-time_quantum;
  }  

else
{  
  t = t + rem_bt[i];    
  wt[i] = t - bt[i]; 
   rem_bt[i] = 0; 
}
} 
}
if (flag==1) 
break;
} 
for (i = 0; i < n ; i++)
 tat[i] = bt[i] + wt[i];
printf("\n Process  BT\t WT\t TAT \n");
for(i=0;i<n;i++) 
printf("\n %d \t %d \t %d \t %d \t",i+1,bt[i],wt[i],tat[i]);
for (i = 0; i < n ; i++)
{ 
total_wt= total_wt+wt[i];
total_tat= total_tat+tat[i]; 
}
printf("\nAverage waiting time = %f",  total_wt/n);
printf ("\nAverage turn around time = %f",total_tat/n);
} 

