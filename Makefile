# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmallado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 19:21:22 by lmallado          #+#    #+#              #
#    Updated: 2020/07/13 19:21:30 by lmallado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = includes/

LIBFT_DIR = ./libft/libft.a

SRCS = ./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c \
	./SRCS/main.c \
	./SRCS/moving_handler/handle_collisions.c \
	./SRCS/moving_handler/moving_handler.c \
	./SRCS/moving_handler/moving_handler_utils.c \
	./SRCS/screen/screen.c \
	./SRCS/screen/loader.c \
	./SRCS/screen/screen_utils.c \
	./SRCS/draw_sprite/draw_sprite.c \
	./SRCS/draw_sprite/draw_sprite_utils.c \
	./SRCS/draw_walls/draw_walls.c \
	./SRCS/draw_walls/draw_walls_utils.c \
	./SRCS/draw_walls/pole_checker.c \
	./SRCS/tools/draw_back.c \
	./SRCS/tools/screenshot/screenshot_maker.c \
	./SRCS/draw_world.c \
	./SRCS/tools/map_reader/map_reader.c \
	./SRCS/tools/map_reader/map_reader_utils.c \
	./SRCS/tools/map_reader/line_parser.c \
	./SRCS/tools/map_reader/parse_color.c \
	./SRCS/tools/map_reader/parse_r.c \
	./SRCS/tools/map_reader/parse_texture.c \
	./SRCS/tools/parser/init_spritelist.c \
	./SRCS/tools/parser/parser.c \
	./SRCS/tools/parser/parser_utils.c \
	./SRCS/tools/managers/error_manager.c

O_FILE = $(patsubst %.c,%.o,$(SRCS))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILE)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx all
	gcc $(CFLAGS) $(O_FILE) $(LIBFT_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c ./includes/cub3d.h
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(O_FILE)
	rm -f $(D_FILE)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean

re:		fclean all

.PHONY : all clean fclean re
