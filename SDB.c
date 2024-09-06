#include "STD.h"
#include "SDB.h"

#include <stdio.h>


SimpleDb database[Num_Student];

/* this function check the database is full or 
not(if full return : 1 ,not full return : 0) */
bool SDB_IsFull()
{
	for(int32 i=Initial;i<Num_Student;i++)
	{
		if(database[i].Student_ID==Initial)
		{
			return false;
		}
	}
	return true;
}

/* this function count the number student in database 
and return the number to function */
uint8 SDB_GetUsedSize()
{
	int32 count=Initial;
	for(int32 i=Initial;i<Num_Student;i++)
	{
		if(database[i].Student_year!=Initial)
		{
			count++;
		}
	}
	return count;
}

/* this function add student in database
and return the true if add student  */
bool SDB_AddEntry()
{
	static int32 i=start;
	if(i<Num_Student)
	{
		printf("enter the Student_ID=\n");
		scanf("%d",&database[i].Student_ID);
		while((int32)database[i].Student_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Student_ID);	
		}
		
		
		printf("enter the Student_year=\n");
		scanf("%d",&database[i].Student_year);
		while((int32)database[i].Student_year<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Student_year);	
		}
		
		
		printf("enter the Course1_ID=\n");
		scanf("%d",&database[i].Course1_ID);
		while((int32)database[i].Course1_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course1_ID);	
		}
		
		
		printf("enter the Course1_grade=\n");
		scanf("%d",&database[i].Course1_grade);
		while((int32)database[i].Course1_grade<Initial)/*castin the database because we can't compare 
		                                                 between the signed and unsigned*/ 
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course1_grade);	
		}
		
		
		printf("enter the Course2_ID=\n");
		scanf("%d",&database[i].Course2_ID);
		while((int32)database[i].Course2_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course2_ID);	
		}
		
			
		printf("enter the Course2_grade=\n");
		scanf("%d",&database[i].Course2_grade);
		while((int32)database[i].Course2_grade<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course2_grade);	
		}
		
		
		printf("enter the Course3_ID=\n");
		scanf("%d",&database[i].Course3_ID);
		while((int32)database[i].Course3_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course3_ID);	
		}
		
		
		printf("enter the Course3_grade=\n");
		scanf("%d",&database[i].Course3_grade);
		while((int32)database[i].Course3_grade<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course3_grade);	
		}
		i++;
		return true;
	}
	else 
	{
		return false;
	}	
}
/* this function take ID student and delet
 from database */
