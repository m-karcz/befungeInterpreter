CC = g++
INCLUDEFILES = $(wildcard include/*.hpp)
CC_FLAGS = -Wall -Wextra -std=c++17
LD_FLAGS =
INCLUDE_DIR = -Iinclude
INCLUDE_GMOCK = -Igtest/googlemock/include/
INCLUDE_GTEST = -Igtest/googletest/include/
MOCKS_DIR = -Itest/mocks/

CPP_FILES = $(wildcard source/*.cpp)
OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

TEST_CPP_FILES = $(wildcard test/*.cpp)
TEST_OBJ_FILES = $(addprefix test_obj/,$(notdir $(TEST_CPP_FILES:.cpp=.o)))

GMOCK = gtest/googlemock/make/gmock-all.o

GTEST = gtest/googlemock/make/gtest-all.o

$(GMOCK):
	make -C gtest/googlemock/make

$(GTEST): $(GMOCK)

.PHONY: clean

run_tests: tests
	./tests 

obj/%.o: source/%.cpp
	$(CC) $< -c -o $@ $(CC_FLAGS) $(INCLUDE_DIR) -g

test_obj/%.o: test/%.cpp $(INCLUDEFILES)
	$(CC) $< -c -o $@ $(CC_FLAGS) $(INCLUDE_DIR) $(INCLUDE_GMOCK) $(INCLUDE_GTEST) $(MOCKS_DIR) -g

sourceLib.a: obj $(OBJ_FILES) $(INCLUDEFILES)
	ar rvs sourceLib.a $(OBJ_FILES)

main: main.cpp $(INCLUDEFILES) sourceLib.a
	$(CC) $(OBJ_FILES) main.cpp sourceLib.a -lpthread -o main -g $(INCLUDE_DIR)

testLib.a: test_obj $(TEST_OBJ_FILES) $(INCLUDE_FILES)
	ar rvs testLib.a $(TEST_OBJ_FILES)

obj:
	mkdir -p obj

test_obj:
	mkdir -p test_obj


tests: sourceLib.a testLib.a $(GMOCK) $(GTEST)
	$(CC)  $(TEST_OBJ_FILES) test_main.cpp sourceLib.a $(GTEST) $(GMOCK) -lpthread -o tests $(LD_FLAGS) $(CC_FLAGS) -g

clean:
	rm obj -rf
	rm test_obj -rf
	rm testLib.a -f
	rm sourceLib.a -f
	rm tests -f
	

