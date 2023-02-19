long gauss_sum1(int n){
    long r=0;

    for(int k=0; k<n;k++){
        r+=k
    }
    return r;
}

status_t gauss_sum2(long *r, int n){
    if (NULL == r){
        return ST_ERR_NULL_PTR;

    }
    if (n <=0){
        return ST_INVALID_ARG;
    }

    *r= gausss_sum1(n);

    return ST_OK;

}
