NAME_SERVER = server

NAME_CLIENT = client

SRC_SERVER = server.c \
	ft_putnbr.c \

SRC_CLIENT = client.c \
	ft_atoi.c

DIR_S = srcs

SRCS_SERVER = $(addprefix ${DIR_S}/, ${SRC_SERVER})

SRCS_CLIENT = $(addprefix ${DIR_S}/, ${SRC_CLIENT})

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CFLAGS = -I./ -Wall -Wextra -Werror

all	: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER)
			gcc -o $(NAME_SERVER) $(SRCS_SERVER) $(CFLAGS)

$(NAME_CLIENT) : $(OBJS_CLIENT)
			gcc -o $(NAME_CLIENT) $(SRCS_CLIENT) $(CFLAGS)

clean	:
			rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean	: clean
			rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all

.PHONY: re clean fclean all