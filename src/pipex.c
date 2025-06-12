#include "../include/pipex.h"

char	**parse_cmd(char *cmd)
{
	char	**cmd_ok;

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
	t_pipex data;

	ft_memset(&data, 0, sizeof(t_pipex));
	data.paths = get_paths(envp);
	data.cmd1 = parse_cmd(argv[2]);
	data.cmd1 = parse_cmd(argv[3]);
}