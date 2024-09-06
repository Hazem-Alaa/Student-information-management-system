#include <stdio.h>
#include "STD.h"
#include "SDB.h"


int main(void)
{
    #if Debug_Mode == 1 //to ON and OFF the program 
	SDB_APP();
	#endif
	
	return 0;
}

