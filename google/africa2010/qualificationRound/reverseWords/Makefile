CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -g -O0 -fno-inline

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf reverseWords

reverseWords: reverseWords.cpp
	$(COMPILER) $(CFLAGS) reverseWords.cpp -o reverseWords
