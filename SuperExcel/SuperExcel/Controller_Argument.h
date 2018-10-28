#ifndef CONTROLLER_ARGUMENT_H
#define CONTROLLER_ARGUMENT_H

#include "Common_Common.h"
#include "Controller_Cell.h"

/// public constances
#define CONTROLLER_ARGUMENT_FILE_NAME_SIZE 256	// �t�@�C�����T�C�Y
#define CONTROLLER_ARGUMENT_VALUE_SIZE 256		// �Z��������T�C�Y


typedef struct Controller_Argument {
	int arg_selector;
	int rows;
	char filename[CONTROLLER_ARGUMENT_FILE_NAME_SIZE];
	int characters;
	double value_double;
	char value_string[CONTROLLER_ARGUMENT_VALUE_SIZE];
	Controller_Cell cell;
} Controller_Argument;


Common_Error Controller_Argument_Init(Controller_Argument*);

#endif // !CONTROLLER_ARGUMENT_H
