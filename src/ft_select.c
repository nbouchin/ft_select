/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:35:24 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 16:43:22 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	Main function, init termios data convert argv to list and init and  print it
*/

int					main(int argc, char **argv)
{
	(void)argc;
	if (argv[1])
	{
		g_va.l = NULL;
		g_va.tty = open("/dev/tty", O_WRONLY);
		g_va.c = (t_cursor*)ft_memalloc(sizeof(t_cursor));
		g_va.c->pos_x = 0;
		g_va.c->pos_y = 0;
		convert_to_list(&(g_va.l), argv);
		init_list(&g_va.l);
		set_termios();
		print_list(&g_va.l, &g_va.c, "");
		catch_key(&g_va.l, &g_va.c, g_va.tty);
		reset_termios();
		return (1);
	}
	return (0);
}
