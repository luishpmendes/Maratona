CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf redotica

redotica: redotica.cpp
	$(COMPILER) $(CFLAGS) redotica.cpp -o redotica
