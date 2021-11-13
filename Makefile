NAME = libasm.a
NAME_BONUS = libasm_bonus.a

CC = gcc
ASM_CC = nasm
FORMAT = macho64
FLAGS = -Werror -Wextra -Wall

SRCS_DIR = ./srcs/
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS = ft_list_size.s
SRCS_FILES = $(addprefix $(SRCS_DIR), $(SRCS))
SRCS_BONUS_FILES = $(addprefix $(SRCS_DIR), $(SRCS_BONUS))

OBJ = $(SRCS:.s=.o)
OBJ_BONUS = $(SRCS_BONUS:.s=.o)
OBJ_DIR = ./objects/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_FILES_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

GREEN = \033[0;32m
RESET = \033[0;0m

all: $(NAME)

$(NAME): $(OBJ_FILES) $(SRCS_FILES) ./srcs/libasm.h
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)
	@echo "$(GREEN) $(NAME) created $(RESET)"

clean:
	@rm -rf objects
	@echo "$(GREEN) ./objects deleted $(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f test_asm
	@rm -f test_bonus
	@rm -f test.txt
	@echo "$(GREEN) ALL FILES DELETED $(RESET)"

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_FILES_BONUS) $(SRCS_BONUS_FILES) ./srcs/libasm_bonus.h
	ar rc $(NAME_BONUS) $(OBJ_FILES_BONUS)
	ranlib $(NAME_BONUS)
	@echo "$(GREEN) $(NAME_BONUS) created $(RESET)"

test: all
	$(CC) $(FLAGS) -c ./test/main.c -o ./objects/main.o -I./srcs/
	$(CC) $(FLAGS) ./objects/main.o -L. -lasm -o test_asm
	./test_asm

test_bonus: bonus
	$(CC) $(FLAGS) -c ./test/main_bonus.c -o ./objects/main_bonus.o -I./srcs/ -I./test/
	$(CC) $(FLAGS) ./objects/main_bonus.o -L. -libasm_bonus -o test_bonus -L./test/ -lft
	./test_bonus

$(OBJ_DIR)%.o: $(SRCS_DIR)%.s
	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)
	@$(ASM_CC) -f $(FORMAT) $^ -o $@



