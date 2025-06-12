#include "../include/pipex.h"

void	ft_error(char *msg, int flag)
{
	ft_putstr(msg);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(flag);
}

int	ft_strlen(char *s)
{
	char *i = s;

	if (!(*s))
		return (0);
	while (*s)
		s++;
	return (s - i);
}

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n && s1[i] != s2[i])
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}