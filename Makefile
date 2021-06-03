NAME			=	libftprintf.a
SRCS_PRINTF_DIR =	./srcs/
SRCS_LIBFT_DIR 	=	./libft/
HDRS_PRINTF		=	./hdrs/
SRCS_PRINTF		=	ft_init.c \
					ft_mask.c \
					ft_printf.c 
SRCS_LIBFT		=	ft_atoi.c \
					ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
					ft_bzero.c ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c  ft_toupper.c \
					ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c \
					ft_lstclear.c ft_lstdelone.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstsize.c ft_lstiter.c
SRCS_PRINTF_AGG =	$(addprefix $(SRCS_PRINTF_DIR), $(SRCS_PRINTF))
SRCS_LIBFT_AGG	=	$(addprefix $(SRCS_LIBFT_DIR), $(SRCS_LIBFT))
OBJS_PRINTF		=	$(SRCS_PRINTF_AGG:.c=.o)
OBJS_LIBFT		=	$(SRCS_LIBFT_AGG:.c=.o)
SRCS_ALL_D		=	$(SRCS_LIBFT_AGG:.c=.d) $(SRCS_PRINTF_AGG:.c=.d)
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g -I $(HDRS_PRINTF)
AR				=	ar
ARFLAGS			=	rcs
RM				=	rm -f


all:	$(NAME)

include	$(wildcard $(SRCS_ALL_D))

$(SRCS_PRINTF_DIR)/%.o: $(SRCS_PRINTF_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ -MD

$(SRCS_LIBFT_DIR)/%.o: $(SRCS_LIBFT_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ -MD

$(NAME):	$(OBJS_LIBFT) $(OBJS_PRINTF)
				@make -sC ./libft/ all
				$(AR) $(ARFLAGS) $(NAME) $?

bonus:	$(NAME)

debug:	
			@make -sC ./libft/ all
			$(CC) $(CFLAGS) -I $(SRCS_LIBFT_DIR) $(SRCS_LIBFT_DIR)/libft.a $(SRCS_LIBFT_AGG) $(SRCS_PRINTF_AGG) main.c -o debug.out 
clean:
			$(RM) $(OBJS_LIBFT) $(OBJS_PRINTF) $(SRCS_ALL_D)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re 