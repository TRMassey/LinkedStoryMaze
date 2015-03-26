CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
LDFLAGS = -lboost_date_time

OBJS = assignment.o Maggie.o Joe.o Char.o Room.o Item.o Start.o Sewer.o Dead.o Secret.o House.o JHouse.o Street.o Final.o End.o World.o readStory.o
SRCS = assignment.cpp Maggie.cpp Joe.cpp Char.cpp Room.cpp Item.cpp Start.cpp Sewer.cpp Dead.h Secret.h House.cpp JHouse.cpp Street.cpp Final.cpp End.cpp World.cpp readStory.cpp
HEADERS = Maggie.h Joe.h Room.h Char.h Item.h Start.h Sewer.h Dead.h Secret.h House.h JHouse.h Street.h Final.h End.h World.h

prog: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o prog

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -rf *.o prog

