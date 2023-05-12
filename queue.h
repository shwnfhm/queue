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
#include <stdbool.h>


//=============================================
// Data Structure Declarations
//=============================================
/* Linked list element (You shouldn't need to change this) */
typedef struct ELE {
    int value;
    struct ELE *next;
} ListElement_t;


/* Queue structure */
typedef struct {
    ListElement_t *head;  /* Linked list of elements */
    ListElement_t *tail;  /* pointer to the last element in the Queue */
    int size;             /* keeps track of number of elements in Queue */
} Queue_t;



//=============================================
// Function Prototypes
//=============================================
/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
Queue_t *q_new();


/*
  Free all storage used by queue.
  No effect if q is NULL
*/
void q_free(Queue_t *q);


/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(Queue_t *q, int v);


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(Queue_t *q, int v);


/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(Queue_t *q, int *vp);


/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(Queue_t *q);


/*
  Reverse elements in queue
  No effect if q is NULL or empty
 */
void q_reverse(Queue_t *q);
