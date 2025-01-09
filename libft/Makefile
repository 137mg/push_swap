# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/10 15:11:23 by mgoedkoo      #+#    #+#                  #
#    Updated: 2023/04/06 15:48:14 by mgoedkoo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
SRCS =		ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c
PF_SRCS =	ft_printf/ft_printf.c\
			ft_printf/va_deciders.c\
			ft_printf/va_makers.c\
			ft_printf/va_printers.c
OBJS =		$(SRCS:%.c=%.o)
PF_OBJS =	$(PF_SRCS:ft_printf/%.c=%.o)
CFLAGS +=	-Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -f $(OBJS) $(PF_OBJS)
	@echo "$(NAME) cleaned up nicely"

fclean:
	rm -f $(NAME)
	@echo "$(NAME) fcleaned up nicely"

re: fclean all

$(NAME): $(OBJS) $(PF_OBJS)
	ar -rcs $(NAME) $(OBJS) $(PF_OBJS)
	@echo "$(NAME) is ready"

$(OBJS): %.o : %.c
	gcc $(CFLAGS) -c $< -o $@
	@echo "the libft o-files are ready"

$(PF_OBJS): %.o : ft_printf/%.c
	gcc $(CFLAGS) -c $< -o $@
	@echo "the ft_printf o-files are ready"

.PHONY: all clean fclean re