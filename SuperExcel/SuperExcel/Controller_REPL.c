#include "Common_Common.h"
#include "View_Reader.h"
#include "Controller_Enum_Commands.h"
#include "Controller_Argument.h"
#include "View_Viewer.h"

/// プライベートメソッド
static Common_Error REPL();
static Common_Error ConvertStringToCommandToken(char[], Controller_Enum_Commands*);
static Common_Error ConvertStringToArgumentsToken(Controller_Enum_Commands, char[], Controller_Argument*, char[], Controller_Argument*);
static Common_Error TryConvertArgumentToCell(int*, char[], Controller_Argument*);
static Common_Error Evaluate(View_Reader*, View_Viewer*);


/// プログラムのエントリポイント
int main()
{
	printf("+---------------------------+\n");
	printf("|     Super Excel REPL      |\n");
	printf("+---------------------------+\n");

	REPL();

	printf("Bye\n\n");

	return 0;
}


/// REPL本体
static Common_Error REPL()
{
	View_Reader view_Reader;
	View_Viewer view_Viewer;
	Controller_Enum_Commands cmd;
	Controller_Argument arg1;
	Controller_Argument arg2;
	Common_Error err;

	// REPL実行
	do {
		/* Read */
		// execute
		RETURN_IF_ERROR(err = View_Reader_Read(&view_Reader));

		/* Eval */
		// prepare
		RETURN_IF_ERROR(err = ConvertStringToCommandToken(view_Reader.command, &cmd));
		RETURN_IF_ERROR(err = ConvertStringToArgumentsToken(cmd, view_Reader.arg1, &arg1, view_Reader.arg2, &arg2));

		// execute
		RETURN_IF_ERROR(err = View_Viewer_Init(&view_Viewer));
		RETURN_IF_ERROR(err = Evaluate(&view_Reader, &view_Viewer));

		/* Print */
		// execute
		RETURN_IF_ERROR(err = View_Viewer_Print(&view_Viewer));
	} while (!HAS_ERROR(err));

	return COMMON_ERROR_NO_ERROR;
}


static Common_Error ConvertStringToCommandToken(char str[], Controller_Enum_Commands* cmd)
{
	if (strcmp(str, "NEW") == 0)
		*cmd = Controller_Enum_Commands_New;
	else if (strcmp(str, "LOAD") == 0)
		*cmd = Controller_Enum_Commands_Load;
	else if (strcmp(str, "SAVE") == 0)
		*cmd = Controller_Enum_Commands_Save;
	else if (strcmp(str, "EXIT") == 0)
		*cmd = Controller_Enum_Commands_Exit;
	else if (strcmp(str, "CURSOR") == 0)
		*cmd = Controller_Enum_Commands_Cursor;
	else if (strcmp(str, "PREC") == 0)
		*cmd = Controller_Enum_Commands_Prec;
	else if (strcmp(str, "WIDTH") == 0)
		*cmd = Controller_Enum_Commands_Width;
	else if (strcmp(str, "SET") == 0)
		*cmd = Controller_Enum_Commands_Set;
	else if (strcmp(str, "ERASE") == 0)
		*cmd = Controller_Enum_Commands_Erase;
	else if (strcmp(str, "SUM") == 0)
		*cmd = Controller_Enum_Commands_Sum;
	else if (strcmp(str, "AVG") == 0)
		*cmd = Controller_Enum_Commands_Avg;
	else
		*cmd = Controller_Enum_Commands_Unknown;

	return COMMON_ERROR_NO_ERROR;
}


