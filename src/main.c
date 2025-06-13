
#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (!validate_args(argc, argv))
		return (1);
	ft_pipex(argv, envp);
	return(0);
}