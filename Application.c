/* =========================================================================== #
#  Filename       | Application.h                                              #
# ---------------------------------------------------------------------------- #
#  Category       | Application's Functions                                    #
# ---------------------------------------------------------------------------- #
#  Title          | Queue Scheduling Study                                     #
# ---------------------------------------------------------------------------- #
#  Developer      | UnderSmith                                                 #
# ---------------------------------------------------------------------------- #
#  Department     | My Smithy                                                  #
# ---------------------------------------------------------------------------- #
#  Copyright      | ????                                                       #
# ---------------------------------------------------------------------------- #
#  Description    |                                                            #
#   Role          : ...                                                        #
#   What to do    : ...                                                        #
#   Style         : The style of this code is                                  #
#                 ;  based on Guido van Rossum's REF 8.                        #
# ---------------------------------------------------------------------------- #
#  Update history : Latest update 2020.08.10.                                  #
#   - 2020.08.10. : Made this code                                             #
# ---------------------------------------------------------------------------- #
#  Reference document                                                          #
#   -                                                                          #
# =========================================================================== */

/* ========================================================================== */
/* Reference module --------------------------------------------------------- */
#include <stdio.h>
#include "Application.h"
/* ========================================================================== */


#define FID001_tic 100
#define FID002_tic 200
#define FID003_tic 300
#define FID004_tic 400
#define FID005_tic 500
#define FID006_tic 600
#define FID007_tic 700
#define FID008_tic 800


int StartSetup(void)
{
    Init_sch_core();

    insert_sch_core(0, 1);
    insert_sch_core(0, 2);
    insert_sch_core(0, 3);
    insert_sch_core(0, 4);

					
	return 1;
}


void (*Process_Core_free[])(void) =
{
    fnc_dummy,  /* on [Application.c] : Function ID 000 ----------------------*/
	fnc_test1,	/* on [Application.c] : Function ID 001 ----------------------*/
	fnc_test2,	/* on [Application.c] : Function ID 002 ----------------------*/
	fnc_test3,	/* on [Application.c] : Function ID 003 ----------------------*/
	fnc_test4,	/* on [Application.c] : Function ID 004 ----------------------*/
	fnc_test5,	/* on [Application.c] : Function ID 005 ----------------------*/
	fnc_test6,	/* on [Application.c] : Function ID 006 ----------------------*/
	fnc_test7,	/* on [Application.c] : Function ID 007 ----------------------*/
	fnc_test8,	/* on [Application.c] : Function ID 008 ----------------------*/
};

void fnc_dummy(void)
{
    // Dummy...
}

void fnc_test1(void)
{
    printf("FID 001 processing...");
    delay_for(FID001_tic); 
    printf("done.\n");
}

void fnc_test2(void)
{
    printf("FID 002 processing...");
    delay_for(FID002_tic); 
    printf("done.\n");
}

void fnc_test3(void)
{
    printf("FID 003 processing...");
    delay_for(FID003_tic);
    printf("done.\n");
}

void fnc_test4(void)
{
    printf("FID 004 processing...");
    delay_for(FID004_tic);
    printf("done.\n");
}

void fnc_test5(void)
{
    printf("FID 005 processing...");
    delay_for(FID005_tic);
    printf("done.\n");
}

void fnc_test6(void)
{
    printf("FID 006 processing...");
    delay_for(FID006_tic);
    printf("done.\n");
}

void fnc_test7(void)
{
    printf("FID 007 processing...");
    delay_for(FID007_tic);
    printf("done.\n");
}

void fnc_test8(void)
{
    printf("FID 008 processing...\n");
    delay_for(FID008_tic);
    printf("done.\n");
}

void delay_for(int iter)
{
    int i, j, k, dummy;
    for(i = 0; i < iter; i++)
        for(j = 0; j < iter; j++)
            for(k = 0; k < iter; k++)
                dummy = i + j + k;
}

