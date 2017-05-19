/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:44:58 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/19 11:49:24 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	error(char *name_term)
{
	if (tgetent(NULL, name_term) < 0)
	{
		ft_putchar_fd('"', 2);
		ft_putstr_fd(name_term, 2);
		ft_putchar_fd('"', 2);
		ft_putstr_fd(" TERM name is not recognise as a valid TERM, ", 2);
		ft_putendl_fd("please set a valid TERM name.", 2);
	}
	else if (tgetent(NULL, name_term) == 0)
		ft_putendl_fd("TERM name is NULL, please set a valid TERM name.", 2);
	else
		ft_putendl_fd("Unknown error.", 2);
	exit(0);
}

/*
**	Set the termios on canonical mode, set the environment.
*/

int		set_termios(void)
{
	struct termios	term;
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("NULL environment, please set a valid environment.", 2);
		exit(0);
	}
	if (tgetent(NULL, name_term) <= 0)
		error(name_term);
	(tcgetattr(0, &term) == -1) ? error(name_term) : 0;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	(tcsetattr(0, TCSADRAIN, &term) == -1) ? error(name_term) : 0;
	ft_putstr_fd(tgetstr("ti", NULL), g_va.tty);
	ft_putstr_fd(tgetstr("vi", NULL), g_va.tty);
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	return (1);
}

/*
**	Reset all termios data.
*/

int		reset_termios(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_putstr_fd(tgetstr("te", NULL), g_va.tty);
	ft_putstr_fd(tgetstr("ve", NULL), g_va.tty);
	return (1);
}
