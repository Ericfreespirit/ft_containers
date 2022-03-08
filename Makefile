
NAME = ft_container
CC = clang++ 
FILE_HPP = container/vector.hpp \
	include/iterator_vector.hpp \
	include/const_iterator_vector.hpp \
	include/reverse_iterator_vector.hpp \
	include/const_reverse_iterator_vector.hpp \
	utils/traits.hpp \
	utils/algorithm.hpp \
	src/our_test/AllTest.hpp \

CPPFLAGS = -Wall -Wextra -std=c++98 -MMD -MP -Icontainer -Iinclude -Iutils 
<<<<<<< HEAD
BUGFLAGS = -fsanitize=address -g3
=======
# BUGFLAGS = -fsanitize=address -g
>>>>>>> 828b84479a8eb422fe64bd77387969c4c4c336bd

FILES = my_main.cpp \
		testErase.cpp\
		testResize.cpp\
		testAssign.cpp\



SRC_PATH = $(shell find src -type d)
vpath %.cpp $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/,$(FILES:%.cpp=%.o))

all :   $(NAME) 

$(NAME) :  $(OBJ_PATH) $(OBJ) $(FILE_HPP) 
	@$(CC)  $(CPPFLAGS)$(BUGFLAGS)  $(OBJ) -o ${NAME}

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@
-include $(OBJ:.o=.d)


clean:
	@rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean 