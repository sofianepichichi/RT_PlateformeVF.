    clock_gettime(CLOCK_REALTIME, &Begin);
    struct timespec period_timespec = ms_tospec(period);
    struct timespec NextActivation = timespec_add(&Begin,&period_timespec);
    struct timespec deadline_timespec = ms_tospec(deadline);
    struct timespec Dij= timespec_add(&Begin,&deadline_timespec);
