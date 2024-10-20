# Compiler
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror

# Directories
SRCDIR := srcs
INCDIR := includes
OBJDIR := objs

# Files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
EXEC := program

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(EXEC)

.PHONY: all clean