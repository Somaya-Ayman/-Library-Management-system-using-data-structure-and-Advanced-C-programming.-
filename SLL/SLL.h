#ifndef SLL_H
#define SLL_H



#include <stdio.h>
#include <stdlib.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"


typedef struct ST_node_t 
{ 
 u8 sllBookName[25]; 
 u8 sllBookAuthor[25]; 
 u32 sllBookPrice; 
 u32 sllNumberOfBook; 
 struct ST_node_t *next;
 }ST_node_t; 
typedef struct ST_list_t 
{ u32 sllListSize;
  ST_node_t *head;
 }ST_list_t;
typedef enum EN_list_state_t
{
LIST_EMPTY,
LIST_NEMPTY,
LAST_NODE,
NLAST_NODE
}EN_list_state_t;

EN_errorState_t createList(ST_list_t **listAddress);
EN_errorState_t listEmpty(ST_list_t *list , EN_list_state_t *retState);
EN_errorState_t addToBack(ST_list_t *list , u8 bookName[] , u8 bookAuthor[], u32 bookPrice);
EN_errorState_t checkRangeOfBooks(ST_list_t *list , u32 bookNumber);
EN_errorState_t removeFromPosition(ST_list_t *list , u32 bookNumber);
void displayBookInfo(ST_list_t *list);



#endif
