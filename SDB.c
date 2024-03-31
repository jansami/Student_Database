#include"SDB.h"
#include"STD.h"
#include<stdio.h>
#include<stdlib.h>
student* start=NULL;//start of single linked list

 bool SDB_IsFull()
 {
student* temp = start ;
uint8 counter = 0;
while (temp != NULL)
{
         counter ++;
         temp=temp->link;
}
if (counter<=10)
{
         return false;//return false if database is not full
}
else
{
         return true;//return true if database is full
}

 }
 uint8 SDB_GetUsedData()// function to Know how many student in our data base(2)
 {
          uint8 counter = 0 ;
          student* temp = start;
          while(temp != NULL)
          {
              counter++;
              temp = temp->link;
          }
          return counter;
 }
 bool SDB_AddEntry()// function for adding node to the list(1)
 {
          student* ptr = (student*)malloc(sizeof(student));//create a new node is single linked list

          uint32 STD_ID , year , cou1_ID , cou1_grd , cou2_ID , cou2_grd , cou3_ID , cou3_grd;


          printf("\n\t\t\t*___________* PLEASE ENTER THE STUDENT DATA *__________*\n\n");

          printf("\n1-please enter the student ID\n--> ");
          scanf ("%d",&STD_ID);

          printf("\n2-please enter the student graduation year\n--> ");
          scanf ("%d",&year);

          printf("\n3-please enter Coures1_ID\n--> ");
          scanf ("%d",&cou1_ID);

          printf("\n4-please enter Coures1_GRADE\n--> ");
          scanf ("%d",&cou1_grd);

          printf("\n5-please enter Coures2_ID\n--> ");
          scanf ("%d",&cou2_ID);

          printf("\n6-please enter Coures2_GRADE\n--> ");
          scanf ("%d",&cou2_grd);

          printf("\n7-please enter Coures3_ID\n--> ");
          scanf ("%d",&cou3_ID);

          printf("\n8-please enter Coures3_GRADE\n--> ");
          scanf ("%d",&cou3_grd);
          if (ptr == NULL)
          {
                   printf("\n\n\t\t\t*__________*Failed to Create the record*__________*\n\n");
          }
          else
          {
                  ptr->Student_ID    = STD_ID;
                  ptr->Student_Year  = year;
                  ptr->Course1_ID    = cou1_ID;
                  ptr->Course1_grade = cou1_grd;
                  ptr->Course2_ID    = cou2_ID;
                  ptr->Course2_grade = cou2_grd;
                  ptr->Course3_ID    = cou3_ID;
                  ptr->Course3_grade = cou3_grd;
                  ptr->link          = start;
                  start              = ptr;
                  printf("\n\n\t\t\t*__________*Record Created Successfully*__________*\n\n");
          }


          }
 void SDB_ReadEntry(uint32 STD_ID)// function for reading data of list by using student ID (3)
{
    student* temp;
    temp = start;
    uint32 flag = 0;

    if (temp == NULL)
    {
             printf("the data base is empty\n");
    }
    else
    {
         while(temp != NULL)
    {
    if(temp->Student_ID == STD_ID)
    {
             printf("\n\t\t\t*__________the student data was found__________*\n");
             printf("\t\t\t*______________the student data is______________*\n\n");
             printf("1-the student ID is : %d\n",temp->Student_ID);
             printf("2-the student graduation year is : %d\n",temp->Student_Year);
             printf("3-course_1 ID is : %d\n",temp->Course1_ID);
             printf("4-course_1 grade is : %d\n",temp->Course1_grade);
             printf("5-course_2 ID is : %d\n",temp->Course2_ID);
             printf("6-course_2 grade is : %d\n",temp->Course2_grade);
             printf("7-course_3 ID is : %d\n",temp->Course3_ID);
             printf("8-course_3 grade is : %d\n",temp->Course3_grade);
             printf("\t\t\t*___________________________________________________*\n\n\n");
             flag = 0;
             break;

    }
    temp = temp->link;
    flag=1;
    }
    }
    if (flag == 1)
    {
             printf("the student ID is not exist\n");
    }
}
bool SDB_IsIdExist (uint32 Std_ID)// function to check if the ID is exist or not (4)
{
         student* temp = start;
         uint32 flag = 0 ;
         if (temp == NULL)
         {
                  return false;
         }
         else
         {
                  while(temp != NULL)
                  {
                           if (temp->Student_ID == Std_ID)
                  {
                           flag = 0;
                           return true;
                           break;
                  }
                 temp = temp->link;
                 flag = 1;
                  }
         }
         if(flag == 1)
         {
                  return false;
         }



}

void SDB_DeleteEntry (uint32 STD_ID)// function to delete student data by using student ID (6)
{
         student* ptr = NULL;// pointer that hold address of deleted node
         if(start->Student_ID == STD_ID)//if ID was found in the first node
         {
                  ptr = start;
                  start = start->link;
                  free(ptr);
                  ptr = NULL;
                  printf("\nthe student data was deleted successfuly\n\n");
         }
         else
         {
                  student* temp = start;
                  while(temp->link != NULL)
                  {
                           if(temp->link->Student_ID == STD_ID)
                           {
                                    ptr = temp->link;

                                    break;
                           }
                           temp = temp->link;
                  }
                  if(temp->link == NULL)
                  {

                           printf("\n %d was not found in your data base\n\n",STD_ID);
                  }
                  else
                  {

                           temp->link = ptr->link;
                           free(ptr);
                           ptr = NULL;
                           printf("\nthe student data was deleted successfuly\n\n");


                  }

         }

}

void SDB_GetList (uint8 *count)
{
         student* temp = start;
         *count = 0;
         while(temp != NULL)
         {
             ++ *count;
         temp = temp->link;
         }
         student* temp1 = start;
         while(temp1 != NULL)
         {
                  printf("%d\n",temp1->Student_ID);
                  temp1= temp1->link;
         }

         }


