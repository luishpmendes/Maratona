CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf doce

doce: doce.cpp
	$(COMPILER) $(CFLAGS) doce.cpp -o doce
