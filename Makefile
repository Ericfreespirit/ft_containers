NAME = ft_container
CC = clang++
CONTAINER = container/vector.hpp
INCLUDE = include/iterator_traits.hpp \
		  include/random.hpp \

CPPFLAGS = -Wall -Wextra -std=c++98 -MMD -MP -Icontainer -Iinclude

FILES = my_main.cpp 


SRC_PATH = $(shell find src -type d)
vpath %.cpp $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/,$(FILES:%.cpp=%.o))

all :   $(NAME) 

$(NAME) :  $(OBJ_PATH) $(OBJ_PATH) $(OBJ) $(CONTAINER) $(INCLUDE)
	@$(CC) $(CPPFLAGS) $(OBJ) -o ${NAME}

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
