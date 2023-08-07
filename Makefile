# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 13:03:58 by oezzaou           #+#    #+#              #
#    Updated: 2023/08/07 14:36:27 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
################################################################################
#								VARIABLES:									   #
################################################################################
NAME		:= ForceBreak
CFLAGS		:= -Wall -Wextra -Werror
CC			:= cc
RM			:= rm -rf
SRCS_DIR	:= srcs
OBJS_DIR	:= objs
INCLUDES	:= includes
SRCS		:= $(wildcard */*.c)
OBJS		:= $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))

################################################################################
#                                 RULES:                                       #
################################################################################
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $@

run:
	./$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re
################################# (END) ########################################
