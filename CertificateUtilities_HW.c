/*****************************************************
 * 
 * Author:  CYBV310 Students and Instructor
 * Stewart
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
// *Defined several new constants replace hard strings
//  with something easier to remember/use.*
///////////////////////////////////////////////////////
#define MAX_LENGTH 256
#define DFN_CN "CN"
#define DFN_O "O"
#define DFN_C "C"
#define DFN_OU "OU"
#define DFN_ST "ST"
#define DFN_L "L"
#define Description_CN "Common Name"
#define Description_O "Organization"
#define Description_C "Country"
#define Description_OU "Organization Unit"
#define Description_ST "State"
#define Description_L "Location"
///////////////////////////////////////////////////////
//               typedefs and structures
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
//		*added these functions so that the program
//		 knows in advance what to expect going forth.*
///////////////////////////////////////////////////////
char* TrimRight(char* str, const char* trimChars);
int GetRelativeDistinguishedName(char* rdnAttribute, char* rdnValue, char* rdndescription);

///////////////////////////////////////////////////////
//                FunctionPrototypes
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
// added extra variables or even questions for the user to answer.
int main(int argc, char **argv)
{
	char commonName[MAX_LENGTH];
	char organization[MAX_LENGTH];
	char country[MAX_LENGTH];
	char organizationUnit[MAX_LENGTH];
	char state[MAX_LENGTH];
	char location[MAX_LENGTH];

	// here the user will see a description of each constant
	GetRelativeDistinguishedName(DFN_CN, commonName, Description_CN);
	GetRelativeDistinguishedName(DFN_O, organization, Description_O);
	GetRelativeDistinguishedName(DFN_C, country, Description_C);
	GetRelativeDistinguishedName(DFN_OU, organizationUnit, Description_OU);
	GetRelativeDistinguishedName(DFN_ST, state, Description_ST);
	GetRelativeDistinguishedName(DFN_L, location, Description_L);

	// if the user inputs no value, then it will not show in the final print statement
	printf("\r\nThe Distinguished Name (DN) is: ");
	if (strlen(commonName) > 0)
	{
		printf("%s=%s,", DFN_CN, commonName);
	}
	if (strlen(organization) > 0)
	{
		printf("%s=%s,", DFN_O, organization);
	}
	if (strlen(country) > 0)
	{
		printf("%s=%s,", DFN_C, country);
	}
	if (strlen(organizationUnit) > 0)
	{
		printf("%s=%s,", DFN_CN, organizationUnit);
	}
	if (strlen(state) > 0)
	{
		printf("%s=%s,", DFN_ST, state);
	}
	if (strlen(location) > 0)
	{
		printf("%s=%s,", DFN_L, location);
	} 

	return 0;
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char *rdnValue, char *rdndescription)
{
	int result = -1;

	rdnValue[0] = '\0';
	// helps the program recieve user input, read, and print it in a meaningful way. 
	printf("Please enter the value for %s (%s): ", rdndescription, rdnAttribute);
	fgets(rdnValue, 256, stdin);
	if (strlen(rdnValue) > 0 )
	{
		TrimRight(rdnValue, NULL);
		
		result = strlen(rdnValue);
	}

    return result;
}

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
	int i;

	if (trimChars == NULL)
	{
		trimChars = "\t\n\v\f\r ";
	}

	i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL)
	{
		str[i] = '\0';
		i--;
	}

	return str;
}
