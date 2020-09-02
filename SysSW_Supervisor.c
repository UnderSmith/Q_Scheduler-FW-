/* =========================================================================== #
#  Filename       | SysSW_Supervisor.c                                         #
# ---------------------------------------------------------------------------- #
#  Category       | C code System Supervisor                                   #
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

Q_head_ptr sch_core;

void Init_sch_core(void)
{
	initQueue(&sch_core);
	
	// Initialize here : ...
    /* Queue insert and out example ----------------------------------------- */
	// inserts node first time on queue
	enQueue(&sch_core, 0, 2);
	// inserts node next of primary->next_Link (third) on queue
	enQueue(&sch_core, sch_core.primary->next_Link, 1);
	// inserts node last on queue
	enQueue(&sch_core, 0, 0);
	// inserts node primary on queue
	enQueue(&sch_core, -1, 3);
	
// 	printf("Outs node, data is '%d',\t\t number of node %d -> %d\r\n",
// 					outQueue(&sch_core), sch_core.num + 1, sch_core.num);
// 	printf("Outs node, data is '%d',\t\t number of node %d -> %d\r\n",
// 					outQueue(&sch_core), sch_core.num + 1, sch_core.num);
// 	printf("Print data of primary node '%d',\t number of node %d\r\n",
// 					sch_core.primary->data, sch_core.num);
// 	printf("Print data of second node '%d',\t number of node %d\r\n",
// 					sch_core.primary->next_Link->data, sch_core.num);

}

int runn_sch_core(void)
{
	return outQueue(&sch_core);
}

void insert_sch_core(int type, int n_fnc)
{
	enQueue(&sch_core, 0, n_fnc);

}