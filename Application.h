/* =========================================================================== #
#  Filename       | Application.c                                              #
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
#include "SysSW_Supervisor.h"
/* ========================================================================== */

extern void Init_sch_core(void);
extern int runn_sch_core(void);
extern void insert_sch_core(int type, int n_fnc);

extern void (*Process_Core_free[])(void);
extern int  StartSetup(void);

void fnc_dummy(void);
void fnc_test1(void);
void fnc_test2(void);
void fnc_test3(void);
void fnc_test4(void);
void fnc_test5(void);
void fnc_test6(void);
void fnc_test7(void);
void fnc_test8(void);

void delay_for(int iter);