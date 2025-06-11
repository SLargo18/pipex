#include "../include/pipex.h"

void	ft_error(char *msg, int flag)
{
	ft_putstr(msg);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(flag);
}

int validate_args(int argc, char**argv)
{
	if (argc != 5)
	{
		write();
		return (0);
	}
}