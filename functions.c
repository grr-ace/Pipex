/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:19:53 by grmullin          #+#    #+#             */
/*   Updated: 2024/10/31 17:30:32 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_exec(char *path, char **array, char **envp)
{
	if (execve(path, array, envp) == -1)
		print_error("Execve error\n");
}

void	ft_path_checker(char *paths, char *cmd, char **envp)
{
	char	*correct;
	char	*full_path;
	char	**arr;

	arr = ft_split(cmd, ' ');
	correct = ft_strjoin(paths, "/");
	full_path = ft_strjoin(correct, arr[0]);
	if (access(full_path, X_OK) == 0)
		ft_exec(full_path, arr, envp);
	free(correct);
	free(full_path);
	free(arr);
}

void	ft_get_path(char *cmd, int fd_write, char **envp)
{
	int		i;
	int		j;
	int		count;
	char	**split_paths;

	i = 0;
	count = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 5) > 60) 
		{
			j = 0;
			split_paths = ft_split(envp[i], ':');
			while (split_paths[j])
				ft_path_checker(split_paths[j++], cmd, envp);
			count++;
			close(fd_write);
			ft_putstr_fd("Invalid command: path not found\n", 2);
			if (count == 1)
				exit(127);
		}
		i++;
	}
	exit(0);
}

void	ft_error_check(int fd)
{
	if (fd == -1)
		print_error("Forking error");
}
