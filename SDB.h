#ifndef SDB_H_
#define SDB-H-
#include"STD.h"
#define MAX_STUDENT_DATA  10 // max size of data base
#define MIN_STUDENT_DATA  3  // min size of data base

typedef struct SimpleDb
{
         uint32 Student_ID;
         uint32 Student_Year;
         uint32 Course1_ID;
         uint32 Course1_grade;
         uint32 Course2_ID;
         uint32 Course2_grade;
         uint32 Course3_ID;
         uint32 Course3_grade;

         struct SimpleDb* link;

}student;

#endif // SDB_H_
