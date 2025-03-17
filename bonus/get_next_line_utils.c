

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char		*new;
	size_t		i;
	size_t		j;

	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i])
		new[i] = line[i];
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(line);
	return (new);
}