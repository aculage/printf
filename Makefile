NAME			=	libftprintf.a
SRCS_PRINTF_DIR =	./srcs/
HDRS_PRINTF		=	./hdrs/
SRCS_PRINTF		=	ft_init.c \
					ft_mask.c \
					ft_printf.c \
					ft_printcaller.c \
					ft_printfunc.c \
					ft_printint.c \
					ft_printuint.c \
					ft_printstr.c \
					ft_printhex.c \
					ft_printptr.c \
					ft_supportive.c \
					ft_supportive2.c 
SRCS_PRINTF_AGG =	$(addprefix $(SRCS_PRINTF_DIR), $(SRCS_PRINTF))
OBJS_PRINTF		=	$(SRCS_PRINTF_AGG:.c=.o)
SRCS_ALL_D		=	$(SRCS_PRINTF_AGG:.c=.d)
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(HDRS_PRINTF) 
AR				=	ar
ARFLAGS			=	rcs
RM				=	rm -f


$(NAME):	$(OBJS_PRINTF) Makefile
				$(AR) $(ARFLAGS) $(NAME) $(OBJS_PRINTF)

all:	$(NAME)

include	$(wildcard $(SRCS_ALL_D))

$(SRCS_PRINTF_DIR)/%.o: $(SRCS_PRINTF_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ -MD

bonus:	$(NAME)

debug:	
			$(CC) -g -I $(HDRS_PRINTF) $(SRCS_PRINTF_AGG) main.c -o debug.out 
clean:
			$(RM) $(OBJS_LIBFT) $(OBJS_PRINTF) $(SRCS_ALL_D)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re 