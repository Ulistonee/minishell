#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	is_minishell(char *line)
{
	if (line == NULL || *line == '\0')
		return (0);
	if (!ft_strcmp(line, "./minishell"))
		return (1);
	return (0);
}
