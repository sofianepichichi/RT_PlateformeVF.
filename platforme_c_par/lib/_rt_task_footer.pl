
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
