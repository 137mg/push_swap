# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/10 15:29:03 by mgoedkoo      #+#    #+#                  #
#    Updated: 2023/04/06 20:37:13 by mgoedkoo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
BONUS =		checker
SRCS =		err_check.c\
			make_op.c\
			make_stack.c\
			main.c\
			push_swap.c\
			sort_large.c\
			sort_medium.c\
			sort_small.c\
			stack_checks.c\
			t_stack.c
B_SRCS =	bonus/checker_bonus.c\
			bonus/err_check_bonus.c\
			bonus/free_mem_bonus.c\
			bonus/main_bonus.c\
			bonus/make_op_bonus.c\
			bonus/sort_stack_bonus.c\
			bonus/t_stack_bonus.c
OBJS =		$(SRCS:%.c=%.o)
B_OBJS =	$(B_SRCS:bonus/%.c=%.o)
LIBFT =		libft/
CFLAGS +=	-Wall -Wextra -Werror

all: $(NAME)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS) $(B_OBJS)
	@echo "$(NAME) cleaned up nicely"

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME) $(BONUS)
	@echo "$(NAME) fcleaned up nicely"

re: fclean all

bonus: $(NAME) $(B_OBJS)
	gcc $(C-FlAGS) -o $(BONUS) $(B_OBJS) -L libft/ -lft
	@echo "$(BONUS) is ready"

$(NAME): $(OBJS)
	@make libft.a -C $(LIBFT) clean
	gcc $(C-FlAGS) -o $(NAME) $^ -L libft/ -lft
	@echo "$(NAME) is ready"

$(OBJS): %.o : %.c
	gcc $(CFLAGS) -c $< -o $@
	@echo "the $(NAME) o-files are ready"

$(B_OBJS): %.o : bonus/%.c
	gcc $(CFLAGS) -c $< -o $@
	@echo "the $(BONUS) o-files are ready"

.PHONY: all clean fclean re bonus