CXX			= g++
CXXFLAGS = -std=c++14

.PHONY : clean

clean:
	rm -f *.exe
	
place: place.h place.cpp place_test.cpp clean
	$(CXX) $(CXXFLAGS) place.cpp place_test.cpp -o place.exe
	./place.exe

entity: place.h place.cpp entity.cpp entity.h entity_test.cpp clean
	$(CXX) $(CXXFLAGS) place.cpp entity.cpp entity_test.cpp -o entity.exe
	./entity.exe

entities: entity.cpp entity.h entities.cpp entities_test.cpp manager.h manager.cpp \
		 place.h place.cpp parser.cpp parser.h clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp manager.cpp place.cpp parser.cpp entities_test.cpp -o entities.exe
	./entities.exe

manager: manager.h manager.cpp entity.cpp entity.h entities.cpp\
		parser.h parser.cpp place.h place.cpp manager_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp place.cpp parser.cpp\
		manager.cpp manager_test.cpp -o manager.exe
	./manager.exe

parser: parser.h parser.cpp clean
	$(CXX) $(CXXFLAGS) parser.cpp parser_test.cpp -o parser.exe
	./parser.exe

all: main.cpp manager.h manager.cpp entity.cpp entity.h entities.cpp\
		parser.h parser.cpp place.h place.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp place.cpp parser.cpp\
	manager.cpp main.cpp -o main.exe
	./main.exe
