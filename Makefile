NAME = ft_ls

CC = gcc

INCLUDES = includes

SRCDIR = srcs

OBJDIR = objects

H = includes/ft_ls.h

LIB = printfast/printfast.a

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC = $(SRCDIR)/set_options.c $(SRCDIR)/add_file_to_list.c \
  $(SRCDIR)/sort_list.c $(SRCDIR)/ft_ls.c $(SRCDIR)/check_option.c\
  $(SRCDIR)/add_filename_to_path.c $(SRCDIR)/check_file_access.c\
  $(SRCDIR)/free_list.c $(SRCDIR)/handle_file_from_stat.c $(SRCDIR)/get_file_informations.c\
  $(SRCDIR)/get_username_from_uid.c $(SRCDIR)/get_groupname_from_gid.c\
  $(SRCDIR)/get_last_modification_time.c $(SRCDIR)/get_last_update_timestamp.c
   

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): build $(OBJ)
	make -C printfast
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) main.c

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
	make clean -C printfast


fclean: clean
	rm -rf $(NAME)
	make fclean -C printfast

re: fclean all

build:
	mkdir -p objects

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c -o $@ $< $(CFLAGS) -I$(INCLUDES)
