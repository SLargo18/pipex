/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:18:48 by slargo-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:18:49 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

static	void	second_child(t_pipex *data, char **envp)
{
	child2(data);
	execute_cmd(data->paths, data->cmd2, envp);
	exit(127);
}

static	void	first_child(t_pipex *data, char **envp)
{
	child1(data);
	execute_cmd(data->paths, data->cmd1, envp);
	exit(127);
}

static	void	open_file(t_pipex *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		perror("Cannot open infile");
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		is_error("Cannot create outputfile", 1, 0);
}

void	create_processes(t_pipex *data, char **argv, char **envp)
{
	open_file(data, argv);
	data->pid1 = fork();
	if (data->pid1 == -1)
		is_error("Fork failed", 1, 0);
	if (data->pid1 == 0)
		first_child(data, envp);
	data->pid2 = fork();
	if (data->pid2 == -1)
		is_error("Fork failed", 1, 0);
	if (data->pid2 == 0)
		second_child(data, envp);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

void	create_pipe(t_pipex *data)
{
	if (pipe(data->pipefd) == -1)
		is_error("Pipe creation failed", 1, 0);
}
