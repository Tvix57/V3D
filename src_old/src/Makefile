#################################################
##              Makefile template              ##
#################################################

#     These special targets are called phony     #
.PHONY: all dist clean install uninstall dvi gcov build Qmakefile

#################### Exec file ###################
EXEC := C8_3DViewer_v1_0-0

# Choosing a compiler and setting the main flags #
CC := gcc
STANDART :=-std=c11
CFLAGS := -Wall -Werror -Wextra $(STANDART)
LKFLAGS := -g -fprofile-arcs -ftest-coverage
CPPCHECKFLAG := --enable=all -$(STANDART)
VFLAG := --leak-check=full --show-leak-kinds=all -s
LDFLAGS := -lcheck
TEST_FLAGS = -fprofile-arcs -ftest-coverage

OS := $(shell uname)
ifeq ($(OS), Darwin)
LEAKS := leaks --atExit -- ./$(EXEC)
endif
ifeq ($(OS), Linux)
LDFLAGS += -lm -lpthread -lrt -lsubunit -D_GNU_SOURCE
LEAKS := valgrind $(VFLAG) ./$(EXEC)
endif

##################      Path     #################
P_SRC := ./source
P_INC := ./include
P_OBJ := ./bin
P_LINT := ../materials/linters

################# Resource files #################
CSOURCES=$(wildcard $(P_SRC)*.c)
CHEADERS=$(wildcard $(P_INC)*.h)
COBJ=$(CSOURCES:$(P_SRC)*.c=$(P_OBJ)*.o)

################## Style check ###################
style:
	cp $(P_LINT)/CPPLINT.cfg .
	python3 $(P_LINT)/cpplint.py $(P_INC)/*.h $(P_SRC)/*.c $(P_SRC)/*.cpp
	rm -rf CPPLINT.cfg
	cppcheck $(CPPCHECKFLAG) $(P_INC)/*.h $(P_SRC)/*.c $(P_SRC)/*.cpp

################## Leaks check ###################
leaks: $(EXEC)
	$(LEAKS)

############ Cleaning up unused files ############
clean: uninstall
	rm -rf ./build
	rm -rf *.o a.out *.gcda *.gcno report/ *.info *.cfg

####### Template for creating object files #######
%.o : $(P_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./include

##############  Project archiving   ##############
dist:
	tar -czf $(EXEC).tgz ./*

##############         Tests        ##############
tests: 
	gcc -c $(TEST_FLAGS) -I include source/parser.c
	gcc -I include tests.c parser.o $(LDFLAGS) $(TEST_FLAGS)
	./a.out

##############     gcov report      ##############
gcov_report: tests
	lcov --directory . -c -o tests.info
	genhtml tests.info -o report
	open report/index.html

TEXI_FILES = ./man.texi
INSTALL_PATH = Build
TEXI2DVI = makeinfo --html

OPEN_CMD = open

dvi:
	open readme.html

Qmakefile:
	qmake 3DViewer.pro -o Qmakefile 

install: Qmakefile
	make -f Qmakefile install INSTALL_ROOT=build

uninstall: Qmakefile
	make -f Qmakefile uninstall INSTALL_ROOT=build
	rm -f *.cpp *.h Qmakefile

run:
ifeq ($(OS), Darwin)
	./build/$(EXEC).app/Contents/MacOS/$(EXEC)
endif
ifeq ($(OS), Linux)
	./build/$(EXEC)
endif
