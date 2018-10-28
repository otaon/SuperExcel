#include "Common_Common.h"
#include "View_Reader.h"
#include "Controller_Enum_Commands.h"
#include "Controller_Argument.h"
#include "View_Viewer.h"

/// プライベートメソッド
static Common_Error REPL();
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
		RETURN_IF_ERROR(err = ConvertStringToArgumentsToken(view_Reader.command, &view_Reader.arg1, &arg1, &view_Reader.arg2, &arg2));

		// execute
		RETURN_IF_ERROR(err = View_Viewer_Init(&view_Viewer));
		RETURN_IF_ERROR(err = Evaluate(&view_Reader, &view_Viewer));

		/* Print */
		// execute
		RETURN_IF_ERROR(err = View_Viewer_Print(&view_Viewer));
	} while (!HAS_ERROR(err));
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
	//int arg_selector;
	//int rows;
	//char filename[CONTROLLER_ARGUMENT_FILE_NAME_SIZE];
	//int characters;
	//double value_double;
	//char value_string[CONTROLLER_ARGUMENT_VALUE_SIZE];
	//Controller_Cell cell;

	/*********************************************
	# File Commands

	NEW rows columns
	Commands Cell Cell
		Create a new spreadsheet with the given number of rows and columns.

	LOAD filename
	Commands char[]
		Load data into the worksheet from filename.

	SAVE filename
	Commands char[]
		Save the current worksheet to filename, overwriting any existing file.

	EXIT
	Commands
		Exit the program.

	----------------------------------------------
	# Viewport Control
	CURSOR cell
	Commands Cell
		Move the cursor to the given cell.

	PREC digits
	Commands int
		Display numbers with digits places after the decimal point.

	WIDTH characters
	Commands int
		Display each cell characters wide.

	----------------------------------------------
	# Data Manipulation
	SET cell value
	Commands double
	Commands char[]
		Set the value of the given cell, overwriting any existing value.

	SET cell
	Commands Cell
		Erase the value of the given cell.

	SUM cell1 cell2
	Commands Cell Cell
		Compute the sum of all of the numeric values in the rectangle bounded by cell1 and cell2.

	AVG cell1 cell2
	Commands Cell Cell
		Compute the average (arithmetic mean) of all of the numeric values in the rectangle bounded by cell1 and cell2.
	*********************************************/

	int is_success = false;

	switch (cmd) {
	case Controller_Enum_Commands_Exit:
		// do nothing
		return;
	case Controller_Enum_Commands_New:
		break;
	case Controller_Enum_Commands_Load:
		break;
	case Controller_Enum_Commands_Save:
		break;
	case Controller_Enum_Commands_Cursor:
		break;
	case Controller_Enum_Commands_Prec:
		break;
	case Controller_Enum_Commands_Width:
		break;
	case Controller_Enum_Commands_Set:
		break;
	case Controller_Enum_Commands_Erase:
		break;
	case Controller_Enum_Commands_Sum:
		break;
	case Controller_Enum_Commands_Avg:
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

static Common_Error TryConvertArgumentTo(int* is_success)
{

}