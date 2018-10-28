#ifndef VIEW_VIEWER_H
#define VIEW_VIEWER_H

/// public constances
#define VIEW_VIEWER_BUF_SIZE 256		// 入力文字列サイズ
#define VIEW_VIEWER_COMMNAD_SIZE 256	// コマンドサイズ
#define VIEW_VIEWER_ARGUMENT_SIZE 256	// 引数サイズ
#define VIEW_VIEWER_COMMAND_NUM_MAX 1	// コマンドの個数上限
#define VIEW_VIEWER_ARG_NUM_MAX 2		// 引数の個数上限
#define VIEW_VIEWER_COMMAND_ARG_NUM_MAX (VIEW_VIEWER_COMMNAD_SIZE + VIEW_VIEWER_ARG_NUM_MAX)	// コマンドと引数の合計個数上限


/// public member
typedef struct View_Viewer {
	int input_num;
	char command[VIEW_VIEWER_COMMNAD_SIZE];	//  入力文字列(コマンド)
	char arg1[VIEW_VIEWER_ARGUMENT_SIZE];		//  入力文字列(引数1)
	char arg2[VIEW_VIEWER_ARGUMENT_SIZE];		//  入力文字列(引数2)
} View_Viewer;


/// public methods
Common_Error View_Viewer_Init(View_Viewer*);
Common_Error View_Viewer_Print(View_Viewer*);

#endif	// !VIEW_VIEWER_H
