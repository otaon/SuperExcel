#ifndef CONTROLLER_ARGUMENT_H
#define CONTROLLER_ARGUMENT_H

#include "Common_Common.h"
#include "Controller_Cell.h"

/// public constances
#define CONTROLLER_ARGUMENT_FILE_NAME_SIZE 256	// ファイル名サイズ
#define CONTROLLER_ARGUMENT_VALUE_SIZE 256		// セル文字列サイズ


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
