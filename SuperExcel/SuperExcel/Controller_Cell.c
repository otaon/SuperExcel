#include "Controller_Cell.h"

Common_Error Controller_Cell_Init(Controller_Cell* this)
{
	this->row = 0;
	this->column = 0;

	return COMMON_ERROR_NO_ERROR;
}
