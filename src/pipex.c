#include "../include/pipex.h"

char	**parse_cmd(char *cmd)
{
	char	**cmd_ok;

	printf("entra en parse_cmd\n");
	if(!cmd)
		return (NULL);
	cmd_ok = ft_split(cmd, ' ');
	return(cmd_ok);
}

char **get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while(envp[i])
	{
		printf("entra en getpath3\n");

		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			printf("entra en strncmp \n ");
			paths = ft_split(envp[i] + 5, ':');
			//printf("PATH found: %s\n", envp[i] + 5);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

void	ft_pipex(char **argv, char **envp)
{
	printf("entraaaaa\n");

	t_pipex data;

	ft_memset(&data, 0, sizeof(t_pipex));
	data.paths = get_paths(envp);
	data.cmd1 = parse_cmd(argv[2]);
	data.cmd2 = parse_cmd(argv[3]);
	if (!data.paths || !data.cmd1 || !data.cmd2)
	{
		free_data(&data);
		is_error("Error parsing cmd or paths", 1, 0);
	}
	printf("entra en pipex, despues de parse cmd\n");
	create_pipe(&data);
	create_processes(&data, argv, envp);
	//wait_processes(&data);
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
	if (!argv[2][0] || !argv[3][0] )
	{
		is_error("ERROR: Invalid Command\n", 1, 1);
		return (0);
	}
	return (1);
}

