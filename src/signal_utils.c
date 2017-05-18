/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:00:49 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:21:47 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**      signal_gesture
*/

void		signal_gesture(void)
{
	clear_tab(g_va.buffer);
	signal(SIGINT, catch_signal);
	signal(SIGWINCH, window_size);
	signal(SIGTSTP, stop_signal);
	signal(SIGCONT, reset_signal);
}

/*
** ls with ctrl+c
*/

void		catch_signal(int ctrl)
{
	if (ctrl == 2)
	{
		ft_putstr(tgetstr("cl", NULL));
		reset_termios();
		close(g_va.tty);
		exit(0);
	}
}

/*
**      stop_signal
*/

void		stop_signal(int ctrl)
{
	char			cmd[2];
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		exit(0);
	(void)ctrl;
	cmd[0] = term.c_cc[VSUSP];
	cmd[1] = '\0';
	reset_termios();
	ft_putstr_fd(tgetstr("ve", NULL), g_va.tty);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cmd);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		exit(0);
}

/*
**      reset_signal
*/

void		reset_signal(int ctrl)
{
	(void)ctrl;
	set_termios();
	ft_putstr_fd(tgetstr("vi", NULL), g_va.tty);
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	print_list(&g_va.l, &g_va.c, g_va.buffer);
}

/*
**      window_size signal
*/

void		window_size(int ctrl)
{
	(void)ctrl;
	ft_putstr(tgetstr("cl", NULL));
	print_list(&g_va.l, &g_va.c, g_va.buffer);
}
