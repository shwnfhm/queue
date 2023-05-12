//=============================================
// Shawn Fahimi
//=============================================
/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

//=============================================
// Includes and Defines
//=============================================
#include <stdlib.h>
#include <stdio.h>
#include "harness.h"
#include "queue.h"


//=============================================
//=============================================
/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
Queue_t *q_new()
{
    Queue_t *q =  malloc(sizeof(Queue_t));
    /* What if malloc returned NULL? */
    if(q == NULL){
      return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}


//=============================================
//=============================================
/* Free all storage used by queue */
void q_free(Queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
    if(q == NULL){
      return;
    }

    ListElement_t *currEle = q->head;
    ListElement_t *tf = currEle;

    //free individual elements
    while(currEle != NULL){
      currEle = currEle->next;
      free(tf);
      tf = currEle;
    }
    //free queue structure
    free(q);
}


//=============================================
//=============================================
/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(Queue_t *q, int v)
{
    if(q == NULL){
      return false;
    }
    
    ListElement_t *newh = malloc(sizeof(ListElement_t));

    //if malloc could not allocate space
    if(newh == NULL){
      return false;
    }
    
    //put v as the value for newh, have it point to the current head
    //and then have "head" point to newh
    newh->value = v;
    newh->next = q->head;
    q->head = newh;
    (q->size)++;

    //if this is the only item, make tail point to newh as well
    if(q->size == 1){
      q->tail = newh;
    }
    return true;
}


//=============================================
//=============================================
/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(Queue_t *q, int v)
{
    if(q == NULL){
      return false;
    }

    ListElement_t *newtail = malloc(sizeof(ListElement_t));

    //if malloc could not allocate space
    if(newtail == NULL){
      return false;
    }

    //make v the value of newtail and have it's next pointer point to nothing
    newtail->value = v;
    newtail->next = NULL;

    //update size
    (q->size)++;

    //"insert" new tail at the end of non-empty queue
    if(q->size != 0){
      q->tail->next = newtail;
      q->tail = newtail;
    }
    //"insert" new tail in empty queue
    else{
      q->head = newtail;
      q->tail = newtail;
    }
   
    return true;
}


//=============================================
//=============================================
/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(Queue_t *q, int *vp)
{
    if(q == NULL || q->size == 0){
      return false;
    }
    
    //save removed value
    if(vp != NULL){
      *vp = q->head->value;
    }

    //change head pointer from first element to next element
    ListElement_t *tf = q->head;
    q->head = q->head->next;
    (q->size)--;
    
    //in case head was the only element
    if(q->size == 0){
      q->tail = NULL;
    }

    //free memory allocated for removed head
    free(tf);
    return true;
}


//=============================================
//=============================================
/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(Queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if(q != NULL){
      return q->size;
    }
    return 0;
}


//=============================================
//=============================================
/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(Queue_t *q)
{
    //no need to reverse if q is NULL or has no more than one element
    if(q == NULL || q->size < 2){
      return;
    }

    /* have pointer to last element point to first element to
      begin reversal */
    q->tail = q->head;
    
    ListElement_t *currEle = q->head;
    ListElement_t *nextEle = q->head->next;
    ListElement_t *prevEle = NULL;

    /* reverse directions of "next" pointers in the queue
      in order to reverse queue */
    while(nextEle != NULL){
      currEle->next = prevEle;
      prevEle = currEle;
      currEle = nextEle;
      nextEle = currEle->next; 
    }
    
    currEle->next = prevEle;

    //have head now point to the original tail
    q->head = currEle;
}