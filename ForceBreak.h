/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForceBreak.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:21:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/08/04 20:05:45 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORCEBREAK_H
# define FORCEBREAK_H
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

//#############################################################################
//#                           DEFINES && TYPEDE                               #
//#############################################################################
# define TRUE			1
# define FALSE			0
# ifndef TIME_PERIOD
# define TIME_PERIOD	2700
#endif
typedef unsigned long long int	ulli;
typedef struct timeval			t_tmval;

//#############################################################################
//#                              FUNCTIONS                                    #
//#############################################################################
ulli	get_current_time(ulli reference);
int		exec_sl(char **args, char **env);
void	break_bg(char **args, char **env);
void	timer(int end);

#endif
