BUILD_DIR = build
SRCS_DIR = src

INCLUDE_FLAGS = -I./src
LD_FLAGS = -lpthread -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS = -std=c++17 -Wall -Wshadow -fsanitize=undefined -fsanitize=address

SRCS = $(shell find $(SRCS_DIR) -name '*.cpp' -or -name '*.c')
OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)

$(info SRCS = $(SRCS))
$(info OBJS = $(OBJS))

-include $(shell find $(BUILD_DIR) -name '*.d')

game: $(OBJS)
	g++ $(OBJS) -o main $(CXXFLAGS) $(LD_FLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	g++ -c $< -o $@ -MMD $(CXXFLAGS) $(INCLUDE_FLAGS) $(LD_FLAGS)

clean:
	find $(BUILD_DIR) -name "*.o" -delete && find $(BUILD_DIR) -name "*.d" -delete
