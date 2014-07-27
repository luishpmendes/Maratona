CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf caixas

caixas: caixas.cpp
	$(COMPILER) $(CFLAGS) caixas.cpp -o caixas
