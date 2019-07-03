CXX			= g++
CXXFLAGS = -std=c++14

.PHONY : clean

clean:
	rm -f *.exe

entity: entity.cpp entity.h entity_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entity_test.cpp -o entity.exe
	./entity.exe

entities: entity.cpp entity.h entities.cpp entities.h entities_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp entities_test.cpp -o entities.exe
	./entities.exe
