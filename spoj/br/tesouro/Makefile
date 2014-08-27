CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf tesouro

tesouro: tesouro.cpp
	$(COMPILER) $(CFLAGS) tesouro.cpp -o tesouro
