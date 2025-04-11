NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
INCDIR = include
SRCS = main.c parse.c init.c utils.c time.c routine.c monitor.c cleanup.c
OBJS = $(addprefix $(SRCDIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/philo.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re