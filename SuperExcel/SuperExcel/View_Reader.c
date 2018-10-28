#include "Common_Common.h"
#include "View_Reader.h"


/// private methods declaration
static Common_Error Init(View_Reader*);
static Common_Error Read(int*, char[], char[], char[]);


/// public methods
// reader of REPL
Common_Error View_Reader_Read(View_Reader* this)
{
	Common_Error err;

	Init(this);

	// precondition check
	if (this->input_num != 0) {
		Common_Common_AssertShowValidationError();
		return COMMON_ERROR_PRECONDITION_ERROR;
	}
	if (Common_Common_AssertAreAllElementsZero(this->command, VIEW_READER_COMMNAD_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;

	if (Common_Common_AssertAreAllElementsZero(this->arg1, VIEW_READER_ARGUMENT_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;
	
	if (Common_Common_AssertAreAllElementsZero(this->arg2, VIEW_READER_ARGUMENT_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;

	return Read(&this->input_num, this->command, this->arg1, this->arg2);
}


/// private methods

// initialize
static Common_Error Init(View_Reader* this)
{
	this->input_num = 0;

	for (int i = 0; i < VIEW_READER_COMMNAD_SIZE; i++)
		this->command[i] = 0;

	for (int i = 0; i < VIEW_READER_ARGUMENT_SIZE; i++)
		this->arg1[i] = 0;

	for (int i = 0; i < VIEW_READER_ARGUMENT_SIZE; i++)
		this->arg2[i] = 0;

	return COMMON_ERROR_NO_ERROR;
}


static Common_Error Read(int* input_num, char command[], char arg1[], char arg2[])
{
	char buffer[VIEW_READER_BUF_SIZE] = { 0 };
	char* token;
	char* next_token = NULL;


	// precondition check
	if (Common_Common_AssertAreAllElementsZero(command, VIEW_READER_COMMNAD_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;

	if (Common_Common_AssertAreAllElementsZero(arg1, VIEW_READER_ARGUMENT_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;

	if (Common_Common_AssertAreAllElementsZero(arg2, VIEW_READER_ARGUMENT_SIZE))
		return COMMON_ERROR_PRECONDITION_ERROR;


	// show prompt
	printf(">> ");

	// receive input from user
	if (gets_s(buffer, VIEW_READER_BUF_SIZE) <= 0)
		return COMMON_ERROR_NO_ERROR;

	// 1st token (command)
	if (!(token = strtok_s(buffer, " \n", &next_token)))
		return COMMON_ERROR_NO_ERROR;

	Common_Common_CopyString(token, command, VIEW_READER_BUF_SIZE);
	(*input_num)++;

	// 2nd token (argument1)
	if (!(token = strtok_s(NULL, " \n", &next_token)))
		return COMMON_ERROR_NO_ERROR;

	Common_Common_CopyString(token, arg1, VIEW_READER_BUF_SIZE);
	(*input_num)++;

	// 3rd token (argument2)
	if (!(token = strtok_s(NULL, " \n", &next_token)))
		return COMMON_ERROR_NO_ERROR;

	Common_Common_CopyString(token, arg2, VIEW_READER_BUF_SIZE);
	(*input_num)++;


	// postcondition check
	if (!(0 <= *input_num && *input_num <= VIEW_READER_COMMAND_ARG_NUM_MAX)) {
		Common_Common_AssertShowValidationError();
		return COMMON_ERROR_POSTCONDITION_ERROR;
	}

	return COMMON_ERROR_NO_ERROR;
}
