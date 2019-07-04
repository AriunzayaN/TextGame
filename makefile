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

manager: manager.h manager.cpp entity.cpp entity.h entities.cpp entities.h manager_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp manager.cpp manager_test.cpp -o manager.exe
	./manager.exe
	
item: item.h item.cpp entity.cpp entity.h entities.cpp entities.h manager.h manager.cpp item_test.cpp clean
	$(CXX) $(CXXFLAGS) entity.cpp entities.cpp manager.cpp item.cpp item_test.cpp -o item.exe
	./item.exe	