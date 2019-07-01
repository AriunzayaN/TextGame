CXX			= g++
CXXFLAGS = -std=c++14

entity: entity.cpp entity.h entity_test.cpp
  clean
	$(CXX) $(CXXFLAGS) entity.cpp entity_test.cpp -o entity.exe
	./entity.exe
  clean

clean:
	rm *.exe
