LIBFT =		libft.a
SRCS_L =	ft_lstaddback.c		ft_memcpy.c		ft_putstr_fd.c		ft_strlcat.c	ft_strstr.c\
			ft_lstat.c			ft_memdel.c		ft_strcat.c			ft_strlen.c		ft_strstrn.c\
			ft_atoi.c			ft_lstdel.c		ft_memmove.c		ft_strchr.c		ft_strmap.c\
			ft_strsub.c			ft_bzero.c		ft_lstdelone.c		ft_memset.c		ft_strclr.c\
			ft_strmapi.c		ft_strtrim.c	ft_isalnum.c		ft_lstiter.c	ft_numwords.c\
			ft_strcmp.c			ft_strncat.c	ft_tolower.c		ft_strcpy.c		ft_strncmp.c\
			ft_isalpha.c		ft_lstmap.c		ft_putchar.c		ft_toupper.c	ft_isascii.c\
			ft_putchar_fd.c		ft_lstnew.c		ft_strdel.c			ft_strncpy.c	ft_striteri.c\
			ft_isdigit.c		ft_lstsize.c	ft_putendl.c		ft_strdup.c		ft_strnequ.c\
			ft_isprint.c		ft_memalloc.c	ft_putendl_fd.c		ft_strequ.c		ft_strnew.c\
			ft_iswhitespace.c	ft_memccpy.c	ft_putnbr.c			ft_striter.c	ft_strnstr.c\
			ft_itoa.c			ft_memchr.c		ft_putnbr_fd.c		ft_strrchr.c	ft_putstr.c\
			ft_lstadd.c			ft_lstsort.c	ft_memcmp.c			ft_strjoin.c	ft_strsplit.c\
			get_next_line.c		ft_maxarr.c		ft_minarr.c			ft_arrdel.c		ft_arrdup.c\
			ft_count_words.c	ft_sqrtint.c	ft_pow.c			ft_wordlen.c	ft_putstr_multiple.c	
OBJS_L =		$(SRCS_L:.c=.o)
INCLUDES_L =	includes/
HEADER_L =		includes/libft.h

DELETE_PREV =	"\x1b[A\x1b[K"

all: $(LIBFT)

$(LIBFT): $(OBJS_L)
	@ar rc $(LIBFT) $(OBJS_L)
	@ranlib $(LIBFT)

%.o: %.c $(HEADER_L)
	@gcc -Wall -Wextra -Werror -I $(INCLUDES_L) -c $< -o $@
	@echo $(DELETE_PREV) "\x1b[36m\b" created: "\x1b[97;46m" $(@:%=%) "\x1b[0m" 

clean:
	@rm -rf $(OBJS_L)
	@echo "\x1b[31m" [X] libft objects "\x1b[0m"

fclean: clean
	@rm -rf $(LIBFT)
	@echo "\x1b[31m" [X] $(LIBFT) "\x1b[0m"

re: fclean all

.PHONY: all clean fclean re