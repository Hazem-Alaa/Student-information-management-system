#ifndef SDB_h
#define SDB_h

#define Debug_Mode 1
#define Num_Student 10
#define start  3
#define Initial  0

struct school 
{
	uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
};
typedef struct school  SimpleDb;

bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList();
bool SDB_IsIdExist(uint32 id);
void SDB_APP();
void SDB_action(uint8 choice);


#endif