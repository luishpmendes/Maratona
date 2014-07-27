CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf bapostas

bapostas: bapostas.cpp
	$(COMPILER) $(CFLAGS) bapostas.cpp -o bapostas
