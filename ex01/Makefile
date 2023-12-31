NAME	= tests

OBJ_DIR	= ./obj
SRC_DIR = .

CC 		= c++
CFLAGS 	= -MP -MMD -I$(SRC_DIR) -Wall -Wextra -Werror -Wpedantic -g -std=c++98
SHELL	= /bin/sh

SRCS	= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

all: $(NAME)

run: all
	./$(NAME)

leaks: all
	leaks -q --atExit -- ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
	$(CC) $(CFLAGS) -o $@ $^
# Add the debugging tool entitlement when building on OS X
ifneq ($(OS),Windows_NT)
ifeq ($(shell uname -s),Darwin)
	/usr/libexec/PlistBuddy -c \
	"Add :com.apple.security.get-task-allow bool true" \
	tmp.entitlements
	codesign -s - -f --entitlements tmp.entitlements ./$(NAME)
	rm -rf tmp.entitlements
endif
endif

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all leaks re clean fclean run

vpath %.cpp $(SRC_DIR)
-include $(SRCS:%.cpp=$(OBJ_DIR)/%.d)
