# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -I./include -Wall -Wextra -pedantic

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte e objeto
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET = $(BINDIR)/programa

# Regra padrão
all: $(TARGET)

# Regra para ligar o executável final
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $(OBJECTS)

# Regra para compilar arquivos .c em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(BINDIR):
	mkdir -p $(BINDIR)
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean