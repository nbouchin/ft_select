/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:49:19 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 16:43:35 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	free_node
*/

void		free_node(t_list *n)
{
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	reset_termios();
	close(g_va.tty);
	free(n);
	exit(0);
}

/*
**	Remove node from list and free it
*/

void		delete_node(t_list *head, t_list *n)
{
	t_list *prev;

	if (head == n)
	{
		if (head->nxt == NULL)
			free_node(n);
		head->cont = head->nxt->cont;
		n = head->nxt;
		head->nxt = head->nxt->nxt;
		free(n);
		return ;
	}
	prev = head;
	while (prev->nxt != NULL && prev->nxt != n)
		prev = prev->nxt;
	if (prev->nxt == NULL)
		return ;
	prev->nxt = prev->nxt->nxt;
	free(n);
	return ;
}

/*
**	Remove the actual node
*/

void		del_node(t_list ***l, t_cursor ***c, char buffer[6])
{
	t_list		*save;
	int			i;

	i = 0;
	save = (**l);
	while (**l)
	{
		if (((t_select*)(**l)->cont)->index == (**c)->pos_x)
		{
			free(((t_select*)(**l)->cont)->argn);
			free((**l)->cont);
			delete_node(save, **l);
			break ;
		}
		(**l) = (**l)->nxt;
	}
	(**l) = save;
	while (**l)
	{
		((t_select*)(**l)->cont)->index = i++;
		(**l) = (**l)->nxt;
	}
	(**l) = save;
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	print_list(*l, *c, buffer);
}

/*
**	React like ft_putchar but return an int.
*/

int			ft_tputchar(int c)
{
	write(1, &c, 1);
	return (c);
}

/*
**	right_key utils
*/

void		right_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	((**c)->pos_x >= list_size(*l)) ? ((**c)->pos_x = 0) : 0;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x += 1;
	print_list(*l, *c, buffer);
}

/*
**	left_key utils
*/

void		left_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	((**c)->pos_x == 0) ? ((**c)->pos_x = list_size((*l))) : 0;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x -= 1;
	print_list(*l, *c, buffer);
}

/*
**	perfect_print
*/

void		perfect_print(int temp, t_cursor ***c, t_list ***l)
{
	if (g_va.col == 1)
	{
		if (temp == 0)
			(**c)->pos_x = list_size(*l) - 1;
	}
	else if (list_size(*l) % g_va.col == 0)
		(**c)->pos_x = g_va.col * ((list_size(*l) / g_va.col) - 1);
	else
		(**c)->pos_x = temp + ((list_size(*l) / g_va.col) * g_va.col);
}

/*
**	up_key utils
*/

void		up_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	int	temp;

	temp = (**c)->pos_x;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x -= g_va.col;
	if (g_va.col == 0 || g_va.col - 1 == 0 || temp == 0)
		perfect_print(temp, c, l);
	else if ((**c)->pos_x < 0)
	{
		(**c)->pos_x = temp + ((list_size(*l) / g_va.col) * g_va.col);
		if ((**c)->pos_x == list_size(*l))
		{
			if ((**c)->pos_x % temp == 0)
				(**c)->pos_x = (**c)->pos_x - g_va.col;
			else if ((**c)->pos_x == list_size(*l))
				(**c)->pos_x = (**c)->pos_x - g_va.col;
			else
				(**c)->pos_x = (list_size(*l) / g_va.col - 1) * g_va.col;
		}
		else if ((**c)->pos_x >= list_size(*l))
			(**c)->pos_x = (list_size(*l) / g_va.col - 1) * g_va.col + temp;
	}
	print_list(*l, *c, buffer);
}

/*
**	if perfect_down
*/

void		perfect_down(t_cursor ****c, t_list ****l, int temp)
{
	if ((***c)->pos_x % g_va.col == 0)
		(***c)->pos_x = 0;
	else if ((***c)->pos_x == list_size(**l))
		(***c)->pos_x = temp - g_va.col;
	else
		(***c)->pos_x = temp;
}

