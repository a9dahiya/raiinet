CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = myprogram
OBJECTS = studio.o asciiart.o blank.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
