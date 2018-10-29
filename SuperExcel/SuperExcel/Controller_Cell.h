#ifndef CONTROLLER_CELL_H
#define CONTROLLER_CELL_H


#include "Common_Common.h"

typedef struct Controller_Cell {
	int column;
	int row;
} Controller_Cell;


/// public methods
Common_Error Controller_Cell_Init(Controller_Cell*);


#endif // !CONTROLLER_CELL_H
