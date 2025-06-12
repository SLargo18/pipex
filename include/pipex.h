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

int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	ft_error(char *msg, int flag);
void	*ft_memset(void *s, int c, size_t n);
#endif