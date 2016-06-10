.PHONY:clean

CC = g++
RM = rm
RMFLAGS = -rf
CFLAGS = -std=c++11  -pthread
LIBS = 

EXE = test
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS) $(LIBS)
%.o : %.cpp
	$(CC) -o $@ -c $^  $(CFLAGS)

clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJS)


