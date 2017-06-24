#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#define maxsize 200


using namespace std;



struct  periodique
{
   int period;
   int deadline;
};



struct timespec ms_tospec(double x)
{
	struct timespec  tp;
	tp.tv_sec = (int)(x/1000);
	tp.tv_nsec = (x-tp.tv_sec)*1000000 ;
	return tp;
}



timespec timespec_add(const timespec *a, const timespec *b)
{
    timespec s;
    s.tv_nsec = a->tv_nsec + b->tv_nsec;
    s.tv_sec = a->tv_sec + b->tv_sec;
    while (s.tv_nsec >= 1000000000) {
    s.tv_nsec = s.tv_nsec - 1000000000;
    s.tv_sec += 1;
    }
    return s;
}

int timespec_cmp(const timespec *a, const timespec *b)
{
    if (a->tv_sec > b->tv_sec) return 1;
    else if (a->tv_sec < b->tv_sec) return -1;
    else if (a->tv_sec == b->tv_sec) {
    if (a->tv_nsec > b->tv_nsec) return 1;
    else if (a->tv_nsec == b->tv_nsec) return 0;
    else return -1;
    }
    return 0;
}

timespec timespec_sub(const timespec *a, const timespec *b)
{
    timespec d;

    d.tv_nsec = a->tv_nsec - b->tv_nsec;
    d.tv_sec =  a->tv_sec - b->tv_sec;
    if (a->tv_nsec < b->tv_nsec) {
    d.tv_nsec += 1000000000;
    d.tv_sec -= 1;
    }
    return d;//timespec_to(&d, unit);
}

double spec_toms(struct timespec x)
{
	return x.tv_sec * 1000+x.tv_nsec / 1000000;
}
void * task_1(void *arg){

        struct periodique *cp = (struct periodique *) arg;
     
long tab1 [maxsize] ; 
long tab2 [maxsize] ; 
long tab3 [maxsize] ; 



	for (int i=0; i<maxsize;i++)
	{

	  tab1[i] = i;
	  tab2[i] = 5-i;

	}
      
int index =1;
int period =70;
int deadline =40;
int nbrIt =2;
int priority =10;
int affinity =1;


struct timespec Begin, End;
int i=0;
int MissedDeadlines=0;
while(i<2){
    clock_gettime(CLOCK_REALTIME, &Begin);
    struct timespec period_timespec = ms_tospec(period);
    struct timespec NextActivation = timespec_add(&Begin,&period_timespec);
    struct timespec deadline_timespec = ms_tospec(deadline);
    struct timespec Dij= timespec_add(&Begin,&deadline_timespec);
	{

	for (int j=0;j<maxsize;j++)
  	{
    	  tab3[j] =tab1[j] + tab2[j];
    	}
		}

clock_gettime(CLOCK_REALTIME, &End);
struct  timespec responseTime= timespec_sub(&End,&Begin);
cout<<i<<"\t"<<spec_toms(responseTime)<<endl;
int DR =timespec_cmp(&Dij,&End);
if(DR == -1)
MissedDeadlines +=1;
clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &NextActivation, NULL);
 i++;
}
printf("deadline raté est : ");
cout<<"\t"<<MissedDeadlines<<endl;

}
void * task_2(void *arg){

        struct periodique *cp = (struct periodique *) arg;
      
       	int m=190;
	int c=0,d=0,k=0,sum=0;
	int first[m][m], second[m][m], multiply[m][m];
    
	for (c = 0; c < m; c++)
	    for (d = 0; d < m; d++)
	    {
            first[c][d]=c*d+5;
            second[d][c]=c+d+5;
        }
int index =2;
int period =60;
int deadline =35;
int nbrIt =2;
int priority =10;
int affinity =1;


struct timespec Begin, End;
int i=0;
int MissedDeadlines=0;
while(i<2){
    clock_gettime(CLOCK_REALTIME, &Begin);
    struct timespec period_timespec = ms_tospec(period);
    struct timespec NextActivation = timespec_add(&Begin,&period_timespec);
    struct timespec deadline_timespec = ms_tospec(deadline);
    struct timespec Dij= timespec_add(&Begin,&deadline_timespec);
		{

	 for (c = 0; c < m; c++) {
            for (d = 0; d < m; d++) {
            	for (k = 0; k < m; k++) {
                	sum = sum + first[c][k]*second[k][d];
                }
                	multiply[c][d] = sum;
                    sum = 0;
            }
    	}
		}

clock_gettime(CLOCK_REALTIME, &End);
struct  timespec responseTime= timespec_sub(&End,&Begin);
cout<<i<<"\t"<<spec_toms(responseTime)<<endl;
int DR =timespec_cmp(&Dij,&End);
if(DR == -1)
MissedDeadlines +=1;
clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &NextActivation, NULL);
 i++;
}
printf("deadline raté est : ");
cout<<"\t"<<MissedDeadlines<<endl;


}
void * task_3(void *arg){

struct periodique *cp = (struct periodique *) arg;
long tab1 [maxsize] ; 
long tab2 [maxsize] ; 
long tab3 [maxsize] ;



	for (int i=0; i<maxsize;i++)
	{

	  tab1[i] = i+7;
	  tab2[i] = 10*i;

	}

int index =3;
int period =60;
int deadline =40;
int nbrIt =3;
int priority =4;
int affinity =0;


struct timespec Begin, End;
int i=0;
int MissedDeadlines=0;
while(i<3){
    clock_gettime(CLOCK_REALTIME, &Begin);
    struct timespec period_timespec = ms_tospec(period);
    struct timespec NextActivation = timespec_add(&Begin,&period_timespec);
    struct timespec deadline_timespec = ms_tospec(deadline);
    struct timespec Dij= timespec_add(&Begin,&deadline_timespec);
		{

          for (int j=0;j<maxsize;j++)
  	  {
    	  	tab3[j] =tab1[j] + tab2[j];
    	  }
		}

clock_gettime(CLOCK_REALTIME, &End);
struct  timespec responseTime= timespec_sub(&End,&Begin);
cout<<i<<"\t"<<spec_toms(responseTime)<<endl;
int DR =timespec_cmp(&Dij,&End);
if(DR == -1)
MissedDeadlines +=1;
clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &NextActivation, NULL);
 i++;
}
printf("deadline raté est : ");
cout<<"\t"<<MissedDeadlines<<endl;

}

int main(int argc, char** argv)
{

  
  struct sched_param param;
  struct periodique pd;
  pthread_attr_t attr;


pd.period =70;
pd.deadline =40;
pthread_t thread0;
param.sched_priority = 10;
pthread_attr_setschedparam(&attr, &param);
pthread_create (&thread0,NULL,task_1,(void *)&pd);




pd.period =60;
pd.deadline =35;
pthread_t thread1;
param.sched_priority = 10;
pthread_attr_setschedparam(&attr, &param);
pthread_create (&thread1,NULL,task_2,(void *)&pd);




pd.period =60;
pd.deadline =40;
pthread_t thread2;
param.sched_priority = 4;
pthread_attr_setschedparam(&attr, &param);
pthread_create (&thread2,NULL,task_3,(void *)&pd);


pthread_join (thread0,NULL);
pthread_join (thread1,NULL);
pthread_join (thread2,NULL);

return 0;

}
