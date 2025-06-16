/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:18:38 by slargo-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:18:39 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	wait_processes(t_pipex *data)
{
	int	status;

	waitpid(data->pid1, &status, 0);
	waitpid(data->pid2, &status, 0);
	if (data->infile != -1)
		close(data->infile);
	if (data->outfile != -1)
		close(data->outfile);
}

char	**parse_cmd(char *cmd)
{
	char	**cmd_ok;

	if (!cmd)
		return (NULL);
	cmd_ok = ft_split(cmd, ' ');
	return (cmd_ok);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

void	ft_pipex(char **argv, char **envp)
{
	t_pipex	data;

	ft_memset(&data, 0, sizeof(t_pipex));
	data.paths = get_paths(envp);
	data.cmd1 = parse_cmd(argv[2]);
	data.cmd2 = parse_cmd(argv[3]);
	if (!data.paths && (argv[2][0] != '/' || argv[3][0] != '/'))
	{
		free_data(&data);
		is_error("Error parsing cmd or paths\n", 1, 0);
	}
	create_pipe(&data);
	create_processes(&data, argv, envp);
	wait_processes(&data);
	free_data(&data);
}

int	validate_args(int argc, char**argv)
{
	if (argc != 5)
	{
		is_error("ERROR: Invalid Arguments\n", 1, 1);
		return (0);
	}
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (0);
	if (!argv[2][0] || !argv[3][0])
	{
		is_error("ERROR: Invalid Command\n", 1, 1);
		return (0);
	}
	return (1);
}
