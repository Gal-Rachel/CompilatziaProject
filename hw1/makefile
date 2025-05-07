# Variables for the files and output
LEXER = scanner.l
PARSER = parser.y
LEX_C = lex.yy.c
PARSER_C = parser.tab.c
PARSER_H = parser.tab.h
AST_C = ast.c
OUTPUT = my_program
TEST_FILE = test_input.txt

# Compiler and flags
CC = gcc
CFLAGS = -g -I.
LEX = flex
BISON = bison
LDFLAGS = -lfl

# Default target: compile everything
all: $(OUTPUT)

# Rule to generate lex.yy.c from scanner.l
$(LEX_C): $(LEXER)
	$(LEX) $(LEXER)

# Rule to generate parser.tab.c and parser.tab.h from parser.y
$(PARSER_C) $(PARSER_H): $(PARSER)
	$(BISON) -d $(PARSER)

# Rule to compile the lexer and parser into the executable
$(OUTPUT): $(LEX_C) $(PARSER_C) $(AST_C)
	$(CC) $(CFLAGS) $(LEX_C) $(PARSER_C) $(AST_C) -o $(OUTPUT) $(LDFLAGS)

# Rule to run the program with the TEST.TXT file and print the AST
run: $(OUTPUT)
	./$(OUTPUT) < $(TEST_FILE)

# Clean up generated files
clean:
	rm -f $(LEX_C) $(PARSER_C) $(PARSER_H) $(OUTPUT)

# Rebuild everything
rebuild: clean all

# Phony targets to avoid conflicts with file names
.PHONY: all clean rebuild run
