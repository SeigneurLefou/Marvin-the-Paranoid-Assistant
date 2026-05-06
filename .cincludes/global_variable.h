#include "marvin.h"

t_cmd	g_commands_list[] = {
	{"-h", cmd_help},
	{"--help", cmd_help},
	{"update", cmd_update},
	{"say", cmd_say},
	{NULL, NULL}
};
