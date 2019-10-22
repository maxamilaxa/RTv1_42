# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 21:20:29 by mkopiika          #+#    #+#              #
#    Updated: 2019/10/20 14:06:48 by mkopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= RTv1

CC_FLG  = -Wall -Wextra -Werror

SOURCES		:=	calc_shapes_norml.c \
            calculate_tracing.c     \
            clamp_func.c            \
            get_error.c             \
            is_hit_shape.c          \
            light_compute.c         \
            main.c                  \
            node_initialization.c   \
            program_loop.c          \
            read_scene.c            \
            read_valid_malloc.c     \
            tools.c                 \
            valid_rows_scene.c      \
            value_parsing.c         \
            vectors.c               \
            get_next_line_mod.c     \


DIR_SRC := $(CURDIR)/src
DIR_OBJ := $(CURDIR)/obj
OBJ_SRC  := $(SOURCES:.c=.o)
OBJ_SRC  := $(addprefix $(DIR_OBJ)/, $(OBJ_SRC))
SOURCES := $(addprefix $(DIR_SRC)/, $(SOURCES))
INCL_LB   =	-I libft/ \
			-I inc/
LIBFT    = libft/libft.a

FR_SDL  	=	-F frameworks
FLG_SDL 	=	-rpath frameworks		\
			-framework SDL2 		\

INCL_SDL   	=	-I $(CURDIR)/frameworks/SDL2.framework/Headers/ 		\


all: $(NAME)

$(LIBFT):
	@make -C libft/

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(NAME): $(LIBFT) $(OBJ_SRC)
	gcc $(OBJ_SRC) $(FR_SDL) $(FLG_SDL) -L libft -lft -o $(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	gcc $(CC_FLG) $(FR_SDL) $(INCL_SDL) $(INCL_LB) -c $< -o $@

clean:
	@make -C libft/ clean
	/bin/rm -rf $(OBJ_SRC)
	/bin/rm -rf $(DIR_OBJ)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re