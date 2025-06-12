
#include "../include/pipex.h"

int validate_args(int argc, char**argv)
{
	if (argc != 5)
	{
		is_error("ERROR: Invalid Arguments\n", 1, 1);
		return (0);
	}
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (0);
	if (!argv[2][0] || !argv[3][0] )
	{
		is_error("ERROR: Invalid Command\n", 1, 1);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (!validate_args(argc, argv))
		return (1);
	ft_pipex(argv, envp);
	return(0);
}