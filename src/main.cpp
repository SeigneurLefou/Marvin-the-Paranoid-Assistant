#include "marvin.hpp"


int	main(int argc, char *argv[])
{
	unordered_map<string, t_builtin_cmd>	builtins;

	if (argc < 2)
		return (1);
	define_builtins_command(builtins);
	if (is_builtins_command(argv[1], builtins))
	{
		exit_code = exec_builtins_command(argc - 1, argv + 1, builtins)
		return (result_cmd);
	}
	cout << "Command doesn't exist." << endf;
	return (1);
	return (EXIT_SUCCESS);
}
