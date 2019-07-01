CXX			= g++
CXXFLAGS = -std=c++14

entity: entity.cpp entity.h entity_test.cpp
	$(CXX) $(CXXFLAGS) entity.cpp entity_test.cpp -o entity
	./entity
