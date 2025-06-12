#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef	struct s_pipex
{
	int		infle;
	int		outfile;
	int		pipefd[2];
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	ft_error(char *msg, int flag);
char	**ft_split(char const *s, char c);

#endif