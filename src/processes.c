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