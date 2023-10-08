#include"main.h"

/*void main(void)
{
    List_t *List =NULL;
    s32 x = 0;
    CreateList(&List);
    AddToFront(List,50);
    AddToFront(List,60);
    RemoveFromPosistion(List,&x,1);
    printf("%d\n",x);
    RemoveFromPosistion(List,&x,2);
    printf("%d\n",x);
    RemoveFromPosistion(List,&x,1);
    printf("%d\n",x);
    RemoveFromPosistion(List,&x,1);
    printf("%d\n",x);
    RemoveFromPosistion(List,&x,1);
    printf("%d\n",x);
    RemoveFromPosistion(List,&x,1);
    printf("%d\n",x);
}*/
		  u32 bbookNumber= 0 ;

/*	      u8 bookName[25];
		  u8 bookAuthor[25];
		  u32 bookPrice;
		  u32 bookNumber;
		  u32 bbookNumber;

		 EN_errorState_t functionState;
		 EN_list_state_t function2State;
		 ST_list_t *listAddress = NULL; ana hasa el satr dah hwa ele qarafne*/
void main (void){
	      u8 bookName[25];
		  u8 bookAuthor[25];
		  u32 bookPrice = 0;
		  u32 bookNumber = 0;

		 EN_errorState_t functionState;
		 EN_list_state_t function2State;
		 ST_list_t *listAddress = NULL;
		 createList(&listAddress);
	//	printf(" number of books %d\n", listAddress->sllListSize );


	printf("   WELCOME TO THE LIBRARY APP \n");
			printf ("\n");
			printf ("   --------------------\n");
			printf ("\n");
	while(1){
		int choice;
		//printf("%d \n",functionState );
		printf("Choose one of the following options:\n");
        printf(" To view all books               Enter '1'\n");
        printf(" To add a New book               Enter '2'\n");
        printf(" To Delete a book                Enter '3'\n");
        printf(" To view No. of available books  Enter '4'\n");
        printf(" To Exit the Library App         Enter '5'\n");
			printf ("\n");
			printf ("   --------------------\n");
			printf ("\n");
		fflush(stdout);
		scanf(" %d",&choice);
		fflush(stdin); 
					printf ("\n");
			printf ("   --------------------\n");
			printf ("\n");
		  
		switch (choice){
			case 1:
			displayBookInfo(listAddress);
			printf ("   --------------------\n");
			break;
			
			case 2:  //done
			
			printf("enter book name: \n");
			fflush(stdout); 
			gets(bookName);//awel esm dayman by2t3oh leh ba2a
			fflush(stdin); 
			
			printf("enter book author: \n");
			fflush(stdout); //it made it worse than before b y skip eno ya3ml cin
			gets(bookAuthor);
			fflush(stdin); 		
			
			printf("enter book price: \n");
			scanf("%d",&bookPrice);		
			
			functionState = addToBack(listAddress , bookName, bookAuthor , bookPrice);
			//printf("%d \n",functionState );
						printf ("   --------------------\n");

			if (functionState == RET_OK){
			printf(" book added successfily\n");
			//printf(" number of books %d\n", listAddress->sllListSize );

			
			}
			else {printf ("error error error\n");}
			printf ("   --------------------\n");
			break;

			case 3:
			printf ("enter book number you want to delete\n");
					fflush(stdout);
		            scanf(" %d",&bookNumber);
		            fflush(stdin); 
		  			printf ("   --------------------\n");

			functionState = removeFromPosition(listAddress , bookNumber);
			printf ("   --------------------\n");
			break;
			case 4: //done
			//functionState = checkRangeOfBooks(listAddress , bbookNumber);
			//if (functionState == RET_OK){
			printf(" number of books %d\n", listAddress->sllListSize );
						printf (" \n");

			printf ("   --------------------\n");

			
			//}
			//else {printf ("error error error\n"); }
			break;
			case 5: break; //done
			default: break;

		}
		if(choice == 5)break;
		
	}
}
