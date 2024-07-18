CC      = cc -O2
FLAGS   = -Wall -Wextra -Werror
NAME    = fractol
LIBFT   = libft
MLX     = minilibx-linux
OBJ_PATH = objs
HEADER  = includes

CFLAGS += -I /opt/X11/include
LDFLAGS += -L /opt/X11/lib -lX11 -lXext

SOURCES = $(wildcard srcs/*.c)
OBJS = $(patsubst srcs/%.c, $(OBJ_PATH)/%.o, $(SOURCES))

GREEN   = \033[1;32m
BCYAN	= \033[1;36m

ifeq ($(UNAME), Linux)
    FLAGS += -D LINUX
endif

all: lib $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)
	$(shell mv $(LIBFT)/*.o $(OBJ_PATH))

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -L $(LIBFT) -L $(MLX) -lft -lmlx $(LDFLAGS) -lm
	@echo "$(GREEN)Project successfully compiled"
	@echo ""
	@echo "$(BCYAN)╔════════════════════════════════════════════════════╗"
	@echo "$(BCYAN)║                   Fractol Usage                    ║"
	@echo "$(BCYAN)║____________________________________________________║"
	@echo "$(BCYAN)║                                                    ║"
	@echo "$(BCYAN)║                ./fractol Mandelbrot                ║"
	@echo "$(BCYAN)║                                                    ║"
	@echo "$(BCYAN)║                ./fractol Julia x y                 ║"
	@echo "$(BCYAN)║                                                    ║"
	@echo "$(BCYAN)║         x and y have to be between -2 and 2        ║"
	@echo "$(BCYAN)║                                                    ║"
	@echo "$(BCYAN)║                ./fractol 'Burning Ship'            ║"
	@echo "$(BCYAN)║                                                    ║"
	@echo "$(BCYAN)╚════════════════════════════════════════════════════╝"

$(OBJ_PATH)/%.o: srcs/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -c -g -o $@ $< -I /opt/X11/include

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX)

fclean: clean
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all lib tmp clean fclean re