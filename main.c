/* =========================================================================== #
#  Filename       | main.c                                                     #
# ---------------------------------------------------------------------------- #
#  Category       | Supposed that start code of core                           #
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
#  Update history : Latest update 2020.09.01.                                  #
#   - 2020.08.10. : Made this code.                                            #
#   - 2020.09.01. : Modified code related to idle state and comments.          #
# ---------------------------------------------------------------------------- #
#  Reference document                                                          #
#   -                                                                          #
# =========================================================================== */

/* ========================================================================== */
/* Reference module --------------------------------------------------------- */
#include <stdio.h>
#include "Application.h"    // 
/* -------------------------------------------------------------------------- */
/* Global variables --------------------------------------------------------- */
static int f_state_core;    // The state of core, [1:running, 0:shutdown]
static int f_ready_core;    // The ready signal of processor, [1:Done, 0:Yet]
static int n_cnt_prog_core; // The times of core's overall turn.
static int n_cnt_free_core; // The times of core's idel turn.
static int n_sch_core;      // The index of next schedule queue.
/* ========================================================================== */

int main()
{
    printf("Hello World!\n");
    
    f_state_core    = 1; // The core state is running.
    f_ready_core    = 0; // The processor is not ready.
    n_cnt_prog_core = 0; // The core's overral turn reset to zero.
    n_cnt_free_core = 0; // The core's idle turn reset to zero.
    n_sch_core      = 0; // The index of next schedule reset to zero.
    
    
    // Setup for processor start. 
    // When setup for the processor is complete, StartSetup returns the value 1.
    f_ready_core = StartSetup();
    
    // Wait for core ready (Case by Multi-core, synchronize every core.)
    while(!f_ready_core);
    
    // Processing...
    while(f_state_core)
    {
    	// To do... (Loop without cycle time.)
    	
    	// for test
        if(n_cnt_free_core > 1000)
        {
            f_state_core = 0;
        }
    	
    	// Counts core's overral turns
    	n_cnt_prog_core++; // It is overhead.
    
        // Get the index of the next job in the schedule queue.
        // Sometimes, queue can be reordered according to scheduler.
    	n_sch_core = runn_sch_core(); // It is overhead.
    
    	if(n_sch_core != -1)
    	{
    		// Running Job function that ordered by the scheduler.
    		Process_Core_free[n_sch_core]();
    		
    		//printf("Running test: ...%d\n\r", n_sch_core1);
    	}
    	else
    	{
    		// Counts core's idle turns.
    		n_cnt_free_core++; // It is overhead.
    		
    		//printf("Empty process...\n\r");
    	}
    }

    return 0;
}