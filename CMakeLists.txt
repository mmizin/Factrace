cmake_minimum_required(VERSION 3.9)
project(Factrace)

set(CMAKE_CXX_STANDARD 11)

include_directories(gmp-6.1.2)

add_executable(Factrace
        f_ljoin_free.c
        f_wright_exact_length.c
        ft_atoi.c
        ft_bzero.c
        ft_lstnew.c
        ft_memccpy.c
        ft_memcpy.c
        ft_memdel.c
        ft_memmove.c
        ft_memset.c
        ft_strchr.c
        ft_strclr.c
        ft_strdup.c
        ft_strjoin.c
        ft_strlen.c
        ft_strncat.c
        ft_strnew.c
        ft_strrchr.c
        ft_strsub.c
        get_next_line.c
        libft.h
        main.c
        my_ft_setyourchar.c)

target_link_libraries(Factrace /Users/nmizin/Factrace/libgmp.a -Wl,-no_pie)