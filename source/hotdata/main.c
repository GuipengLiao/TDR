#include "hotpot/hp_getopt.h"
#include "hotpot/hp_error.h"
#include "globals.h"

#include "encoding/ddekit_json_encoding_writer.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hotdata_parser.h"


const char* const short_options = "?h:i:c:";

const struct option long_options[] =
{
	{ "help",					0, NULL, '?' },		//�鿴����



	{ "include",				1, NULL, 'i' },		//���ð����ļ�Ŀ¼
	
	{ "c_hotpot",				1, NULL, 'c' },		//���c����ͷ�ļ�

	{ NULL,						0, NULL, 0     }
};//���һ��Ԫ�ر�ʶΪNULL

typedef void (*FUNC) (const char*, const char*);
#define MAX_FUNC_NUM 1024

int g_gen_c_hotpot = FALSE;
char g_gen_c_hotpot_output_path[HP_MAX_FILE_PATH_LENGTH];

DATA_PARSER dp;

JSON_WRITER jw;

int main(int argc, char **argv)
{
	int i;
	int oc;	
	FILE *fout;
	fout = fopen("d:/ast_base.out", "w");
	ddekit_json_encoding_writer_init(&jw, fout);

	
	while((oc = hp_getopt_long (argc, argv, short_options, long_options, NULL)) != -1)
	{
		switch (oc)
		{
		case '?':
			//need useage
			break;
		case 'i':
			break;		
		case 'c':
			g_gen_c_hotpot = TRUE;
			strncpy(g_gen_c_hotpot_output_path, hp_optarg, HP_MAX_FILE_PATH_LENGTH);
			break;
		default:
			break;
		}
	}


	for(i = hp_optind; i < argc; ++i)
	{
		if(data_parser(&dp, argv[i], &jw) == E_HP_NOERROR)
		{
			printf("succeed\n");
		}
		else
		{
			printf("failed\n");
		}
	}
	fclose(fout);
	return 0;
}
