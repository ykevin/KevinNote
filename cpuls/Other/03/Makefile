.PHONY:clean

CC = g++
RM = rm
RMFLAGS = -rf
CFLAGS = 
LIBS = 

EXE = test
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS) $(LIBS)
%.o : %.cpp
	$(CC) -o $@ -c $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJS)


