#include "../include/pipex.h"

static	void	second_child(t_pipex *data, char **argv, char **envp)
{
	child2(data, argv);
	execute_cmd(data->paths, data->cmd2, envp);
}

static	void	first_child(t_pipex *data, char **argv, char **envp)
{
	printf("entra en creacion de child1\n");
	child1(data, argv);
	fprintf(stderr, "➡️ Llegó a X lugar\n");
	execute_cmd(data->paths, data->cmd1, envp);
}

static	void	open_file(t_pipex *data, char **argv)
{
	printf("abre\n");
	data->infile = open(argv[1], O_RDONLY);
	if(data->infile == -1)
		is_error("Cannot open infile", 1, 0);
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		is_error("Cannot create outputfile", 1, 0);
}

void	create_processes(t_pipex *data, char **argv, char **envp)
{
	printf("entra en processes\n");
	open_file(data, argv);
	data->pid1 = fork();
	if (data->pid1 == -1)
		is_error("Fork failed", 1, 0);
	if (data->pid1 == 0)
		first_child(data, argv, envp);
	data->pid2 = fork();
	if (data->pid2 == -1)
		is_error("Fork failed", 1, 0);
	if (data->pid2 == 0)
		second_child(data, argv, envp);
}

void	create_pipe(t_pipex *data)
{
	printf("crea el pipe\n");
	if(pipe(data->pipefd) == -1)
		is_error("Pipe creation failed", 1, 0);
}

// void	wait_processes(t_pipex *data)
// {
// 	int	status;

// 	waitpid(data->pid1, &status, 0);
// 	waitpid(data->pid2, &status, 0);
// 	if(data->infile != -1)
// 		close(data->infile);
// 	if(data->outfile != -1)
// 		close(data->outfile);
// }