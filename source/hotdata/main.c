#include "hotpot/hp_error.h"
#include "globals.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "hotprotocol/hp_json_writer.h"
#include "hotscript/hotobject.h"
#include "hotscript/hot_vm.h"
#include "hotscript/hotobject_reader.h"
#include "hotscript/hotobject_writer.h"
#include "hotscript/script_parser.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hotdata_parser.h"
#include "hotprotocol/hp_xml_writer.h"
#include "hotprotocol/hp_xml_reader.h"
#include "hotprotocol/hp_lua_writer.h"

#include "language/language_types.h"
#include "language/language_reader.h"
#include "language/language.h"
#include "hotjson/json_parser.h"

#include "syntactic_node.h"

#include "hotscript/hot_vm.h"
#include <io.h>

#define HOTDATA_VERSION "0.0.1"

void version()
{
	printf("HotData version %s\n", HOTDATA_VERSION);
}

void usage()
{
	fprintf(stderr, "Usage: hd [options] file\n\n");
	fprintf(stderr, "Use hd -help for a list of options\n");
}

void help()
{
	fprintf(stderr, "Usage: thrift [options] file\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "  -version					Print the compiler version\n");
	fprintf(stderr, "  -lua filename			Run the lua script\n");
	fprintf(stderr, "  -i dir					Add a directory to the list of directories\n");
}


LanguageLib language_lib;
DATA_PARSER dp;

char lua_file_name[HP_MAX_FILE_PATH_LENGTH];
HP_LUA_WRITER writer;
SCRIPT_PARSER sp;
const char *json_input = NULL;
FILE* output_file = NULL;
FILE* json_output_file = NULL;


char root_dir[HP_MAX_FILE_PATH_LENGTH];
char lua_dir[HP_MAX_FILE_PATH_LENGTH];
char real_script_path[HP_MAX_FILE_PATH_LENGTH];
char path_prefix[HP_MAX_FILE_PATH_LENGTH];
char language_path[HP_MAX_FILE_PATH_LENGTH];

void script_putc(HotVM *self, char c)
{
	fputc(c, (FILE*)self->user_data);
}

void get_real_file_path()
{
	snprintf(path_prefix, HP_MAX_FILE_PATH_LENGTH, "%s%cresource%clua%c", root_dir, HP_FILE_SEPARATOR, HP_FILE_SEPARATOR, HP_FILE_SEPARATOR);

	if(access(lua_file_name, 00) == 0)
	{
		snprintf(real_script_path, HP_MAX_FILE_PATH_LENGTH, "%s", lua_file_name);		
	}
	else
	{
		snprintf(real_script_path, HP_MAX_FILE_PATH_LENGTH, "%s%s", path_prefix, lua_file_name);
	}
}


JSON_PARSER jp;
SCRIPT_PARSER sp;

int main(int argc, char **argv)
{
	int i;
	lua_State *L;
	strncpy(root_dir, argv[0], HP_MAX_FILE_PATH_LENGTH);
	

	
	
	//���Ȼ�ø�Ŀ¼
	snprintf(root_dir, HP_MAX_FILE_PATH_LENGTH, getenv("HotPot_Dir"));
	if(root_dir[strlen(root_dir) - 1] != HP_FILE_SEPARATOR)
	{
		root_dir[strlen(root_dir)] = HP_FILE_SEPARATOR;
	}
#ifdef _DEBUG
	snprintf(root_dir, HP_MAX_FILE_PATH_LENGTH, "D:\\HotPot\\");
#endif//_DEBUG

	snprintf(lua_dir, HP_MAX_FILE_PATH_LENGTH, "%s/resource/lua/", root_dir);

	data_parser_init(&dp);
	for (i = 1; i < argc - 1; ++i)
	{
		char* arg;

		arg = strtok(argv[i], " ");
		// Treat double dashes as single dashes
		if (arg[0] == '-' && arg[1] == '-')
		{
			++arg;
		}
		if (strcmp(arg, "-help") == 0)
		{
			help();
			goto ERROR_RET;
		}
		else if (strcmp(arg, "-version") == 0)
		{
			version();
			goto ERROR_RET;
		}				
		else if (strcmp(arg, "-lua") == 0)
		{
			arg = argv[++i];
			if (arg == NULL)
			{
				fprintf(stderr, "Missing template file specification\n");
				usage();
				goto ERROR_RET;
			}
			strncpy(lua_file_name, arg, HP_MAX_FILE_PATH_LENGTH);
		}
		else if (strcmp(arg, "-i") == 0)
		{
			arg = argv[++i];
			if (arg == NULL)
			{
				fprintf(stderr, "Missing template file specification\n");
				usage();
				goto ERROR_RET;
			}
			scanner_stack_add_path(&dp.scanner_stack, arg);
		}		
		else
		{
			fprintf(stderr, "Unrecognized option: %s\n", arg);
			usage();
			goto ERROR_RET;
		}
	}

	snprintf(language_path, HP_MAX_FILE_PATH_LENGTH, "%s%cresource%clanguage%csimplified_chinese.xml", root_dir, HP_FILE_SEPARATOR, HP_FILE_SEPARATOR, HP_FILE_SEPARATOR);
	load_language(&language_lib, language_path);

	
	

	L = luaL_newstate();
	luaL_openlibs(L);



	lua_pushstring(L, root_dir);
	lua_setglobal( L, "root_dir" );

	lua_pushstring(L, lua_dir);
	lua_setglobal( L, "lua_dir" );


	lua_writer_init(&writer, L);
	if(data_parser(&dp, argv[i], &writer.super, &language_lib) != E_HP_NOERROR)
	{
		goto ERROR_RET;
	}

	if(lua_file_name[0])
	{
		lua_setglobal( L, "hd" );
		get_real_file_path();
		if(luaL_dofile(L, real_script_path) != 0)
		{
			const char* error = lua_tostring(L, -1);
			fprintf(stderr, error);
		}
	}
	

	return 0;
ERROR_RET:
	return 1;
}
