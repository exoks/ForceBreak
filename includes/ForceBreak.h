/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForceBreak.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:21:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/08/07 20:06:50 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORCEBREAK_H
# define FORCEBREAK_H
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>

//##############################################################################
//#                           DEFINES && TYPEDEF                               #
//##############################################################################
# define TRUE			1
# define FALSE			0
# define SL_TOOL		"tools/sl"
# define COWSAY_TOOL	"tools/cowsay"
# define CMATRIX_TOOL	"tools/cmatrix"
# define FIRST_MSG		"cowsay hello"

# ifndef TIME_PERIOD
# define TIME_PERIOD	60
#endif

typedef unsigned long long int	ulli;
typedef struct timeval			t_tmval;

//##############################################################################
//#                              FUNCTIONS                                     #
//##############################################################################
ulli	get_current_time(ulli reference);
int		exec_tools(char **args, char **env);
void	break_bg(char **args, char **env);
void	timer(int end);
void	set_tools(char **tools);
char	**ft_split(char const *s, char sep);

#endif
