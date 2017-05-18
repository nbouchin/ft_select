# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 12:55:49 by nbouchin          #+#    #+#              #
#    Updated: 2017/05/18 17:16:31 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_select
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
LIB		= libft/libft.a
HEADER	= include/
LIBSRC	= libft/
SRCDIR	= src/
OBJDIR	= obj/
SRC		= ft_select.c	list_utils.c		term_mode.c		key_utils.c		print_utils.c \
		  arrow_utils.c	perfect_collumn.c	node_utils.c	signal_utils.c	

# colors

GRN		=	\033[0;32m
RED		=	\033[0;31m
CYN		=	\033[0;36m
NC		=	\033[0m

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -L./$(LIBSRC) -lft -ltermcap -o $(NAME) $(OBJS)
	@echo "\n${CYN}PROCESSING DONE !${NC}"

$(LIB):
	@echo "${CYN}Processing ${NC}./libft/obj ${CYN}[${NC}...${CYN}]${NC}"
	@make -C $(LIBSRC)
	@echo "\n${CYN}Processing ${NC}./obj ${CYN}[${NC}...${CYN}]${NC}"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)$(NAME).h
	@echo "${GRN}Compiling${NC} $@"
	@$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER)

clean:
	@echo "${RED}Cleaning ${NC}./obj/ ${RED}[${NC}...${RED}]${NC}"
	@rm -rf $(OBJS)
	@echo "${RED}Cleaning ${NC}./libft/obj/ ${RED}[${NC}...${RED}]${NC}"
	@make -C $(LIBSRC) clean

fclean: clean
	@echo "${RED}Cleaning ${NC}./${RED}ft_ls${NC}"
	@rm -Rf $(NAME)
	@echo "${RED}Cleaning ${NC}./libft/${RED}libft.h${NC}\n"
	@make -C $(LIBSRC) fclean
	@echo "${RED}DELET DONE !${NC}"

re: fclean all

.PHONY: all clean fclean re
