NAME= libft.a

SOURCE= ft_isprint.c \
	   ft_strlen.c \
	   ft_atoi.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_isdigit.c \
	   ft_isalpha.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

BONUS= ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c

OSOURCE= $(SOURCE:.c=.o)

OBONUS= $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c $< -Wall -Werror -Wextra -o $@ -I ./

$(NAME): $(OSOURCE)
	ar rc $@ $^
	ranlib $@

bonus: $(OSOURCE) $(OBONUS)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -rf $(OSOURCE) $(OBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all
