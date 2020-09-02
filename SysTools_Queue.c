/* =========================================================================== #
#  Filename       | SysTools_Queue.c                                           #
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
#include <stdlib.h>
#include "SysTools_Queue.h"
/* ========================================================================== */



/* Insert node on queue ------------------------------------------------------*/
void initQueue(Q_head_ptr *head)
{
    /* Input	: Queue head, ------------------------------------------------*/
	/* Output	: none. ------------------------------------------------------*/
	/* Jobs		: Initialize Queue -------------------------------------------*/
	
	head->num = 0;
	head->primary = NULL;
}



/* Insert node on queue ------------------------------------------------------*/
void enQueue(Q_head_ptr *head, Q_node_ptr *pre, int data)
{
    /* Input	: Queue head, previous node, and data of node ----------------*/
    /* Output	: none. ------------------------------------------------------*/
    /* Jobs		: Insert methods are four case -------------------------------*/
    /*          ; If queue is empty, Insert node on primary ------------------*/
    /*          ; ('pre' == -1) Inserts node on primary ----------------------*/
    /*          ; ('pre' ==  0) Inserts node on last -------------------------*/
    /*          ; ('pre' is available address) Inserts node on next of 'pre' -*/

    Q_node_ptr *new = (Q_node_ptr*)malloc(sizeof(Q_node_ptr));
    Q_node_ptr *temp;

    new->data = data;

    if(head->primary == NULL)
    {	/* Queue is empty, insert first node ---------------------------------*/
        head->primary = new;
        head->primary->prev_Link = NULL;
        head->primary->next_Link = NULL;
        head->num = 1;
    }
	else
	{	/* Queue is not empty. -----------------------------------------------*/

		head->num++;

		if(pre == -1)
		{	/* Insert node in primary position -------------------------------*/
			new->next_Link = head->primary;
			head->primary->prev_Link = new;
			new->prev_Link = NULL;
			head->primary = new;
		}
		else if(pre == NULL)
		{	/* Insert node in last position ----------------------------------*/

			/* Find last node ------------------------------------------------*/
			temp = head->primary;
			while(temp->next_Link != NULL)
			{	/* Find next, again ------------------------------------------*/
				temp = temp->next_Link;
			}
			new->prev_Link = temp;
			new->next_Link = NULL;
			temp->next_Link = new;
		}
		else
		{
			/* Insert node on next of 'pre' ----------------------------------*/
			if(pre->next_Link == NULL)
			{	/* 'pre' node is last node of queue --------------------------*/
				new->next_Link = NULL;
				pre->next_Link = new;
				new->prev_Link = pre;
			}
			else
			{	/* 'pre' node is not last node of queue ----------------------*/
				new->next_Link = pre->next_Link;
				pre->next_Link = new;
				new->prev_Link = pre;
				new->next_Link->prev_Link = new;
			}
		}
	}
}
/*----------------------------------------------------------------------------*/

/* Delete node on queue ------------------------------------------------------*/
void deQueue(Q_head_ptr *head, Q_node_ptr *old)
{
	/* Input	: Queue head, removed target node ----------------------------*/
	/* Output	: none. ------------------------------------------------------*/
	/* Jobs		: Delete methods are four case -------------------------------*/
	/*          ; If 'old' node is last node, --------------------------------*/
	/*          ; If Queue has only one node, --------------------------------*/
	/*          ; If 'old' node is first node, -------------------------------*/
	/*          ; General case, ----------------------------------------------*/

	if(head->num > 0)
	{	/* If queue is not empty, this function do not working ---------------*/
		head->num--;

		/* Divides node position ---------------------------------------------*/
		if(old->next_Link == NULL)
		{	/* 'old' node is last on queue -----------------------------------*/
			if(head->primary->next_Link == NULL)
			{	/* Queue has only one node -----------------------------------*/
				head->primary = NULL;
			}
			else
			{	/* Number of node is not one ---------------------------------*/
				/* Previous node's next link change --------------------------*/
				old->prev_Link->next_Link = old->next_Link;
			}
		}
		else if(old->prev_Link == NULL)
		{	/* 'old' node is first on queue ----------------------------------*/
			head->primary = old->next_Link;
			old->next_Link->prev_Link = old->prev_Link;
		}
		else
		{	/* 'old' node is not first and last on queue (general case) ------*/
			old->prev_Link->next_Link = old->next_Link;
			old->next_Link->prev_Link = old->prev_Link;
		}

		free(old);
	}
}
/*----------------------------------------------------------------------------*/


/* Outs one node on queue ----------------------------------------------------*/
int outQueue(Q_head_ptr *head)
{
	/* Input	: Queue head -------------------------------------------------*/
	/* Output	: Data of first node -----------------------------------------*/
	/* Jobs		: Outs data of first node and delete -------------------------*/

	int output;

	if(head->primary == NULL)
	{	/* If queue is empty, return -1 --------------------------------------*/
		return -1;
	}
	else
	{	/* Return data of first node (primary) and deleted node on queue -----*/
		output = head->primary->data;
		deQueue(head, head->primary);
		return output;
	}
}
/*----------------------------------------------------------------------------*/

