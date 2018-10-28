#ifndef CONTROLLER_ENUM_COMMANDS_H
#define CONTROLLER_ENUM_COMMANDS_H

typedef enum Controller_Enum_Commands {
	Controller_Enum_Commands_Unknown = -1,
	Controller_Enum_Commands_Exit = 0,	// REPLÇ…ï]âøÇ≥ÇπÇΩÇ∆Ç´Ç…ÉãÅ[ÉvÇî≤ÇØÇÈ
	Controller_Enum_Commands_New,
	Controller_Enum_Commands_Load,
	Controller_Enum_Commands_Save,
	Controller_Enum_Commands_Cursor,
	Controller_Enum_Commands_Prec,
	Controller_Enum_Commands_Width,
	Controller_Enum_Commands_Set,
	Controller_Enum_Commands_Erase,
	Controller_Enum_Commands_Sum,
	Controller_Enum_Commands_Avg
} Controller_Enum_Commands;


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



#endif // !CONTROLLER_ENUM_COMMANDS_H