
#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (!validate_args(argc, argv))
	{
		printf("entra1\n");
		is_error("ERROR: Invalid Arguments\n", 1, 1);
	}
	ft_pipex(argv, envp);
	return(0);
}