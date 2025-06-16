#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (!validate_args(argc, argv))
		is_error("ERROR: Invalid Arguments\n", 1, 1);
	ft_pipex(argv, envp);
	return (0);
}
