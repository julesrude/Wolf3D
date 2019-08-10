NAME =			wolf3d

SRCS =			main.c\
				validate_map.c\
				init_wolf.c\
				init_mlx.c\
				map_tostruct.c\
				cast_rays.c\
				draw_ray.c\
				distance_to_walls.c\
				actions.c

OBJS_PATH =		objs/
OBJS =			${addprefix $(OBJS_PATH), ${SRCS:%.c=%.o}}
INCLUDES =		includes/
HEADER =		includes/wolf3d.h
HEADER_KEYS =	includes/keyboard.h

LIBFT =			libft/libft.a
INCLUDES_L =	libft/includes/
#HEADER_L =		libft/includes/libft.h

LIBX =			minilibx/libmlx.a
LIBX_FOLDER =	minilibx/
LIBX_FLAGS =	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

COMPILE =		gcc -Wall -Wextra -Werror
DELETE_PREV =	"\x1b[A\x1b[K"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_PATH) $(OBJS)
	@$(COMPILE) $(OBJS) -I $(INCLUDES) -I $(INCLUDES_L) $(LIBFT) $(LIBX_FLAGS) -o $(NAME)
	@echo "\n 	\x1b[36m" [ 💁 $(NAME) ] "\x1b[0m\n"

$(OBJS_PATH)%.o: %.c $(HEADER) $(HEADER_KEYS)
	@$(COMPILE) -I $(INCLUDES) -I $(INCLUDES_L) -c $< -o $@
	@echo "\x1b[36m" created: "\x1b[97;46m" $(@:objs/%=%) "\x1b[0m"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(LIBFT):
	@make -C libft
	@echo "\n 	\x1b[36m" [ 💁 $(LIBFT) ] "\x1b[0m\n"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\x1b[31m" [X] $(OBJS_PATH) "\x1b[0m"
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\x1b[31m" [X] $(NAME) "\x1b[0m"
	@rm -rf $(LIBFT)
	@echo "\x1b[31m" [X] $(LIBFT) "\x1b[0m\n\n"

re: fclean all

