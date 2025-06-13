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