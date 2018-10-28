#include "Common_Common.h"
#include "View_Viewer.h"

/// private methods declear
static Common_Error Print(View_Viewer*);


/// private methods
// initialize
Common_Error View_Viewer_Init(View_Viewer* this)
{
	this->input_num = 0;

	for (int i = 0; i < VIEW_VIEWER_COMMNAD_SIZE; i++)
		this->command[i] = 0;

	for (int i = 0; i < VIEW_VIEWER_ARGUMENT_SIZE; i++)
		this->arg1[i] = 0;

	for (int i = 0; i < VIEW_VIEWER_ARGUMENT_SIZE; i++)
		this->arg2[i] = 0;

	return COMMON_ERROR_NO_ERROR;
}


// printer of REPL
Common_Error View_Viewer_Print(View_Viewer* this)
{
	return Print(this);
}


static Common_Error Print(View_Viewer* this)
{
	if (this->input_num <= 0) {
		printf("no valid input\n");
		return COMMON_ERROR_NOT_VALIABLE_ERROR;
	}

	if (this->input_num >= 1)
		printf("command: %s\n", this->command);

	if (this->input_num >= 2)
		printf("arg1: %s\n", this->arg1);

	if (this->input_num >= 3)
		printf("arg2: %s\n", this->arg2);

	return COMMON_ERROR_NO_ERROR;
}
