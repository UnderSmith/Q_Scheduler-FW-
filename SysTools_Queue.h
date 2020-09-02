/* =========================================================================== #
#  Filename       | SysTools_Queue.h                                           #
# ---------------------------------------------------------------------------- #
#  Category       | C code Queue Library                                       #
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
/* ========================================================================== */

typedef struct Q_node Q_node_ptr;
typedef struct Q_node
{
	int data;
	Q_node_ptr *prev_Link, *next_Link;
}Q_node_ptr;

typedef struct Q_head
{
	int num;
	Q_node_ptr *primary;
}Q_head_ptr;

void initQueue(Q_head_ptr *head);
void enQueue(Q_head_ptr *head, Q_node_ptr *pre, int data);
void deQueue(Q_head_ptr *head, Q_node_ptr *old);
int  outQueue(Q_head_ptr *head);
