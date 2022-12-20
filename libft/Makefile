NAME	=	libft.a

CC		=	cc

CFLAGS	= 	-Wall -Wextra -Werror

SRCS 	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_toupper.c \
				ft_tolower.c ft_strncmp.c ft_memcmp.c ft_strrchr.c ft_strnstr.c \
				ft_strdup.c ft_strjoin.c ft_substr.c ft_strlen.c ft_strlcpy.c \
				ft_strlcat.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strtrim.c \
				ft_split.c ft_strchr.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				get_next_line/get_next_line.c get_next_line/ft_strchrr.c \
				get_next_line/ft_strlenn.c ft_printf/ft_printf.c ft_printf/ft_printf_char.c \
				ft_printf/ft_printf_number.c ft_printf/ft_printf_utils.c \
				ft_printf/ft_printf_len.c send_error.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS	= $(BONUS:.c=.o)   

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
