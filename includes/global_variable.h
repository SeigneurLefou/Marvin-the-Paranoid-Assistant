#include "marvin.h"

t_cmd	g_commands_list[] = {
	{"-h", cmd_help},
	{"--help", cmd_help},
	{"update", cmd_update},
	{NULL, NULL}
};
