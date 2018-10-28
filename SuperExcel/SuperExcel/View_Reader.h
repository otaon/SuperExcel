#ifndef VIEW_READER_H
#define VIEW_READER_H


/// public constances
#define VIEW_READER_BUF_SIZE 256		// 入力文字列サイズ
#define VIEW_READER_COMMNAD_SIZE 256	// コマンドサイズ
#define VIEW_READER_ARGUMENT_SIZE 256	// 引数サイズ
#define VIEW_READER_COMMAND_NUM_MAX 1	// コマンドの個数上限
#define VIEW_READER_ARG_NUM_MAX 2		// 引数の個数上限
#define VIEW_READER_COMMAND_ARG_NUM_MAX (VIEW_READER_COMMAND_NUM_MAX + VIEW_READER_ARG_NUM_MAX)	// コマンドと引数の合計個数上限


/// public member
typedef struct View_Reader {
	int input_num;
	char command[VIEW_READER_COMMNAD_SIZE];	//  入力文字列(コマンド)
	char arg1[VIEW_READER_ARGUMENT_SIZE];		//  入力文字列(引数1)
	char arg2[VIEW_READER_ARGUMENT_SIZE];		//  入力文字列(引数2)
} View_Reader;


/// public methods
Common_Error View_Reader_Read(View_Reader*);


#endif	// !VIEW_READER_H