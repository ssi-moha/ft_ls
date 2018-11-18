NAME = ft_ls

CC = gcc

INCLUDES = includes

SRCDIR = srcs

OBJDIR = objects

H = includes/ft_ls.h

LIB = printfast/printfast.a

CFLAGS = -Wall -Wextra -Werror

SRC = $(SRCDIR)/handle_options.c $(SRCDIR)/add_file_to_list.c

OBJ= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): build $(OBJ)
	make -C printfast
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) main.c

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

build:
	mkdir -p objects

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c -o $@ $< $(CFLAGS) -I$(INCLUDES)
