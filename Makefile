NAME = factrace
SRCS = 	main.c \
		ft_bzero.c \
		ft_lstnew.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strnew.c \
		ft_strrchr.c \
		ft_strsub.c \
		get_next_line.c \
		ft_strsplit.c \
		my_ft_lettercount.c \
		my_ft_wordcount.c \
		ft_atoi.c \
		f_wright_exact_length.c \
		my_ft_setyourchar.c

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): *.o
	$(CC) *.o libgmp.a -Wl,-no_pie -o $(NAME)

%.o:%.c
	$(CC) -c $^ -I gmp-6.1.2 #libgmp.a -Wl,-no_pie

clean:
	/bin/rm -rf *.o *.out

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

