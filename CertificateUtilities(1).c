/*****************************************************
 * 
 * Author:  CYBV310 Students and Instructor
 * Used a structure to manage the program better
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////
#define MAX_RDN_LENGTH     256
#define RDN_CN   "CN"
#define RDN_C    "C"
#define RDN_O    "O"
#define RDN_OU   "OU"
#define RDN_L    "L"
#define RDN_ST   "ST"

///////////////////////////////////////////////////////
//               typedefs and structures
//			provided structure by professor
///////////////////////////////////////////////////////
typedef struct
{
	char commonName[MAX_RDN_LENGTH];
	char organization[MAX_RDN_LENGTH];
	char country[MAX_RDN_LENGTH];
	char organizationalUnit[MAX_RDN_LENGTH];
	char locality[MAX_RDN_LENGTH];
	char state[MAX_RDN_LENGTH];
} DistinguishedName;

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////
char* TrimRight(char* str, const char* trimChars);
void printDistinguishedName(DistinguishedName* pName);
int GetRelativeDistinguishedName(char* rdnAttribute, char* rdnDescription, char* rdnValue);

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

int main(int argc, char **argv)
{
	DistinguishedName subjectName; // structure data allocated to subject named to later call specifics from structure.

	char distinguishedName[MAX_RDN_LENGTH * 6]; //apparently this has to still be there

	GetRelativeDistinguishedName(RDN_CN, "Common Name", subjectName.commonName); //using a pointer to reference structure data
	GetRelativeDistinguishedName(RDN_O,"Organization",  subjectName.organization);
	GetRelativeDistinguishedName(RDN_OU, "Organizational Unit", subjectName.organizationalUnit);
	GetRelativeDistinguishedName(RDN_C, "Country", subjectName.country);
	GetRelativeDistinguishedName(RDN_L, "Locality", subjectName.locality);
	GetRelativeDistinguishedName(RDN_ST, "State", subjectName.state);

	// Initialize the DN to zero length
	distinguishedName[0] = '\0';

	// print each attribute that has a value // new function
	printDistinguishedName(&subjectName); // in order to print it must reference subjectname (variable) to print correctly

	return 0;
}

/*****************************************************
 *
 * AddRelativeDistinguishedName
 *
******************************************************/
void printDistinguishedName(DistinguishedName *pName)
{
	char* separator = "";
	//moved print & if statements here, and created a pointer using pname. 
	printf("\r\nThe Distinguished Name (DN) is: ");
	if (strlen(pName->commonName) > 0)
	{
		printf("%s=%s", RDN_CN, pName->commonName);//pname takes the data from what it points to and prints, like a hierachy
		separator = ", ";
	}
	if (strlen(pName->organization) > 0)
	{
		printf("%s%s=%s", separator, RDN_O, pName->organization);
		separator = ", ";
	}
	if (strlen(pName->organizationalUnit) > 0)
	{
		printf("%s%s=%s", separator, RDN_OU, pName->organizationalUnit);
		separator = ", ";
	}
	if (strlen(pName->country) > 0)
	{
		printf("%s%s=%s", separator, RDN_C, pName->country);
		separator = ", ";
	}
	if (strlen(pName->locality) > 0)
	{
		printf("%s%s=%s", separator, RDN_L, pName->locality);
		separator = ", ";
	}
	if (strlen(pName->state) > 0)
	{
		printf("%s%s=%s", separator, RDN_ST, pName->state);
	}

	printf("\n\n");
}

/*****************************************************
 *
 * GetRelativeDistinguishedName
 *
******************************************************/
int GetRelativeDistinguishedName(char *rdnAttribute, char* rdnDescription, char *rdnValue)
{
	int result = -1;

	printf("Please enter the value for %s (%s): ", rdnDescription, rdnAttribute);
	fgets(rdnValue, MAX_RDN_LENGTH, stdin);
	if (strlen(rdnValue) > 0 )
	{
		TrimRight(rdnValue, NULL);
		result = 0;
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