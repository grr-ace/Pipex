/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:23:10 by grmullin          #+#    #+#             */
/*   Updated: 2024/01/03 09:44:47 by grmullin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

int		pipex(int fd_read, int fd_write, char **av, char **envp);
int		ft_wait(int pid1, int pid2);
int		create_infile(char *file_name);
int		create_outfile(char *file_name);
void	ft_get_path(char *cmd, int fd_write, char **envp);
void	ft_path_checker(char *paths, char *cmd, char **envp);
void	ft_close(int fd_read, int fd_write, int infile, int outfile);
void	print_error(char *str);
void	ft_exec(char *path, char **array, char **envp);
void	dup_infile(int infile_arg, int fd_write, int fd_read);
void	dup_outfile(int outfile_arg, int fd_write, int fd_read);
void	ft_error_check(int fd);

#endif
