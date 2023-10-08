#include "SLL.h"


EN_errorState_t createList(ST_list_t **ListAddress)
{
    EN_errorState_t FunctionState = RET_OK;
    if(ListAddress != NULL)
    {
        ST_list_t *ListPtr = (ST_list_t*)malloc(sizeof(ST_list_t));
        if(NULL != ListPtr)
        {
            ListPtr -> head = NULL;
            ListPtr -> sllListSize = 0;
            *ListAddress = ListPtr;
        }
        else
        {
            printf("The malloc() Failed to allocate the required size\n");
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}

 EN_errorState_t listEmpty(ST_list_t *list , EN_list_state_t *retState)
{
    EN_errorState_t FunctionState = RET_OK;
    if(NULL!=list)
    {
        if(list->sllListSize == 0)
        {
            *retState = LIST_EMPTY;
        }
        else
        {
            *retState = LIST_NEMPTY;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}




EN_errorState_t addToBack(ST_list_t *List,u8 bookName[] , u8 bookAuthor[], u32 bookPrice)
{
    EN_errorState_t FunctionState = RET_OK;
    ST_node_t *BufferPtr = NULL;
    if(NULL != List)
    {
        ST_node_t *NodePtr = (ST_node_t *)malloc(sizeof(ST_node_t));
        if(NodePtr != NULL)
        {
			
			int j=0;
            while(bookName[j] != '\0'){
	        NodePtr-> sllBookName[j] = bookName[j];
			j++;
			}
			NodePtr-> sllBookName[j] = '\0';
			
			
			int i=0;
			while(bookAuthor[i]!= '\0'){
	        NodePtr-> sllBookAuthor[i]= bookAuthor[i];
			i++;
	        }
			NodePtr-> sllBookAuthor[i] = '\0';

			
			//NodePtr-> sllBookName[i] = '\0';	
            //if (sizeof(bookPrice)==sizeof(s32) ){			
	        NodePtr-> sllBookPrice = bookPrice;
			//}
			//else {
			//printf("wrooong\n");
			//scanf("enter a number:  %d\n",&bookPrice);
			//NodePtr-> sllBookPrice = bookPrice;
			//}
            NodePtr -> next	 = NULL;
						
			/*printf("%s\n",NodePtr-> sllBookName);
			printf("%s\n",NodePtr-> sllBookAuthor);
			printf("%d\n",NodePtr-> sllBookPrice);*/
			
            BufferPtr = List-> head;
            if(BufferPtr==NULL)
            {
                List -> head = NodePtr;
            }
            else
            {
                while(BufferPtr->next != NULL)
                {
                    BufferPtr = BufferPtr -> next;
                }
                BufferPtr -> next = NodePtr;
            }
            List -> sllListSize++;
			NodePtr-> sllNumberOfBook = List -> sllListSize;			
			//printf("%list size is %d\n",List -> sllListSize);


        }
        else
        {
            FunctionState = RET_NULL_PTR;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}



EN_errorState_t removeFromPosition(ST_list_t *list , u32 bookNumber)
{
    EN_errorState_t FunctionState = RET_OK;
    EN_list_state_t List_State = LIST_NEMPTY;
    ST_node_t *PreviousPos = NULL; //to store the address, previous the exact node which the user wants to remove
    ST_node_t *NextPos = NULL; //to store the address of the exact node which the user wants to remove
    ST_node_t *BufferPtr = NULL; //to use in remove proccess frome front and from back
    if(NULL!=list)
    {
		//listEmpty(ST_list_t *list , EN_list_state_t *retState)
        listEmpty(list,&List_State);
        if(List_State == LIST_EMPTY)
        {
            printf("Sorry!! The List is EMPTY\n");
        }
        else
        {
            //is the list have one node
            if(list->head->next == NULL)
            {
                //*Ret_Data = List -> Head -> Value;
                free(list->head);
            }
            //if the user want to remove the 1st node in the list
            else if (bookNumber==1)
            {
                //*Ret_Data = List->Head->Value;
                BufferPtr =list->head;
                list->head = BufferPtr->next;
                free(BufferPtr);
			//	printf(" book number is :%d deleted\n ",bookNumber );

            }
            //if the user want to remove the last node in the list
            else if (bookNumber==list->sllListSize)
            {
               BufferPtr = list->head;
               while(BufferPtr->next->next != NULL)
               {
                   BufferPtr = BufferPtr->next;
               }
               //*Ret_Data = BufferPtr->next->Value;
               free(BufferPtr->next);
               BufferPtr->next = NULL;
			  // printf(" book number is :%d deleted\n ",bookNumber );

            }
            //if the user want to remove certain node from the middle of the node
            else
            {
                PreviousPos = list->head;
                for(int i = 1;i<bookNumber-1;i++)
                {
                    PreviousPos = PreviousPos -> next;
                }
                NextPos = PreviousPos->next;
               // *Ret_Data = NextPos->Value;
                PreviousPos = NextPos->next;
                free(NextPos);

            }
			printf(" book number %d is deleted\n ",bookNumber );
            list->sllListSize--;
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}

void displayBookInfo(ST_list_t *list){
	    if(NULL!=list)
    {
	//	EN_list_state_t *retState;
	//	listEmpty(list , retState)
	    EN_list_state_t List_State = LIST_NEMPTY;
        listEmpty(list,&List_State);
        if(List_State == LIST_EMPTY)
        {
            printf("Sorry!! no books \n");
        }
		else{
		ST_node_t *ptr = list-> head;
					int i =1;

        while (ptr -> next != NULL){
			//printf(" book number is :%d\n", ptr->sllNumberOfBook);
			printf(" book number is :%d\n", i);
			printf(" book author is :%s\n", ptr->sllBookAuthor);
			printf(" book name is :%s\n", ptr->sllBookName);
			printf(" book price is :%d\n", ptr->sllBookPrice);
			printf ("\n");
			printf ("   --------------------\n");
			printf ("\n");
            i++;

			ptr = ptr-> next;
		}
			//printf(" book number is :%d\n", ptr->sllNumberOfBook);
			printf(" book number is :%d\n", i);
			printf(" book author is :%s\n", ptr->sllBookAuthor);
			printf(" book name is :%s\n", ptr->sllBookName);
			printf(" book price is :%d\n", ptr->sllBookPrice);
			printf ("\n");
			printf ("   --------------------\n");
			printf ("\n");
		//}
	}
}
}
EN_errorState_t checkRangeOfBooks(ST_list_t *list , u32 bookNumber){
    EN_errorState_t functionState;
	if (list == NULL) {
	return  functionState = RET_NULL_PTR;
	}
	ST_node_t *ptr = list-> head;
    //if (ptr->next == NULL){bookNumber = 0;}
    //else {
		while (ptr -> next != NULL){
			ptr = ptr-> next;
		}
		// I have reached the last one whose next is null
		bookNumber = ptr -> sllNumberOfBook ; 
//	}	
	    return  functionState = RET_OK;
}