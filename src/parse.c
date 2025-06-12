#include "../include/pipex.h"

int validate_args(int argc, char**argv)
{
	if (argc != 5)
	{
		ft_error("ERROR: Invalid Arguments\n", 1);
		return (0);
	}
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
	{
		ft_error("ERROR: Invalid Arguments\n, 1");
	}
}