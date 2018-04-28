//Round Robin
#include<stdio.h>
#include<conio.h>
int main()
{
    int Burst[10],Bursth[10],Wait[10],Turnar[10],prior[10];
    int i,j,proc,swit,quan,size,sum,sumwt,sumtat,ttat,temp,count,temp1,temp2,temp3;
    float avgwt=0.0,avgtat=0.0;
    int pr[10];
    j=0;
	size=0; 
	count=0; 
	sum=0; 
	sumwt=0; 
	ttat=0;
	sumtat=0;
    printf("\n\n\n\t\t\t    >>  OS PROJECT <<");
    printf("\n\t\t\t      ======================");
    printf("\n\n   Enter number of processes: ");
    scanf("%d",&proc);
    printf("\n");
    for(i=0;i<proc;i++)
	{
        pr[i]=i+1;
    }
    for(i=0;i<proc;i++)
	{
        printf("\n Enter burst time for Process P%d: ",i+1);
        scanf("%d",&Burst[i]);
        Bursth[i]=Burst[i];
    }
    for(i=0;i<proc;i++)
	{
        printf("\n Enter Priority for Process P%d: ",i+1);
        scanf("%d",&prior[i]);
    }
    printf("\n\n Enter time quantum:");
   scanf("%d",&quan);
    for(i=0;i<proc;i++)
    {
    	for(j=0;j<proc-1;j++)
    	{
    		if(prior[j]>prior[j+1])
    		{
    			temp=prior[j];
    			prior[j]=prior[j+1];
    			prior[j+1]=temp;
    			temp1=Burst[j];
    			Burst[j]=Burst[j+1];
    			Burst[j+1]=temp1;
    			temp2=Bursth[j];
    			Bursth[j]=Bursth[j+1];
    			Bursth[j+1]=temp2;
    			temp3=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp3;
			}
		}
	}
    for(i=0;i<proc;i++)
	{
        if(Bursth[i]%quan== 0)
		{
            swit=Bursth[i]/quan;
        }
        else
		{
			swit=(Bursth[i]/quan)+1;
		}
        size=size+swit;
    }
    int gantch[size],gantproc[size];
    j=0;
    while(1)
	{
        for(i=0,count=0;i<proc;i++)
		{           //
            temp=quan;
            if(Bursth[i]==0)
			{
                count++;
                continue;
            }
            if(Bursth[i]>quan)
			{
                gantch[j]=quan;
                gantproc[j]=pr[i]; 
				j++;
                Bursth[i]=Bursth[i]-quan;
            }
            else if(Bursth[i]>=0)
			{
                if(Bursth[i]==quan)
				{
					gantch[j]=quan; 
					gantproc[j]=pr[i]; 
					j++;
				}
                else
				{
					gantch[j]=Bursth[i];
					gantproc[j]=pr[i]; 
					j++;
				}
                temp=Bursth[i];
                Bursth[i]=0;
            }
            ttat=ttat+temp;
            Turnar[i]=ttat;
        }
        if(proc==count)
		{
        	break;
        }
    }
    for(i=0;i<proc;i++)
	{
        Wait[i]=Turnar[i]-Burst[i];
        sumwt=sumwt+Wait[i];
        sumtat=sumtat+Turnar[i];
    }
    avgwt=(float)sumwt/proc;
    avgtat=(float)sumtat/proc;
    printf("\n\n   Process   Burst time   Priority	  Waiting time   Turn around time\n");
    printf("   -------   ----------   ------------    ------------  ----------------\n");
    for(i=0;i<proc;i++)
	{
    	printf("\n\n      P%d\t %d\t       %d \t        %d \t        %d",pr[i],Burst[i],prior[i],Wait[i],Turnar[i]);
    }
    printf("\n\n\n\n\t\t   Gantt Chart:\n");
    printf("\t\t   ------------\n\n");
    for(j=0;j<size;j++)
	{
        printf("\tP%d",gantproc[j]);
    }
    printf("\n   0");
    for(j=0;j<size;j++)
	{
        sum=sum+gantch[j];
        if(j==0)
		{
			printf("        %d",sum);
		}
        else
		{
			printf("\t    %d",sum);
		}
        }
        printf("\n\n\n   Average Waiting Time: %.2f \n\n   Average Turn Around Time: %.2f",avgwt,avgtat);
}
