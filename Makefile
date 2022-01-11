NAME =libftprintf.a

SRCS =  src/ft_printf.c\
	src/ft_go_struct.c\
	src/ft_print_character.c\
	src/ft_print_hexa.c\
	src/ft_print_number.c\
	src/ft_print_pointer.c\
	src/ft_print_string.c\
	src/ft_print_unsint.c\

O_LIBFT = ./libft/ft_atoi.o\
	  ./libft/ft_bzero.o\
	  ./libft/ft_calloc.o\
	  ./libft/ft_isalnum.o\
	  ./libft/ft_isalpha.o\
	  ./libft/ft_isascii.o\
	  ./libft/ft_isdigit.o\
	  ./libft/ft_isprint.o\
	  ./libft/ft_itoa.o\
	  ./libft/ft_itoa_base.o\
	  ./libft/ft_itoa_base_more.o\
	  ./libft/ft_memccpy.o\
	  ./libft/ft_memchr.o\
	  ./libft/ft_memcmp.o\
	  ./libft/ft_memcpy.o\
	  ./libft/ft_memmove.o\
	  ./libft/ft_memset.o\
	  ./libft/ft_putchar_fd.o\
	  ./libft/ft_putchar_fd_return.o\
	  ./libft/ft_putendl_fd.o\
	  ./libft/ft_putnbr_fd.o\
	  ./libft/ft_putnbr_unsigned.o\
	  ./libft/ft_putstr_fd.o\
	  ./libft/ft_split.o\
	  ./libft/ft_strchr.o\
	  ./libft/ft_strdup.o\
	  ./libft/ft_strjoin.o\
	  ./libft/ft_strlcat.o\
	  ./libft/ft_strlcpy.o\
	  ./libft/ft_strlen.o\
	  ./libft/ft_strmapi.o\
	  ./libft/ft_strncmp.o\
	  ./libft/ft_strnstr.o\
	  ./libft/ft_strrchr.o\
	  ./libft/ft_strtrim.o\
	  ./libft/ft_substr.o\
	  ./libft/ft_tolower.o\
	  ./libft/ft_toupper.o\
	  ./libft/ft_strjoin_f12.o\

O_FILES = $(SRCS:.c=.o)

LIBFT = libft.a

FLAGS = -Wall -Werror -Werror

HEADER = ft_printf.h

all : $(NAME)

$(NAME): $(LIBFT) $(O_FILES)
	ar crs $(NAME) $(O_FILES) $(O_LIBFT)	

$(LIBFT):
	make -C libft

.c.o:
	gcc ${FLAGS} -I ${HEADER} -c $< -o $(<:.c=.o)

clean :
	make clean -C libft
	rm -f ${O_FILES}

fclean : clean
	make fclean -C libft
	cd libft; rm -f $(LIBFT); cd ..
	rm -f ${NAME}

re : fclean all
