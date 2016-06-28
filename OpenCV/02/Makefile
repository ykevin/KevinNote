.PHONY:clean

CC = g++
RM = rm
RMFLAGS = -rf
CFLAGS = `pkg-config --cflags --libs opencv`  
LIBS = 

EXE = opencv
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS) $(LIBS)
%.o : %.cpp
	$(CC) -o $@ -c $^ $(CFLAGS) 

clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJS)