void SDB_DeletEntry(uint32 id)
{
	int flag=0;
	for(int i=Initial;i<Num_Student;i++)
	{
		if(id==database[i].Student_ID)
		{
			database[i].Student_ID=0;
			database[i].Student_year=0;
			database[i].Course1_ID=0;
			database[i].Course1_grade=0;
			database[i].Course2_ID=0;
			database[i].Course2_grade=0;
			database[i].Course3_ID=0;
			database[i].Course3_grade=0;	
			printf("Done deleted\n");
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("This student does not exist\n");
	}
}

/* this function take ID student and show information 
about student*/
bool SDB_ReadEntry(uint32 id)
{
	int32 flag=0;
	for(int32 i=Initial;i<Num_Student;i++)
	{
		if(id==database[i].Student_ID)
		{
			printf("enter the Student_ID=%d\n",database[i].Student_ID);
			printf("enter the Student_year=%d\n",database[i].Student_year);
			printf("enter the Course1_ID=%d\n",database[i].Course1_ID);
			printf("enter the Course1_grade=%d\n",database[i].Course1_grade);
			printf("enter the Course2_ID=%d\n",database[i].Course2_ID);
			printf("enter the Course2_grade=%d\n",database[i].Course2_grade);
			printf("enter the Student_ID=%d\n",database[i].Course3_ID);
			printf("enter the Student_ID=%d\n",database[i].Course3_grade);	
			flag=1;
			return true;
		}
	}
	if(flag==0)
	{
		printf("This student does not exist\n");
		return false;
	}	
}
/* this function show all IDs student in database*/
void SDB_GetList()
{
	for(int i=Initial;i<Num_Student;i++)
	{
		printf("%d ",database[i].Student_ID);
	}
}

/* this function check the ID student exist in database or NO
(if exist return --> 1,and if not exist return --> 0)*/
bool SDB_IsIdExist(uint32 id)
{
	for(int i=Initial;i<Num_Student;i++)
	{
		if(id==database[i].Student_ID && id!=0)
		{
			return true;
		}
	}
	return false;
}
/* this function put in SDB_APP(), take option from user and jump
the function by switch case */

void SDB_action(uint8 choice)
{
	int32 flage=0;
	uint32 x,y,z;
	uint8 s;
	bool b;
	while(flage==0)
	{
		printf("Enter operation \n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 0:
			flage=1;
			break;
			
			case 1:
			SDB_AddEntry();
			break;
			
			case 2:
			s=SDB_GetUsedSize();
			printf("%d\n",s);
			break;
			
			case 3:
			printf("enter the id\n");
			scanf("%d",&x);
			bool w=SDB_ReadEntry(x);
			printf("%d\n",w);
			break;
			
			case 4:
			SDB_GetList();
			printf("\n");
			break;
			
			case 5:
			printf("enter the id\n");
			scanf("%d",&y);
			bool a=SDB_IsIdExist(y);
			printf("%d\n",a);
			break;
			
			case 6:
			printf("enter the id\n");
			scanf("%d",&z);
			SDB_DeletEntry(z);
			break;
			
			case 7:
			b=SDB_IsFull();
			printf("%d\n",b);
			break;
			
			default :
			printf("I don't have this feature , please ");
			break;
				
		}
		
	}	
}

/* this function put in main(), show options to user and call
SDB_action */
void SDB_APP()
{
	for(int i=Initial;i<start;i++)
	{
		printf("please ,enter 3 student\n");
		printf("enter the Student_ID=\n");
		scanf("%d",&database[i].Student_ID);
		while((int32)database[i].Student_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Student_ID);	
		}
		
		
		printf("enter the Student_year=\n");
		scanf("%d",&database[i].Student_year);
		while((int32)database[i].Student_year<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Student_year);	
		}
		
		
		printf("enter the Course1_ID=\n");
		scanf("%d",&database[i].Course1_ID);
		while((int32)database[i].Course1_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course1_ID);	
		}
		
		
		printf("enter the Course1_grade=\n");
		scanf("%d",&database[i].Course1_grade);
		while((int32)database[i].Course1_grade<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course1_grade);	
		}
		
		
		printf("enter the Course2_ID=\n");
		scanf("%d",&database[i].Course2_ID);
		while((int32)database[i].Course2_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course2_ID);	
		}
		
			
		printf("enter the Course2_grade=\n");
		scanf("%d",&database[i].Course2_grade);
		while((int32)database[i].Course2_grade<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course2_grade);	
		}
		
		
		printf("enter the Course3_ID=\n");
		scanf("%d",&database[i].Course3_ID);
		while((int32)database[i].Course3_ID<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course3_ID);	
		}
		
		
		printf("enter the Course3_grade=\n");
		scanf("%d",&database[i].Course3_grade);
		while((int32)database[i].Course3_grade<Initial)
		{
			printf("please enter the correct number =");
			scanf("%d",&database[i].Course3_grade);	
		}	
	}
	
	uint8 choice;
	printf("To add entry, enter 1\n");
	printf("To get used size in database, enter 2\n");
	printf("To read student data, enter 3\n");
	printf("To get the list of all student IDs, enter 4\n");
	printf("To check is ID is existed, enter 5\n");
	printf("To delete student data, enter 6\n");
	printf("To check is database is full, enter 7\n");
	printf("To exit enter 0\n");
	
	SDB_action(choice);

}




