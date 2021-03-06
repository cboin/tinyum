CC=gcc
LD=gcc -o
OBJDIR=bin
SRCDIR=src
DOXYFILE=Doxyfile
DOCDIR=doc
INCDIR=include
EXE=tinyum
CFILES:=$(wildcard $(SRCDIR)/*.c)
INCLUDES:=$(wildcard $(INCDIR)/*.h)
OBJECTS:=$(CFILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS=-Wall -Wextra -W -Werror -Wwrite-strings -Wshadow -Wstrict-overflow -fno-strict-aliasing -Wno-missing-field-initializers -O2 -g
LDFLAGS=-lpthread
MKDIR_P=mkdir -p

.PHONY:all clean mrproper directories doc

all: directories $(EXE)

$(EXE): $(OBJECTS)
	$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o  $@
	@echo "Compiled "$<" successfully!"

doc: 
	$(MKDIR_P) $(DOCDIR)
	doxygen $(DOXYFILE)
	@echo "Generate doc !"

directories: $(OBJDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)
	@echo "Create "$(OBJDIR)" folder!"
clean:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

mrproper: clean
	$(rm) $(EXE)
	@echo "Executable removed!"