static Common_Error ConvertStringToArgumentsToken(Controller_Enum_Commands cmd, char arg_str1[], Controller_Argument *arg1, char arg_str2[], Controller_Argument *arg2)
{
	Common_Error err;

	//int arg_selector;
	//int rows;
	//char filename[CONTROLLER_ARGUMENT_FILE_NAME_SIZE];
	//int characters;
	//double value_double;
	//char value_string[CONTROLLER_ARGUMENT_VALUE_SIZE];
	//Controller_Cell cell;

	int is_success = false;

	switch (cmd) {
	case Controller_Enum_Commands_Exit:
		//EXIT
		//Commands
		//	Exit the program.
		// do nothing
		break;
	case Controller_Enum_Commands_New:
		//NEW rows columns
		//Commands Cell Cell
		//	Create a new spreadsheet with the given number of rows and columns.
		RETURN_IF_ERROR(err = TryConvertArgumentToCell(&is_success, arg_str1, arg1));
		RETURN_IF_ERROR(err = TryConvertArgumentToCell(&is_success, arg_str2, arg2));
		break;
	case Controller_Enum_Commands_Load:
		//LOAD filename
		//Commands char[]
		//	Load data into the worksheet from filename.
		break;
	case Controller_Enum_Commands_Save:
		//SAVE filename
		//Commands char[]
		//	Save the current worksheet to filename, overwriting any existing file.
		break;
	case Controller_Enum_Commands_Cursor:
		//CURSOR cell
		//Commands Cell
		//	Move the cursor to the given cell.
		break;
	case Controller_Enum_Commands_Prec:
		//PREC digits
		//Commands int
		//	Display numbers with digits places after the decimal point.
		break;
	case Controller_Enum_Commands_Width:
		//WIDTH characters
		//Commands int
		//	Display each cell characters wide.
		break;
	case Controller_Enum_Commands_Set:
		//SET cell value
		//Commands double
		//Commands char[]
		//	Set the value of the given cell, overwriting any existing value.
		break;
	case Controller_Enum_Commands_Erase:
		//SET cell
		//Commands Cell
		//	Erase the value of the given cell.
		break;
	case Controller_Enum_Commands_Sum:
		//SUM cell1 cell2
		//Commands Cell Cell
		//	Compute the sum of all of the numeric values in the rectangle bounded by cell1 and cell2.
		break;
	case Controller_Enum_Commands_Avg:
		//AVG cell1 cell2
		//Commands Cell Cell
		//	Compute the average (arithmetic mean) of all of the numeric values in the rectangle bounded by cell1 and cell2.
		break;
	case Controller_Enum_Commands_Unknown:
		// do nothing
		break;
	default:
		// do nothing
		break;
	}

	return COMMON_ERROR_NO_ERROR;
}


static Common_Error TryConvertArgumentToCell(int* is_success, char arg_str[], Controller_Argument* arg)
{
	char c = '\0';
	int d = 0;

	*is_success = false;

	Controller_Argument_Init(arg);

	if (arg_str[0] == '\0') {
		return COMMON_ERROR_NO_ERROR;
	}

	c = arg_str[0];

	if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))) {
		return COMMON_ERROR_NO_ERROR;
	}

	if ('A' <= c && c <= 'Z') {
		c = c - 'A' + 1;
	}

	if ('a' <= c && c <= 'z') {
		c = c - 'a' + 1;
	}

	d = atoi(&arg_str[1]);

	if (d == 0) {
		return COMMON_ERROR_NO_ERROR;
	}

	arg->arg_selector = CONTOLLER_ARGUMENT_CELL;
	arg->cell.column = (int)c;
	arg->cell.row = d;

	*is_success = true;
	return COMMON_ERROR_NO_ERROR;
}


static Common_Error Evaluate(View_Reader* view_Reader, View_Viewer* view_Viewer)
{
	// Stub
	view_Viewer->input_num = view_Reader->input_num;
	for (int i = 0; i < VIEW_VIEWER_COMMNAD_SIZE; i++)
		view_Viewer->command[i] = view_Reader->command[i];

	for (int i = 0; i < VIEW_VIEWER_ARGUMENT_SIZE; i++)
		view_Viewer->arg1[i] = view_Reader->arg1[i];

	for (int i = 0; i < VIEW_VIEWER_ARGUMENT_SIZE; i++)
		view_Viewer->arg2[i] = view_Reader->arg2[i];

	return COMMON_ERROR_NO_ERROR;
}
