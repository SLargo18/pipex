#include "../include/pipex.h"
#include <stdio.h>
void	ft_error(char *msg, int flag)
{
	ft_putstr(msg);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(flag);
}

int	ft_strlen(char *s)
{
	char *i = s;

	if (!(*s))
		return (0);
	while (*s)
		s++;
	return (s - i);
}