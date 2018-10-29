#include "Common_Common.h"
#include "Controller_Argument.h"


Common_Error Controller_Argument_Init(Controller_Argument* this)
{
	this->arg_selector = CONTOLLER_ARGUMENT_NONE;
	this->rows = 0;
	for (int i = 0; i < CONTROLLER_ARGUMENT_FILE_NAME_SIZE; i++)
		this->filename[i] = 0;
	this->characters = 0;
	this->value_double = 0.0;
	for (int i = 0; i < CONTROLLER_ARGUMENT_VALUE_SIZE; i++)
		this->value_string[i] = 0;
	Controller_Cell_Init(&this->cell);

	return COMMON_ERROR_NO_ERROR;
}