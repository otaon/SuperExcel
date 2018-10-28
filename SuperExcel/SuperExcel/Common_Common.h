#ifndef COMMON_COMMON_H
#define COMMON_COMMON_H


/// header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// common const
#define true 1
#define false 0


/// error handling
#define HAS_ERROR(x) ((x) < 0)
#define RETURN_IF_ERROR(x)	if((x) < 0)puts("error")


/// error type
typedef enum Common_Error {
	COMMON_ERROR_NO_ERROR = 0,
	COMMON_ERROR_ERROR = -1,
	COMMON_ERROR_PRECONDITION_ERROR = -2,
	COMMON_ERROR_POSTCONDITION_ERROR = -3,
	COMMON_ERROR_NOT_VALIABLE_ERROR = -4,
	COMMON_ERROR_NOT_IMPLEMENTED_ERROR = -5
} Common_Error;


/// public methods
Common_Error Common_Common_AssertAreAllElementsZero(char[], int);
Common_Error Common_Common_AssertShowValidationError();
Common_Error Common_Common_CopyString(char*, char*, int);


#endif // !COMMON_COMMON_H