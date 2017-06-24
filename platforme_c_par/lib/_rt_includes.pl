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
