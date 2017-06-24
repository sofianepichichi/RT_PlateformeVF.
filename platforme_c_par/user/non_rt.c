#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#define maxsize 2000
using namespace std;


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
      
	rt:
	{

	for (int j=0;j<maxsize;j++)
  	{
    	  tab3[j] =tab1[j] + tab2[j];
    	}
		}

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
	rt:
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

	rt:
		{

          for (int j=0;j<maxsize;j++)
  	  {
    	  	tab3[j] =tab1[j] + tab2[j];
    	  }
		}

}

int main(void)
{
task_1();
}
