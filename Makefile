#Program variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

#Files variables
LIBFT = sources/libft
SRCS_FILES =	main.c \
				checkers/input.c \
				operations/utils.c \
				operations/sa.c \
				operations/sb.c \
				operations/ss.c \
				operations/pa.c \
				operations/pb.c \
				operations/ra.c \
				operations/rb.c \
				operations/rr.c \
				operations/rra.c \
				operations/rrb.c \
				operations/rrr.c
SRCS = $(addprefix sources/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
INCLS = includes/

#Extra variables
RESET = \033[1;39m
BOLD= \033[1m
GREEN= \033[1;32m
BLUE= \033[1;34m

#Commands
all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C $(LIBFT) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)/libft.a
	@echo "$(BOLD)[$(NAME)] Makefile : $(GREEN)Executable created successfully!$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLS)
	@echo "$(BOLD)[$(NAME)] Makefile : $(BLUE)Scripts compiled.$(RESET)"

clean :
	@make clean -C $(LIBFT) --no-print-directory
	@rm -f $(OBJS)
	@echo "$(BOLD)[$(NAME)] Makefile : $(BLUE)Objects files removed.$(RESET)"

fclean : clean
	@make fclean -C $(LIBFT) --no-print-directory
	@rm -f $(NAME)
	@echo "$(BOLD)[$(NAME)] Makefile : $(BLUE)Executable removed.$(RESET)"

re : fclean all

.PHONY : all clean fclean re