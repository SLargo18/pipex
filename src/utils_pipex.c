#include "../include/pipex.h"

static	void	second_child(t_pipex *data, char **argv, char **envp)
{
	child2(data, argv);
	execute_cmd(data->paths, data->cmd2, envp);
	exit(0);
}

static	void	first_child(t_pipex *data, char **argv, char **envp)
{
	printf("entra en creacion de child1\n");
	child1(data, argv);
	fprintf(stderr, "➡️ Llegó a X lugar\n");
	execute_cmd(data->paths, data->cmd1, envp);
	exit(0);
}

static	void	open_file(t_pipex *data, char **argv)
{
	printf("abre\n");
	data->infile = open(argv[1], O_RDONLY);
	if(data->infile == -1)
		perror("Cannot open infile");
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
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

void	create_pipe(t_pipex *data)
{
	printf("crea el pipe\n");
	if(pipe(data->pipefd) == -1)
		is_error("Pipe creation failed", 1, 0);
}