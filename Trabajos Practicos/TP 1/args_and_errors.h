#pragma once

#include <stdio.h>
#include <string.h>

//Definition of types - Errors
typedef enum {ST_OK, ST_ERR_INSUFFICIENT_ARGUMENTS, ST_ERR_TOO_MANY_ARGUMENTS, ST_ERR_NULL_PTR, ST_ERR_INVALID_NUMBER, ST_ERR_UNKNOWN_ARGUMENT, ST_HELP, ST_ERR_MEM_ALLOC, END} status_t;

static char *status_msg[END] = {[ST_OK] = "OK", [ST_ERR_INSUFFICIENT_ARGUMENTS] = "ERROR: Insufficient arguments", 
                                [ST_ERR_TOO_MANY_ARGUMENTS] = "ERROR: Too many arguments",[ST_ERR_NULL_PTR] = "ERROR: Null pointer", 
                                [ST_ERR_INVALID_NUMBER] = "ERROR: Invalid number", [ST_ERR_UNKNOWN_ARGUMENT] = "ERROR: Unknown argument", 
                                [ST_HELP] = "Finished Process", [ST_ERR_MEM_ALLOC] = "ERROR: Memory allocation failed"};

//Definition of types - Arguments
typedef enum {ARG_COLS_SHORT, ARG_COLS_LONG, ARG_ROWS_SHORT, ARG_ROWS_LONG, ARG_SEED_SHORT, ARG_SEED_LONG, ARG_CYCLES, ARG_PPM, ARG_TER_REP, ARG_HELP_SHORT, ARG_HELP_LONG, ARG_PPM_TER } arg_t;

static const char *valid_args[] = {[ARG_COLS_SHORT] = "-W",  [ARG_COLS_LONG] = "--width",  [ARG_ROWS_SHORT] = "-H",    [ARG_ROWS_LONG] = "--height",  
                                   [ARG_CYCLES] = "-c",      [ARG_PPM] = "-n",             [ARG_SEED_SHORT] = "-s",    [ARG_SEED_LONG] = "--seed",  
                                   [ARG_TER_REP] = "-tr",    [ARG_HELP_SHORT] = "-h",      [ARG_HELP_LONG] = "--help", [ARG_PPM_TER] = "-pr"};