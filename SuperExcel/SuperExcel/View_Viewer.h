#ifndef VIEW_VIEWER_H
#define VIEW_VIEWER_H

/// public constances
#define VIEW_VIEWER_BUF_SIZE 256		// ���͕�����T�C�Y
#define VIEW_VIEWER_COMMNAD_SIZE 256	// �R�}���h�T�C�Y
#define VIEW_VIEWER_ARGUMENT_SIZE 256	// �����T�C�Y
#define VIEW_VIEWER_COMMAND_NUM_MAX 1	// �R�}���h�̌����
#define VIEW_VIEWER_ARG_NUM_MAX 2		// �����̌����
#define VIEW_VIEWER_COMMAND_ARG_NUM_MAX (VIEW_VIEWER_COMMNAD_SIZE + VIEW_VIEWER_ARG_NUM_MAX)	// �R�}���h�ƈ����̍��v�����


/// public member
typedef struct View_Viewer {
	int input_num;
	char command[VIEW_VIEWER_COMMNAD_SIZE];	//  ���͕�����(�R�}���h)
	char arg1[VIEW_VIEWER_ARGUMENT_SIZE];		//  ���͕�����(����1)
	char arg2[VIEW_VIEWER_ARGUMENT_SIZE];		//  ���͕�����(����2)
} View_Viewer;


/// public methods
Common_Error View_Viewer_Init(View_Viewer*);
Common_Error View_Viewer_Print(View_Viewer*);

#endif	// !VIEW_VIEWER_H
