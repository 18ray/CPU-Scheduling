#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define MAX 100
#define MAX_PROCESS 100

double average_waiting_time, average_turnaround_time;
int sum_waiting_time=0, sum_turnaround_time=0, time_quantum;
int i, j, n;

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
	int turnaround_time;
	int priority;
}Process;

Process temp, temp2[100], p[MAX];

void print_table()
{
    int i;

    puts("+-----+--------------+--------------+------------+");
    puts("| PID | Process Name | Arrival Time | Burst Time |");
    puts("+-----+--------------+--------------+------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |       P%d     |      %2d      |     %2d     |\n"
               ,p[i].pid, p[i].pid, p[i].arrival_time, p[i].burst_time );
        puts("+-----+--------------+--------------+------------+");
    }

}

void gantt_chart(Process p[], int n)
{
    int i, j;

    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("  ");
        if(p[i].turnaround_time > 9) printf("\b");
        printf("%d", p[i].turnaround_time);

    }
    printf("\n");

}

void gantt_chart_pre(Process p[], int n)
{
    int i, j;

    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("  ");
        if(p[i].turnaround_time > 9) printf("\b");
        printf("%d", p[i].turnaround_time);

    }
    printf("\n");
}

void sort_sjf()
{
    int i, j;
    if(p[1].arrival_time == 0){
		    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    }
    else
    for(i=1; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sort_sjf_non()
{
    int i, j;
    if(p[1].arrival_time == 0){
		    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    }
    else
    for(i=1; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }   
}

void gantt_chart_round_robin(Process p[], int n)
{

}

void sort_round_robin(Process p[], int n)
{
	 
}

void sort_priority(Process p[], int n)
{
    int i, j, k;
    if(p[1].arrival_time == 0){
		    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    }
    else

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                
            }
        }
    }
  	
}

void sort_priority_non(Process p[], int n)
{
    int i, j;
    if(p[1].arrival_time == 0){
		    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    }
    else
    for(i=1; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }   
}

void awal(){
	printf("Enter total process : ");
    scanf("%d", &n);
    for(i=0; i<n; i++) 
	{
    	printf("P[%d]\n", i+1);
        printf("Arrival Time : ");
		scanf("%d", &p[i].arrival_time);
        printf("Burst Time   : ");
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
        p[i].waiting_time = p[i].turnaround_time = 0;
    }
    printf("\n");	
}

void awat(){
    p[0].turnaround_time = p[0].burst_time;
    for(i=1; i<n; i++) {
    p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
	for(i=0; i<n; i++) {
    sum_waiting_time = sum_waiting_time + p[i].waiting_time - p[i].arrival_time;
    sum_turnaround_time = sum_turnaround_time + p[i].turnaround_time - p[i].arrival_time;
	}
	average_waiting_time = (double)sum_waiting_time / (double) n;
	average_turnaround_time = (double)sum_turnaround_time / (double) n;	
}

void computation(){
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			if(p[i].pid > p[j].pid) {
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			}
		}
	}
    for(i=n; i>0; i--) {
	printf("P%d = %d-%d = %d ms\n",p[i-1].pid,p[i-1].waiting_time,p[i-1].arrival_time,p[i-1].waiting_time - p[i-1].arrival_time);
	}
	printf("AWT = (");
    for(i=n; i>0; i--) {
	printf("%d+",p[i-1].waiting_time - p[i-1].arrival_time);
	}printf(")/%d = %.2f ms",n,average_waiting_time);
	printf("\n\n");
    for(i=n; i>0; i--) {
	printf("P%d = %d-%d = %d ms\n",p[i-1].pid,p[i-1].turnaround_time,p[i-1].arrival_time,p[i-1].turnaround_time - p[i-1].arrival_time);
	}
	printf("ATAT = (");
    for(i=n; i>0; i--) {
	printf("%d+",p[i-1].turnaround_time - p[i-1].arrival_time);
	}printf(")/%d = %.2f ms",n,average_turnaround_time);
}

