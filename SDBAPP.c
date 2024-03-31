#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"SDB.h"
#include"STD.h"

void cls()//clearing console function
{
         system("cls");

}
void SDB_APP()
{
   printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|                    |\n\t\t\t\t\t|\tWelcome      |\n\t\t\t\t\t|____________________|\n\t\t\t\t\t|\t\t     |\n\n\n");
getch();
cls();
uint8 choice;



         while(1)
    {
        printf("\n\t\t\t\t\tStudent's Record\n");
        printf("\t\t\t_______________________________________________");
        printf("\n\n");

        printf("------------------------------------------------------------------------------------------");
        printf("\n\n");
        printf("\t\t\t\t1. Add entry.\n");
        printf("\t\t\t\t2. Used size in data base.\n");
        printf("\t\t\t\t3. Read student data with ID.\n");
        printf("\t\t\t\t4. Getting list of all students ID.\n");
        printf("\t\t\t\t5. Check ID is exist or not.\n");
        printf("\t\t\t\t6. Delete Student data.\n");
        printf("\t\t\t\t7. Checking data base is full or not.\n");
        printf("\t\t\t\t8. Exit.\n");
        printf("------------------------------------------------------------------------------------------");

        printf("\n\t\t\tPlease Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        cls();
        SDB_action(choice);


}

}
void SDB_action (uint8 choice)
{
         uint32 ID_search1,ID_search2, ID_Delete,data_Base;
         uint32 list[50];
         uint8 count,list_Count;
;

      switch (choice)
         {
         case 1:
         SDB_AddEntry();
         getch();
         cls();
         break;

         case 2:
         count = SDB_GetUsedData();
         printf("\n\n\t\t\t\t\t* there is %d students in your data base *\n\n",count);
         getch();
         cls();
         break;

         case 3:
         printf("please enter the ID of the student that you want to search\n");
         scanf("%d",&ID_search1);
         SDB_ReadEntry(ID_search1);
         getch();
         cls();
         break;

         case 4:
           list_Count=0;
           printf("The list of the IDs in the data base is:\n");
           SDB_GetList(&list_Count);
           printf("the number of IDs in the list is %d\n",list_Count);

           getch();
           cls();
         break;

         case 5:
         printf("please enter the ID of the student to check if its exist or not\n");
         scanf("%d",&ID_search2);
         bool position1 = SDB_IsIdExist(ID_search2);
         if (position1 == false )
         {
         printf("\nthe student ID is not found in the data base\n\n\n\n\n\n\n\n\n\n");
         }
         else
         {
         printf("\nthe student ID is found in the data base\n\n\n\n\n\n\n\n\n\n");
         }
         getch();
         cls();
         break;

         case 6:
         printf("please enter the ID of the student that you want to delete his/her information\n");
         scanf("%d",&ID_Delete);
         SDB_DeleteEntry(ID_Delete);
         getch();
         cls();
         break;

         case 7:
          data_Base = SDB_IsFull ();
         if (data_Base == true)
         {
         printf("your data base is full\n");
         }
         else
         {
         printf("your data base is not full\n");
         }
         getch();
         cls();
         break;

         case 8:
         printf("\n\n\n\n\n\t\t\t\t\t*__________* THANK YOU *__________*\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
         exit(1);
         break;

          default:printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                    printf("\n\t\t\tPlease Enter Correct Key to Access.");
                    printf("\n\t\t\t\tOr Enter 8 to Exit.\n\n\n");
                    getch();
                    cls();
                    return SDB_APP;

         }

}
