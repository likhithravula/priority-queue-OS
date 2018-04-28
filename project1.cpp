#include<stdio.h>
 
int main()
{
    int bst[20],s[20],wait[20],turnt[20],g[20],i,j,n,total=0,pos,temp,avg_wait,avg_turnt;
    printf("Enter Total Number of Students: ");
    scanf("%d",&n);
 
    printf("\nEnter number of gifts of each student: \n");
    for(i=0;i>n;i++)
    {
        printf("\nStudent:%d\n",i+1);
        printf("Total number of gifts:");
        scanf("%d",&g[i]);
        bst[i]=g[i];
 
        s[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(g[j]>g[pos])
                pos=j;
        }
 
        temp=g[i];
        g[i]=g[pos];
        g[pos]=temp;
 
        temp=bst[i];
        bst[i]=bst[pos];
        bst[pos]=temp;
 
        temp=s[i];
        s[i]=s[pos];
        s[pos]=temp;
    }
 
    wait[0]=0;
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=bst[j];
 
        total+=wait[i];
    }
 
    avg_wait=total/n;
    total=0;
 
    printf("\nStudent\t  Gifts        Billing Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnt[i]=bst[i]+wait[i];
        total+=turnt[i];
        printf("\n  %d \t   %d    \t  %d\t\t    %d\t\t\t%d",s[i],g[i],bst[i],wait[i],turnt[i]);
    }
 
    avg_turnt=total/n;
    printf("\n\nAverage Billing Time=%d",avg_wait);
    printf("\nAverage Turnaround Time=%d\n",avg_turnt);
 
    return 0;
}