int main(){
	main:
		int pilih; 
		puts("===============================================================================");
    	puts("|                             PENJADWALAN PROSES                              |");
    	puts("===============================================================================");
    	puts("===============================================================================");
		puts("| 1. FCFS                                                                     |");
		puts("| 2. SJF (Preemptive) #Zero Arrival time                                      |");
		puts("| 3. SJF (Non-Preemptive)                                                     |");
		puts("| 4. Round Robin                                                              |");
		puts("| 5. Priority (Preemptive) #Zero Arrival time                                 |");
		puts("| 6. Priority (Non-Preemptive)                                                |");
		puts("===============================================================================");
		cout<<"Pilih <1-6> : ";
		cin>>pilih;
		switch(pilih)
		{
			case 1:
					{
						awal();//initiate
    					print_table();//print_table
    					//sort
						awat();//calculate
    					printf("			Hasil\n\n");
    					printf("Algorithm : First Come First Serve\n");
						printf("Average Waiting Time    : %-2.2lf ms\n", average_waiting_time);
						printf("Average Turnaround Time : %-2.2lf ms\n", average_turnaround_time);
						printf("\nGantt Chart:\n\n");
    					gantt_chart(p, n);//<=gantt_chart
    					printf("\nComputation:\n");
						computation();//computation
						break;
					}
			case 2://Non Arrival
					{
						awal();//initiate
    					print_table();//print_table
    					sort_sjf();//<=sort
						awat();//calculate
    					printf("			Hasil\n\n");
    					printf("Algorithm : SJF Preemptive\n");
						printf("Average Waiting Time    : %-2.2lf ms\n", average_waiting_time);
						printf("Average Turnaround Time : %-2.2lf ms\n", average_turnaround_time);
						printf("\nGantt Chart:\n\n");
    					gantt_chart_pre(p, n);//<=gantt_chart
    					printf("\nComputation:\n");
						computation();//computation
						break;
					}
			case 3:
					{
						awal();//initiate
    					print_table();//print_table
    					sort_sjf_non();//<=sort
    					awat();//calculate
    					printf("			Hasil\n\n");
    					printf("Algorithm : SJF Non-Preemptive\n");
						printf("Average Waiting Time    : %-2.2lf ms\n", average_waiting_time);
						printf("Average Turnaround Time : %-2.2lf ms\n", average_turnaround_time);
						printf("\nGantt Chart:\n\n");
    					gantt_chart(p, n);//<=gantt_chart
    					printf("\nComputation:\n");
						computation();//computation
						break;
					}
					
			case 4:
				   {
					  int i, limit, total = 0, x, counter = 0, time_quantum; 
				      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
				      float average_wait_time, average_turnaround_time;
				      printf("\nEnter Total Process : "); 
				      scanf("%d", &limit); 
				      x = limit; 
				      for(i = 0; i < limit; i++) 
				      {
				            printf("\nEnter Details Process[%d]\n", i + 1);
				            printf("Arrival Time : ");
				            scanf("%d", &arrival_time[i]);
				            printf("Burst Time   : ");
				            scanf("%d", &burst_time[i]); 
				            temp[i] = burst_time[i];
				      } 
				      printf("\nEnter Time Quantum:\t"); 
				      scanf("%d", &time_quantum); 
				      puts("+-----------+-----------------+-----------------+---------------------+");
				      printf("Process ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
				     puts("+-----------+-----------------+-----------------+---------------------+");
				      for(total = 0, i = 0; x 
					  != 0;) 
				      { 
				            if(temp[i] <= time_quantum && temp[i] > 0) 
				            { 
				                  total = total + temp[i]; 
				                  temp[i] = 0; 
				                  counter = 1; 
				            } 
				            else if(temp[i] > 0) 
				            { 
				                  temp[i] = temp[i] - time_quantum; 
				                  total = total + time_quantum; 
				            } 
				            if(temp[i] == 0 && counter == 1) 
				            { 
				                  x--; 
				                  printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\n", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
				                  puts("+-----------+-----------------+-----------------+---------------------+");
				                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
				                  turnaround_time = turnaround_time + total - arrival_time[i]; 
				                  counter = 0; 
				            } 
				            if(i == limit - 1) 
				            {
				                  i = 0; 
				            }
				            else if(arrival_time[i + 1] <= total) 
				            {
				                  i++;
				            }
				            else 
				            {
				                  i = 0;
				            }
				      } 
				      average_wait_time = wait_time * 1.0 / limit;
				      average_turnaround_time = turnaround_time * 1.0 / limit;
				      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
				      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
					   }
					   break;
			case 5://Non Arrival
					{
						printf("Enter total process : ");
    					scanf("%d", &n);
    					for(i=0; i<n; i++) 
						{
      					printf("P[%d]\n", i+1);
        				printf("Arrival Time    : ");
						scanf("%d", &p[i].arrival_time);
        				printf("Burst Time      : ");
        				scanf("%d", &p[i].burst_time);
        				printf("Priority Time   : ");
        				scanf("%d", &p[i].priority);
        				p[i].pid = i+1;
        				p[i].waiting_time = p[i].turnaround_time = 0;
    					}
    					printf("\n");
    					print_table();//print_table
    					sort_priority(p, n);//<=sort
						awat();//calculate
    					printf("			Hasil\n\n");
    					printf("Algorithm : Priority Non-Preemptive\n");
						printf("Average Waiting Time    : %-2.2lf ms\n", average_waiting_time);
						printf("Average Turnaround Time : %-2.2lf ms\n", average_turnaround_time);
						printf("\nGantt Chart:\n\n");
    					gantt_chart_pre(p, n);//<=gantt_chart
    					printf("\nComputation:\n");
						computation();//computation
						break;
					}
			case 6:
					{
						printf("Enter total process : ");
    					scanf("%d", &n);
    					for(i=0; i<n; i++) 
						{
      					printf("P[%d]\n", i+1);
        				printf("Arrival Time    : ");
						scanf("%d", &p[i].arrival_time);
        				printf("Burst Time      : ");
        				scanf("%d", &p[i].burst_time);
        				printf("Priority Time   : ");
        				scanf("%d", &p[i].priority);
        				p[i].pid = i+1;
        				p[i].waiting_time = p[i].turnaround_time = 0;
    					}
    					printf("\n");
    					print_table();//print_table
    					sort_priority_non(p, n);//<=sort
 						awat();//calculate
    					printf("			Hasil\n\n");
    					printf("Algorithm : Priority Non-Preemptive\n");
						printf("Average Waiting Time    : %-2.2lf ms\n", average_waiting_time);
						printf("Average Turnaround Time : %-2.2lf ms\n", average_turnaround_time);
						printf("\nGantt Chart:\n\n");
    					gantt_chart(p, n);//<=gantt_chart
    					printf("\nComputation:\n");
						computation();//computation
						break;
					}
		}
		system("pause"); 
		return 0;
}
