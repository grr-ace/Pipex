/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:08:42 by grmullin          #+#    #+#             */
/*   Updated: 2024/01/02 17:25:42 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	res;
	int	fd[2];

	res = 0;
	if (ac != 5)
	{
		ft_putstr_fd("Invalid arguments supplied\n", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		print_error("Error making pipe");
	res = pipex(fd[0], fd[1], av, envp);
	return (res);
}

int	pipex(int fd_read, int fd_write, char **av, char **envp)
{
	int	pid1;
	int	pid2;
	int	infile_fd;
	int	outfile_fd;

	infile_fd = create_infile(av[1]);
	outfile_fd = create_outfile(av[4]);
	pid1 = fork();
	ft_error_check(pid1);
	if (pid1 == 0)
	{
		dup_infile(infile_fd, fd_write, fd_read);
		ft_get_path(av[2], fd_read, envp);
	}
	pid2 = fork();
	ft_error_check(pid2);
	if (pid2 == 0)
	{
		dup_outfile(outfile_fd, fd_write, fd_read);
		ft_get_path(av[3], fd_read, envp);
	}
	ft_close(fd_read, fd_write, infile_fd, outfile_fd);
	return (ft_wait(pid1, pid2));
}

void	ft_close(int fd_read, int fd_write, int infile, int outfile)
{
	if (close(fd_read) == -1)
		print_error("Error closing read end of pipe");
	if (close(fd_write) == -1)
		print_error("Error closing write end of pipe");
	if (close(infile) == -1)
		print_error("Error closing infile fd");
	if (close(outfile) == -1)
		print_error("Error closing outfile fd");
}

int	ft_wait(int pid1, int pid2)
{
	int	status1;
	int	status2;
	int	exit_status2;
	int	check;

	status1 = 0;
	status2 = 0;
	check = 0;
	waitpid(pid1, &status1, WUNTRACED);
	waitpid(pid2, &status2, WUNTRACED);
	exit_status2 = 0;
	if (WIFEXITED(status2))
	{
		exit_status2 = WEXITSTATUS(status2);
		check = exit_status2;
	}
	return (check);
}
