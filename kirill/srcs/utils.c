#include "../minishell.h"

char			**check_key(char **envs, char *key)
{
	char		**tmp;
	int			key_len;

	tmp = envs;
	if (!key)
		return NULL;
	key_len = (int)ft_strlen(key);
	while(*tmp != NULL)
	{
		if (!ft_strncmp(*tmp, key, key_len) && *(*tmp + key_len) == '=')
			return (tmp);
		if (!ft_strncmp(*tmp, key, key_len + 1))
			return (tmp);
		tmp++;
	}
	return (NULL);
}

char			**copy_arrays_2x(char **src_arr)
{
	int		i;
	char	**tmp_src;
	char	**tmp_dst;
	char	**res_arr;

	i = 0;
	if (!src_arr)
		return NULL;
	tmp_src = src_arr;
	while(*(tmp_src++)) {
		i++;
	}
	res_arr = (char **) malloc(sizeof(char *) * i + 1);
	tmp_src = src_arr;
	tmp_dst = res_arr;
	while(*tmp_src)
	{
		*tmp_dst = ft_strdup(*tmp_src);
		tmp_src++;
		tmp_dst++;
	}
	*tmp_dst = NULL;
	return res_arr;
}

int				fail(char *str, int res)
{
	printf("%s\n", str);
	return (res);
}
///**
//**
//** @param envs
//** @param key
//** @return
//*/
//
int				count_envp(char **envp_cp)
{
	int			i;

	i = 0;
	while (envp_cp[i] != NULL)
		i++;
	return (i);
}

char			*check_arg(char **envp_cp, char **key)
{
	char		**tmp;
	int			key_len;
	char		*eq;

	eq = NULL;
	tmp = envp_cp;
	if (!*key)
		return NULL;
	eq = ft_strchr(*key, '=');
	if (eq)
		(*eq) = '\0';
	key_len = (int)ft_strlen(*key);
	while(*tmp != NULL)
	{
		if (!ft_strncmp(*tmp, *key, key_len) && *(*tmp + key_len) == '=')
		{
			if (eq)
				*eq = '=';
			return (*tmp);
		}
		tmp++;
	}
	if (eq)
		*eq = '=';
	return (NULL);
}

char			*get_value(char **envp_cp, char *key)
{
	char		**tmp;
	int			key_len;

	tmp = envp_cp;
	if (!key)
		return NULL;
	key_len = (int)ft_strlen(key);
	while(*tmp != NULL)
	{
		if (!ft_strncmp(*tmp, key, key_len) && *(*tmp + key_len) == '=')
			return (*tmp + key_len + 1);
		if (!ft_strncmp(*tmp, key, key_len + 1))
			return (*tmp + key_len);
		tmp++;
	}
	return (NULL);
}

void			print_arr_2x(char **array)
{
	int			i;

	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}