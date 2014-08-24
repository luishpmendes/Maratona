CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf cardapio

cardapio: cardapio.cpp
	$(COMPILER) $(CFLAGS) cardapio.cpp -o cardapio
