


int main(int argc, char** argv)
{

 pthread_attr_t attr_t1;
 struct sched_param param_1;
 struct periodique pd_2;


 pthread_attr_init(&attr);
 param.sched_priority = 13;
 pthread_setschedparam(pthread_self(), SCHED_FIFO, &param);


 pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
 pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
