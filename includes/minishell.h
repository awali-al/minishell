/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:36:18 by awali-al          #+#    #+#             */
/*   Updated: 2019/11/28 16:00:22 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>

# include <stdio.h>

# define RED_COL	"\x1b[31m"
# define GREEN_COL	"\x1B[32m"
# define RESET_COL	"\x1b[37m"

typedef struct		s_arg
{
	char			*str;
	struct s_arg	*nxt;
}					t_arg;

char				*my_envirenement(char **env);
void				display_prompt(int c);
char				**line_treat(char *line, char **env);
char				**var_home(char **line, char **env);


char				*check_command(char **line, char ***env, int *c);
void				my_echo(char **line, char **env, int *c);
int					my_cd(char **line, char ***env, int *c);
char				*value_of(char **env, char *key);
void				my_env(char **env, int *c);
char				*program_path(char *cmd, int *c);
char				*command_path(char *cmd, char **syspath, int *c);
void				free_2d(char **path);

void				run_command(char *cmd, char *line, char ***env, int *c);
void				change_env_path(char *path, char ***env, int *c);

void				free_list(t_arg *head);

/*
void				error(char *line, int *c);
t_env				*preset_env(char ***env);
char				*command_return(char *path, char *cmd, int *c);
char    			*null_return(char *cmd, int *c);
char				*locate_command(char *line);
char				*value_of(char **env, char *key);
void				change_env_path(char *path, char ***env);
*/

#endif