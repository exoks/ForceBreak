/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForceBreak_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:26:42 by oezzaou           #+#    #+#             */
/*   Updated: 2023/08/07 20:16:19 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ForceBreak.h"

//=== get_current_time =========================================================
ulli	get_current_time(ulli reference)
{
	t_tmval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec - reference);
}

//=== exec_tools ===============================================================
int	exec_tools(char **args, char **env)
{
	pid_t	pid;
	int		status;

	(void) args;
	pid = fork();
	if (pid == -1)
		perror(0);
	if (pid == 0)
		exit(execve(CMATRIX_TOOL, ft_split("cmatrix", ' '), env));
	sleep(10);
	kill(pid, SIGKILL);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

/*
//=== timer ====================================================================
void	timer(int end)
{
	while (end >= 0)
	{
		printf("TIMER| >>>> |%d|\n", end--);
		sleep(1);
	}
}
*/

//=== break_bg =================================================================
void	break_bg(char **args, char **env)
{
	ulli	reference;

	reference = get_current_time(0);
	while (TRUE)
	{
		if (get_current_time(reference) >= TIME_PERIOD)
		{
			if (exec_tools(args, env) == -1)
				exit(EXIT_FAILURE);
			reference = get_current_time(0);
		}
		sleep(1);	
	}
}
