/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForceBreak.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:21:05 by oezzaou           #+#    #+#             */
/*   Updated: 2023/08/07 14:50:23 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ForceBreak.h"


int	main(int ac, char **av, char **env)
{
	pid_t	pid;

	(void) ac;
	pid = fork();
	if (pid == -1)
		perror(0);
	if (pid == 0)
		break_bg(++av, env);
	return (EXIT_SUCCESS);
}
