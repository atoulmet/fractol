# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 16:31:19 by atoulmet          #+#    #+#              #
#    Updated: 2017/02/23 17:56:50 by atoulmet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC_PATH = srcs/

SRCS = julio.c put_string.c celtic.c burningship.c init_color.c zoom.c julia.c mandelbrodt.c events.c ft_error.c put_color_pixel.c choose_fract.c env_img_init.c main.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH),$(SRCS))

FLAGS = -Wall -Wextra -Werror 

INC = -I ./includes/ -I./libft

LIB = -L minilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $< -o $@ $(INC)

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
