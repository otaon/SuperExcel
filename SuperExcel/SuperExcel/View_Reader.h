#ifndef VIEW_READER_H
#define VIEW_READER_H


/// public constances
#define VIEW_READER_BUF_SIZE 256		// ���͕�����T�C�Y
#define VIEW_READER_COMMNAD_SIZE 256	// �R�}���h�T�C�Y
#define VIEW_READER_ARGUMENT_SIZE 256	// �����T�C�Y
#define VIEW_READER_COMMAND_NUM_MAX 1	// �R�}���h�̌����
#define VIEW_READER_ARG_NUM_MAX 2		// �����̌����
#define VIEW_READER_COMMAND_ARG_NUM_MAX (VIEW_READER_COMMAND_NUM_MAX + VIEW_READER_ARG_NUM_MAX)	// �R�}���h�ƈ����̍��v�����


/// public member
typedef struct View_Reader {
	int input_num;
	char command[VIEW_READER_COMMNAD_SIZE];	//  ���͕�����(�R�}���h)
	char arg1[VIEW_READER_ARGUMENT_SIZE];		//  ���͕�����(����1)
	char arg2[VIEW_READER_ARGUMENT_SIZE];		//  ���͕�����(����2)
} View_Reader;


/// public methods
Common_Error View_Reader_Read(View_Reader*);


#endif	// !VIEW_READER_H