/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:32:14 by grmullin          #+#    #+#             */
/*   Updated: 2024/01/02 17:16:52 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	create_infile(char *file_name)
{
	int	infile;

	infile = open(file_name, O_RDONLY);
	if (infile == -1)
		print_error("Infile is not accessible");
	return (infile);
}

int	create_outfile(char *file_name)
{
	int	outfile;

	outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		print_error("Outfile is not accessible");
	return (outfile);
}

void	dup_infile(int infile, int fd_write, int fd_read)
{
	if (close(fd_read) == -1)
		print_error("Error closing read end of pipe");
	if (dup2(infile, STDIN_FILENO) == -1)
		print_error("Error duping infile");
	if (close(infile) == -1)
		print_error("Error closing infile");
	if (dup2(fd_write, STDOUT_FILENO) == -1)
		print_error("Error duping write end of pipe");
	if (close(fd_write) == -1)
		print_error("Error closing write end of pipe");
}

void	dup_outfile(int outfile, int fd_write, int fd_read)
{
	if (close(fd_write) == -1)
		print_error("Error closing write end of pipe");
	if (dup2(fd_read, STDIN_FILENO) == -1)
		print_error("Error duping read end of pipe");
	if (close(fd_read) == -1)
		print_error("Error closing read end of pipe");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		print_error("Error duping outfile");
	if (close(outfile) == -1)
		print_error("Error closing outfile");
}

void	print_error(char *str)
{
	perror(str);
	exit (1);
}
