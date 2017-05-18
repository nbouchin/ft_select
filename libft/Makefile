# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 11:12:01 by nbouchin          #+#    #+#              #
#    Updated: 2017/03/16 10:31:06 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror
RM		=	rm -Rf
LIBSRC	=	./
LOBJDIR	=	./obj/
LSRCDIR =	./src/
LHEADER =	./includes/
OBJDIR	=	./src/ft_printf/obj/
SRCDIR	=	./src/ft_printf/src/
HEADER	=	./src/ft_printf/includes/
GRN		=	\033[0;32m
RED		=	\033[0;31m
CYN		=	\033[0;36m
NC		=	\033[0m


SRC		=  get_type.c		parser.c		lower_s.c \
		   upper_s.c		lower_p.c		lower_d.c		upper_d.c \
		   lower_i.c		lower_o.c		upper_o.c 		lower_c.c\
		   lower_u.c		upper_u.c		lower_x.c		upper_x.c \
		   upper_c.c		modulo.c		int_utils.c		str_utils.c \
		   tab_utils.c 		uint_utils.c	wstr_utils.c	undefined.c

LSRC	= ft_atoi.c		ft_itoa.c		ft_memmove.c	ft_putstr.c \
		  ft_strdel.c	ft_strlen.c		ft_strnew.c		ft_tolower.c \
		  ft_bzero.c	ft_memalloc.c	ft_memset.c		ft_putstr_fd.c \
		  ft_strdup.c	ft_strmap.c		ft_strnstr.c	ft_toupper.c \
		  ft_isalnum.c	ft_memccpy.c	ft_putchar.c	ft_strcat.c \
		  ft_strequ.c	ft_strmapi.c	ft_strrchr.c	ft_isalpha.c \
		  ft_memchr.c	ft_putchar_fd.c	ft_strchr.c		ft_striter.c \
		  ft_strncat.c	ft_strsplit.c	ft_isascii.c	ft_memcmp.c \
		  ft_putendl.c	ft_strclr.c		ft_striteri.c	ft_strncmp.c \
		  ft_strstr.c	ft_isdigit.c	ft_memcpy.c		ft_putendl_fd.c \
		  ft_strcmp.c	ft_strjoin.c	ft_strncpy.c	ft_strsub.c \
		  ft_isprint.c	ft_memdel.c		ft_putnbr.c		ft_strcpy.c \
		  ft_strlcat.c	ft_strnequ.c    ft_strtrim.c	ft_putnbr_fd.c \
		  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c \
		  ft_lstiter.c	ft_lstmap.c		ft_strrev.c		ft_power.c \
		  ft_islower.c	ft_isupper.c	ft_isspace.c	get_next_line.c \
		  ft_queuestr.c	ft_lstaddend.c	ft_nblen.c		ft_realloc.c \
		  ft_sort_params.c	ft_printf.c

LSRCS	=	$(addprefix $(LSRCDIR), $(LSRC))
LOBJS 	=	$(addprefix $(LOBJDIR), $(LSRC:.c=.o))
SRCS	=	$(addprefix $(SRCDIR), $(SRC))
OBJS	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LOBJS)
	@ar rc $(NAME) $(OBJS) $(LOBJS)
	@ranlib $(NAME)

$(LOBJDIR)%.o:$(LSRCDIR)%.c $(LHEADER)libft.h
	@$(CC) -o $@ $(FLAG) -c $< -I $(LHEADER)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)libftprintf.h
	@$(CC) -o $@ $(FLAG) -c $< -I $(HEADER)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LOBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
