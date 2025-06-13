#include "../include/pipex.h"

void	open_file(t_pipex *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if(data->infile == -1)
	{
		perror(argv[1]);
		is_error("Cannot open infile", 1, 0);

	}
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror(argv[4]);
		is_error("Cannot create outputfile", 1, 0);
	}
}

void	child1(t_pipex *data, char **argv)
{
	close(data->pipefd[0]);
	if (data->infile == -1)
		is_error("Cannot open input file", 1, 0);
	if (dup2(data->infile, STDIN_FILENO) == -1
		|| (dup2(data->pipefd[1], STDIN_FILENO) == -1))
		is_error ("dup2 failed", 1, 0);
	close(data->infile);
	close(data->pipefd[1]);
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