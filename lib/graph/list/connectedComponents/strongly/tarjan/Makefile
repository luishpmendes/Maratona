CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf tarjan tarjan2

tarjan: tarjan.cpp
	$(COMPILER) $(CFLAGS) tarjan.cpp -o tarjan

tarjan2: tarjan2.cpp
	$(COMPILER) $(CFLAGS) tarjan2.cpp -o tarjan2
