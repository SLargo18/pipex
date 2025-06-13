#include "../include/pipex.h"

char	*find_cmp_p(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;

	i = 0;
	if (!paths || !cmd)
		return(NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if(!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	execute_cmd(char **paths, char **cmd, char **envp)
{
	char	*cmd_p;

	if (!cmd || !cmd[0])
		is_error("Command not found", 127, 1);
	cmd_p = find_cmp_p(paths, cmd[0]);
	if (!cmd_p)
		is_error("Command not found", 127, 1);
	if (execve(cmd_p, cmd, envp) == -1)
		{
			free(cmd_p);
			is_error("Execution failed", 127, 1);
		}
}

void	child1(t_pipex *data, char **argv)
{
	close(data->pipefd[0]);
	if (data->infile == -1)
	{
		close(data->pipefd[1]);
		is_error("Cannot open input file", 1, 0);
	}
	if (dup2(data->infile, STDIN_FILENO) == -1
		|| (dup2(data->pipefd[1], STDOUT_FILENO) == -1))
		is_error ("dup2 failed", 1, 0);
	close(data->infile);
	close(data->pipefd[1]);
}

void	child2(t_pipex *data, char **argv)
{
	close(data->pipefd[1]);
	if (dup2(data->pipefd[0], STDIN_FILENO) == -1
		|| (dup2(data->outfile, STDOUT_FILENO) == -1))
		is_error("dup2 failed", 1, 0);
	close(data->pipefd[0]);
	close(data->outfile);
}