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
	int		infile;
	int		outfile;
	int		pipefd[2]; //para la entra y salida o sea leer y escribir 
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

int		ft_strlen(const char *s);
int		validate_args(int argc, char**argv);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*find_cmp_p(char **paths, char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *s);
void	free_data(t_pipex *data);
void	create_pipe(t_pipex *data);
void	ft_pipex(char **argv, char **envp);
void	child1(t_pipex *data, char **argv);
void	child2(t_pipex *data, char **argv);
void	is_error(char *msg, int exit_code, int close_std);
void	execute_cmd(char **paths, char **cmd, char **envp);
void	create_processes(t_pipex *data, char **argv, char **envp);
void	*ft_memset(void *s, int c, size_t n);

#endif