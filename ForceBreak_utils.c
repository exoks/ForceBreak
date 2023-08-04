/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForceBreak_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:26:42 by oezzaou           #+#    #+#             */
/*   Updated: 2023/08/04 20:06:10 by oezzaou          ###   ########.fr       */
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

//=== exec_sl ==================================================================
int	exec_sl(char **args, char **env)
{
	pid_t	pid;
	int		status;
	
	pid = fork();
	if (pid == -1)
		perror(0);
	if (pid == 0)
		exit(execve("sl", args, env));
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

//=== timer ====================================================================
void	timer(int end)
{
	while (end >= 0)
	{
		printf("TIMER| >>>> |%d|\n", end--);
		sleep(1);
	}
}

//=== break_bg =================================================================
void	break_bg(char **args, char **env)
{
	ulli	reference;

	reference = get_current_time(0);
	while (TRUE)
	{
		if (get_current_time(reference) >= TIME_PERIOD)
		{
			timer(10);
			if (exec_sl(args, env) == -1)
				exit(EXIT_FAILURE);
			reference = get_current_time(0);
		}
		sleep(1);	
	}
}
