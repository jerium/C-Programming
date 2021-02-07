/*****************************************************
 *
 * Author:  CYBV310 Students and Instructor
 * This program contains the first 3 parts of Excercise #2
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char** argv)
{
	printf("Starting:\n"); // initalizing phrase

	int a; //start of for statement that counts to 10. Adds 1 to inital value until it is 10, then stops.

	for (a = 1; a < 11; ++a)
	{
		printf("%d\n", a);
	}
	
	printf("Done!\n"); // initalizing phrase
	printf("\n"); // Break
	printf("\n"); // Break
	printf("\n"); // Break

	printf("Starting again:\n"); 

	one_three(); //Using one function to call another.

	printf("Yay!\n");

	printf("\n");
	printf("\n");
	printf("\n");

	printf("Now counting size of data types:\n");
	counting(); //Size in bytes of data types
	printf("Done.\n");
	return 0;
}

int one_three()
{
	printf("One.\n");
	two(); //Using one function to call another.
	printf("Three.\n");
}

int two()
{
	printf("Two.\n");
}

int counting()
{
	printf("Char: %d\n", sizeof(char)); //size of function to find value in 
	printf("Unsigned Char: %d\n", sizeof(unsigned char));
	printf("Short: %d\n", sizeof(short));
	printf("Unsigned short: %d\n", sizeof(unsigned short));
	printf("Int: %d\n", sizeof(int));
	printf("Unsigned Int: %d\n", sizeof(unsigned int));
	printf("Long: %d\n", sizeof(long));
	printf("Unsigned Long: %d\n", sizeof(unsigned long));
	printf("Float: %d\n", sizeof(float));
	printf("Double: %d\n", sizeof(double));
}