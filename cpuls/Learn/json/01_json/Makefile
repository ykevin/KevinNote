
.PHONY:clean

CC = g++
CFLAGS = -ljsoncpp

EXE = 01_json
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(EXE):$(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)
%.o:%.cpp
	$(CC) -o $@ -c $^ 

clean:
	rm -rf $(OBJS) $(EXE)