/*
**	down_key utils
*/

void		down_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	int	temp;

	temp = (**c)->pos_x;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	temp = (**c)->pos_x;
	(**c)->pos_x += g_va.col;
	if (list_size(*l) == temp + g_va.col)
		if (list_size(*l) % g_va.col != 0)
			(**c)->pos_x = list_size(*l) % g_va.col;
	if (g_va.col == 0)
		return ;
	if ((**c)->pos_x > list_size(*l))
	{
		(**c)->pos_x = temp - ((list_size(*l) / g_va.col) * g_va.col);
		if ((**c)->pos_x < 0)
			(**c)->pos_x = temp
				- ((list_size(*l) / g_va.col) * g_va.col) + g_va.col;
		if ((**c)->pos_x == list_size(*l))
			perfect_down(&c, &l, temp);
	}
	print_list(*l, *c, buffer);
}

/*
**	set ul
*/

void		set_ul(int i, t_list ****l)
{
	t_list *save;

	save = (***l);
	while (***l)
	{
		(((t_select*)(***l)->cont)->index == i)
			? (((t_select*)(***l)->cont)->ul = 1) : 0;
		(***l) = (***l)->nxt;
	}
	(***l) = save;
}

/*
**	space_key utils
*/

void		space_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	print_list(*l, *c, buffer);
	(**c)->pos_x += 1;
}

/*
**	Clear the buffer tab
*/

void		clear_tab(char buffer[6])
{
	int		i;

	i = 0;
	while (buffer[i])
		buffer[i++] = '\0';
}

/*
**	Deals with ctrl+c
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
**	print selection
*/

void		print_select(t_list ***l, t_cursor ***c, int tty, char buffer[6])
{
	(void)c;
	(void)buffer;
	(void)tty;
	reset_termios();
	close(g_va.tty);
	while (**l)
	{
		if (((t_select*)(**l)->cont)->hl)
		{
			ft_putstr_fd(((t_select*)(**l)->cont)->argn, 1);
			ft_putchar_fd(' ', 1);
		}
		(**l) = (**l)->nxt;
	}
	exit(0);
}

/*
**	stop_signal
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
**	reset_signal
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
**	window_size signal
*/

void		window_size(int ctrl)
{
	(void)ctrl;
	ft_putstr(tgetstr("cl", NULL));
	print_list(&g_va.l, &g_va.c, g_va.buffer);
}

/*
**	arrow_gesture
*/

void		arrow_gesture(t_cursor ***c, t_list ***l, int tty)
{
	(g_va.buffer[2] == 'A')
		? up_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'B')
		? down_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'D')
		? left_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'C')
		? right_key(c, tty, g_va.buffer, l) : 0;
}

/*
**	signal_gesture
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
**	Catch key strokes and react depending of them
*/

int			catch_key(t_list **l, t_cursor **c, int tty)
{
	while (1)
	{
		signal_gesture();
		read(0, g_va.buffer, 6);
		if (g_va.buffer[0] == 27)
		{
			(g_va.buffer[1] == 0)
				? ft_putstr_fd(tgetstr("cl", NULL), tty) : 0;
			if (g_va.buffer[1] == 0)
				return (0);
			arrow_gesture(&c, &l, tty);
		}
		if (g_va.buffer[0] == 4)
			return (0);
		(g_va.buffer[0] == 127 ||
		(g_va.buffer[0] == 27 &&
		g_va.buffer[1] == 91 && g_va.buffer[2] == 51))
			? del_node(&l, &c, g_va.buffer) : 0;
		(g_va.buffer[0] == 32)
			? space_key(&c, tty, g_va.buffer, &l) : 0;
		(g_va.buffer[0] == 10 &&
		g_va.buffer[1] == 0) ?
			print_select(&l, &c, tty, g_va.buffer) : 0;
	}
	return (0);
}
