# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 01:21:35 by roliveir          #+#    #+#              #
#    Updated: 2019/06/06 09:37:38 by oboutrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes/
LIB_INC_PATH = libft/includes/
OBJ_PATH = objs/

SRC_PARS_PATH = srcs/pars/
SRC_FDF_PATH = srcs/fdf/
SRC_PATH = srcs/

LIBFT_FLAG = -Llibft -lft
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

SRC_NAME = main.c error_manager.c

SRC_PARS_NAME = pars_main.c			\
				pars_build_line.c	\
				pars_max_min.c		\
				pars_normal.c		\
				pars_map.c			\
				init_pile.c			\
				free_pile.c			\
				ft_atoip_err.c

SRC_FDF_NAME = fdf_main.c			\
			   fdf_fill.c			\
			   fdf_print.c			\
			   fdf_print_hor_ver.c	\
			   fdf_print_diagup.c	\
			   fdf_print_diagdo.c	\
			   fdf_key.c			\
			   fdf_mat_rotation.c	\
			   fdf_mode.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PARS_NAME = $(SRC_PARS_NAME:.c=.o)
OBJ_FDF_NAME = $(SRC_FDF_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_PARS = $(addprefix $(OBJ_PATH), $(OBJ_PARS_NAME))
OBJ_FDF = $(addprefix $(OBJ_PATH), $(OBJ_FDF_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(OBJ_PARS) $(OBJ_FDF)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) -I $(INC_PATH) -I $(LIB_INC_PATH)\
		-I minilibx/ $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME) $(OBJ)\
		$(OBJ_PARS) $(OBJ_FDF)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2>&-
$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_PARS_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
$(OBJ_PATH)%.o : $(SRC_FDF_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ) $(OBJ_PARS) $(OBJ_FDF)
	@rm -rf $(OBJ_PATH) 2>&-

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
