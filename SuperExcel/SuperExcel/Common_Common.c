#include "Common_Common.h"


Common_Error Common_Common_AssertAreAllElementsZero(char array[], int size)
{
	for (int i = 0; i < size; i++) {
		if (array[i] != 0) {
			printf("[ASSERTION_ERROR]: this array has NOT_ZERO element\n");
			return COMMON_ERROR_ERROR;
		}
	}

	return COMMON_ERROR_NO_ERROR;
}


Common_Error Common_Common_AssertShowValidationError()
{
	printf("[ASSERTION_ERROR]: VALIDATION_ERROR occurred\n");
	return COMMON_ERROR_ERROR;
}


Common_Error Common_Common_CopyString(char* src, char* dst, int dst_size)
{
	for (int i = 0; i < dst_size; i++) {
		if (src[i] == '\0')
			return COMMON_ERROR_NO_ERROR;

		dst[i] = src[i];
	}

	return COMMON_ERROR_ERROR;
}
