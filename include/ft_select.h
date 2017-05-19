/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:39:55 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:55:09 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/includes/libft.h"
# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>

/*
**	Structure that contain the current cursor position.
*/

typedef struct	s_cursor
{
	int			pos_x;
	int			pos_y;
}				t_cursor;

/*
**	global linked-list content
*/

typedef struct	s_global
{
	t_list		*l;
	int			col;
	int			line;
	int			tty;
	t_cursor	*c;
	char		buffer[6];
}				t_global;

t_global		g_va;

/*
**	t_select structure is the content of the arguments linked list.
**	It contain the argument name, his size, the index of the link and
**	a boolean that say if the argument name is highlighted or not.
*/

typedef struct	s_select
{
	int			index;
	int			nsize;
	int			hl;
	int			ul;
	char		*argn;
	int			max_size;
}				t_select;

/*
**	list_utils.c
*/

void			convert_to_list(t_list **list_name, char **argv);
void			print_list(t_list **list_name, t_cursor **c,
		char buffer[6]);
void			init_list(t_list **list_name);
int				list_size(t_list **list_name);

/*
**	term_mode.c
*/

int				set_termios(void);
int				reset_termios(void);

/*
**	key_utils.c
*/

int				ft_tputchar(int c);
int				catch_key(t_list **l, t_cursor **c, int tty_name);
void			space_key(t_cursor ***c, int tty,
		char buffer[6], t_list ***l);
void			del_node(t_list ***l, t_cursor ***c, char buffer[6]);
void			clear_tab(char buffer[6]);

/*
**	arrow_utils.c
*/

void			right_key(t_cursor ***c, int tty, char buffer[6], t_list ***l);
void			left_key(t_cursor ***c, int tty, char buffer[6], t_list ***l);
void			up_key(t_cursor ***c, int tty, char buffer[6], t_list ***l);
void			down_key(t_cursor ***c, int tty, char buffer[6], t_list ***l);

/*
**	signal_utils.c
*/

void			catch_signal(int ctrl);
void			window_size(int ctrl);
void			stop_signal(int ctrl);
void			reset_signal(int ctrl);
void			signal_gesture(void);

/*
**	print_utils
*/

void			print_select(t_list ***l,
		t_cursor ***c, int tty, char buffer[6]);

/*
**	perfect_collumn.c
*/

void			perfect_print(int temp, t_cursor ***c, t_list ***l);
void			perfect_down(t_cursor ****c, t_list ****l, int temp);

#endif
